/** xml_to_code - convert XML layout files to pure C++ initialization code
 *  Usage: xml_to_code <output.cpp> <function_name> <input_xml_files...>
 *
 *  Parses XML at build time (via pugixml linked into this tool) and generates
 *  C++ code that creates the same UI at runtime via direct API calls -
 *  zero XML parsing needed at runtime.
 *
 *  The generated function signature is:
 *    void <function_name>(ui::Window* pWindow)
 *
 *  Build: clang++ -std=c++17 -O2 xml_to_code.cpp -lstdc++ -o xml_to_code
 *         (pugixml is header-only, include path must point to duilib/third_party/xml)
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <sys/stat.h>

// ---- Minimal pugixml (header-only, included from duilib) ----
#include "pugixml.hpp"

static std::string attr(const pugi::xml_node& node, const char* name,
                         const std::string& def = "") {
    const char* v = node.attribute(name).value();
    return v[0] ? v : def;
}

static std::string escapeCStr(const std::string& s) {
    std::string out;
    for (char ch : s) {
        switch (ch) {
        case '\\': out += "\\\\"; break;
        case '"':  out += "\\\""; break;
        case '\n': out += "\\n";  break;
        case '\r': break;
        case '\t': out += "\\t";  break;
        default:   out += ch;     break;
        }
    }
    return out;
}

static std::string nodeName(const pugi::xml_node& node) {
    return node.name();
}

// Map XML class names to C++ control class names
static std::string cppClass(const std::string& xmlClass) {
    if (xmlClass == "Window" || xmlClass == "Global") return "";
    if (xmlClass == "Box")              return "ui::Box";
    if (xmlClass == "VBox")             return "ui::VBox";
    if (xmlClass == "HBox")             return "ui::HBox";
    if (xmlClass == "Control")          return "ui::Control";
    if (xmlClass == "Label")            return "ui::Label";
    if (xmlClass == "Button")           return "ui::Button";
    if (xmlClass == "RichEdit")         return "ui::RichEdit";
    if (xmlClass == "CheckBox")         return "ui::CheckBox";
    if (xmlClass == "RadioBox")         return "ui::RadioBox";
    if (xmlClass == "ComboBox")         return "ui::ComboBox";
    if (xmlClass == "Progress")         return "ui::Progress";
    if (xmlClass == "Slider")           return "ui::Slider";
    if (xmlClass == "ScrollBar")        return "ui::ScrollBar";
    if (xmlClass == "TabBox")           return "ui::TabBox";
    if (xmlClass == "ListBox")          return "ui::ListBox";
    if (xmlClass == "ListCtrl")         return "ui::ListCtrl";
    if (xmlClass == "TreeView")         return "ui::TreeView";
    if (xmlClass == "VirtualListBox")   return "ui::VirtualListBox";
    // Virtual*ListBox variants need Layout* in constructor
    if (xmlClass == "VirtualVTileListBox") return "virtual_vtile";
    if (xmlClass == "VirtualHTileListBox") return "virtual_htile";
    if (xmlClass == "VirtualVListBox")  return "virtual_v";
    if (xmlClass == "VirtualHListBox")  return "virtual_h";
    if (xmlClass == "RichEdit")         return "ui::RichEdit";
    if (xmlClass == "Option")           return "ui::Option";
    if (xmlClass == "Event")            return ""; // skip event bindings
    if (xmlClass == "OptionBox")        return "ui::OptionBox";
    if (xmlClass == "Edit")             return "ui::Edit";
    if (xmlClass == "WebView2")         return "ui::WebView2";
    return ""; // Unknown - skip
}

// Track which classes are used by generated controls
static std::set<std::string> s_usedClasses;
static void trackClass(const std::string& cls) { if (!cls.empty()) s_usedClasses.insert(cls); }

static void genAttrs(std::ostream& out, const std::string& var,
                     const pugi::xml_node& node) {
    for (const auto& a : node.attributes()) {
        std::string name = a.name();
        std::string value = a.value();
        if (name.empty() || value.empty()) continue;
        if (name == "on_click" || name == "on_select" || name == "on_change") continue;
        if (name == "class") trackClass(value);  // Track class usage for image embedding
        out << "        " << var << "->SetAttribute(_T(\"" << escapeCStr(name)
            << "\"), _T(\"" << escapeCStr(value) << "\"));\n";
    }
}

static void genNode(std::ostream& out, const pugi::xml_node& node,
                    const std::string& parentVar, int depth) {
    std::string tag = nodeName(node);
    if (tag.empty()) return;

    std::string cls = cppClass(tag);
    if (cls.empty()) {
        // Container nodes with no direct C++ class (e.g., <Global>, <Window>)
        for (auto child : node.children()) {
            if (child.type() == pugi::node_element) {
                genNode(out, child, parentVar, depth);
            }
        }
        return;
    }

    static int varId = 0;
    std::string var = "p" + std::to_string(varId++);

    // Handle Virtual*ListBox variants (need Layout* in constructor)
    if (cls == "virtual_vtile") {
        out << "    ui::VirtualListBox* " << var
            << " = new ui::VirtualListBox(pWindow, new ui::VirtualVTileLayout);\n";
    } else if (cls == "virtual_htile") {
        out << "    ui::VirtualListBox* " << var
            << " = new ui::VirtualListBox(pWindow, new ui::VirtualHTileLayout);\n";
    } else if (cls == "virtual_v") {
        out << "    ui::VirtualListBox* " << var
            << " = new ui::VirtualListBox(pWindow, new ui::VirtualVLayout);\n";
    } else if (cls == "virtual_h") {
        out << "    ui::VirtualListBox* " << var
            << " = new ui::VirtualListBox(pWindow, new ui::VirtualHLayout);\n";
    } else {
        out << "    " << cls << "* " << var << " = new " << cls << "(pWindow);\n";
    }
    genAttrs(out, var, node);

    // Note: event handlers (AttachClick, etc.) must be wired manually
    // in the calling code after InitXxxUI(). See genui/genlist MainForm for example.

    // Check for children
    bool hasChildren = false;
    for (auto c : node.children()) {
        if (c.type() == pugi::node_element && !cppClass(nodeName(c)).empty()) {
            hasChildren = true; break;
        }
    }

    // Process children
    for (auto child : node.children()) {
        if (child.type() == pugi::node_element) {
            genNode(out, child, var, depth + 1);
        }
    }

    // Add to parent
    if (!parentVar.empty()) {
        out << "        " << parentVar << "->AddItem(" << var << ");\n";
    }
    out << "\n";
}

static std::string stem(const std::string& path) {
    auto pos = path.rfind('/');
    std::string name = (pos != std::string::npos) ? path.substr(pos + 1) : path;
    auto dot = name.rfind('.');
    if (dot != std::string::npos) name = name.substr(0, dot);
    // Capitalize first letter: main -> Main, item -> Item
    if (!name.empty()) name[0] = toupper(name[0]);
    return name;
}

// ---- Base64 encode / image embedding support ----
static const char kBase64Tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static std::string readBinaryFile(const std::string& path, bool& ok) {
    std::ifstream f(path, std::ios::binary);
    ok = f.good();
    if (!ok) return "";
    return std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
}

static std::string base64Encode(const std::string& data) {
    std::string out;
    out.reserve((data.size() + 2) / 3 * 4);
    for (size_t i = 0; i < data.size(); i += 3) {
        unsigned n = (unsigned char)data[i] << 16;
        if (i + 1 < data.size()) n |= (unsigned char)data[i + 1] << 8;
        if (i + 2 < data.size()) n |= (unsigned char)data[i + 2];
        out += kBase64Tbl[(n >> 18) & 63];
        out += kBase64Tbl[(n >> 12) & 63];
        out += (i + 1 < data.size()) ? kBase64Tbl[(n >> 6) & 63] : '=';
        out += (i + 2 < data.size()) ? kBase64Tbl[n & 63] : '=';
    }
    return out;
}

static std::string imageVarName(const std::string& path) {
    std::string n;
    auto p = path.rfind('/'); if (p != std::string::npos) n = path.substr(p+1);
    else n = path;
    for (auto& c : n) if (c == '.' || c == '-') c = '_';
    return n;
}

// Collect class→image mapping from global.xml
static void parseGlobalClasses(const std::string& globalPath,
    std::map<std::string, std::string>& classImages,
    std::map<std::string, std::string>& classAttrs) {
    pugi::xml_document doc;
    if (!doc.load_file(globalPath.c_str())) return;
    for (auto node : doc.document_element().children()) {
        if (std::string(node.name()) != "Class") continue;
        std::string name = attr(node, "name");
        if (name.empty()) continue;
        std::string img = attr(node, "normal_image");
        if (!img.empty()) {
            // Extract file='xxx' from image string
            auto fp = img.find("file='");
            if (fp != std::string::npos) {
                auto fe = img.find('\'', fp + 6);
                if (fe != std::string::npos) {
                    classImages[name] = img.substr(fp + 6, fe - fp - 6);
                }
            }
        }
        // Collect all attributes for AddClass
        std::string attrs;
        for (auto& a : node.attributes()) {
            std::string an = a.name();
            if (an == "name") continue;
            attrs += " " + an + "=\"" + a.value() + "\"";
        }
        if (!attrs.empty()) classAttrs[name] = attrs;
    }
}

int main(int argc, char** argv) {
    std::string outputPath, baseName, globalPath;
    std::vector<std::string> xmlFiles;
    bool autoEmbed = false;

    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "-g" && i + 1 < argc) { globalPath = argv[++i]; autoEmbed = true; }
        else if (outputPath.empty()) outputPath = a;
        else if (baseName.empty()) baseName = a;
        else xmlFiles.push_back(a);
    }

    if (outputPath.empty() || baseName.empty() || xmlFiles.empty()) {
        std::cerr << "Usage: xml_to_code [-g global.xml] <output.inc> <base_func_name> <xml1> [xml2...]"
                  << std::endl;
        std::cerr << "  -g global.xml : auto-embed images referenced by classes" << std::endl;
        return 1;
    }

    // Parse global.xml for class→image mappings
    std::map<std::string, std::string> classImages, classAttrs;
    if (!globalPath.empty()) parseGlobalClasses(globalPath, classImages, classAttrs);

    std::ofstream out(outputPath);
    if (!out) { std::cerr << "Cannot open output: " << outputPath << std::endl; return 1; }

    out << "///////////////////////////////////////////////////////////////////////////\n";
    out << "//   AUTO-GENERATED by xml_to_code - DO NOT EDIT BY HAND\n";
    out << "//\n";
    out << "//   Source XML files:\n";
    for (const auto& x : xmlFiles) out << "//     " << x << "\n";
    out << "//\n";
    out << "//   Each XML file produces one function:\n";
    out << "//     " << baseName << " + FileStem\n";
    for (const auto& x : xmlFiles) {
        out << "//     " << baseName << stem(x) << "(ui::Window* pWindow)\n";
    }
    out << "//\n";
    out << "//   Functions ending in 'Window' call AttachBox() automatically.\n";
    out << "//   Other functions (templates, items) do NOT call AttachBox - the\n";
    out << "//   caller must add the root control to a parent container.\n";
    out << "///////////////////////////////////////////////////////////////////////////\n\n";
    out << "#include \"duilib/duilib.h\"\n\n";

    bool hasWindowFunc = false;
    for (const auto& xmlFile : xmlFiles) {
        pugi::xml_document doc;
        if (!doc.load_file(xmlFile.c_str())) {
            std::cerr << "Failed to parse: " << xmlFile << std::endl;
            return 1;
        }

        pugi::xml_node root = doc.document_element();
        if (!root) continue;

        std::string funcName = baseName + stem(xmlFile);
        std::string rootTag = nodeName(root);

        out << "void " << funcName << "(ui::Window* pWindow) {\n";

        if (rootTag == "Window" || rootTag == "Global") {
            for (auto child : root.children()) {
                if (child.type() == pugi::node_element) {
                    genNode(out, child, "", 1);
                }
            }
        } else {
            genNode(out, root, "", 1);
        }

        // AttachBox for Window-rooted files; skip for templates (ListBoxItem etc.)
        bool isTemplate = false;
        for (auto child : root.children()) {
            if (child.type() == pugi::node_element) {
                std::string tag = nodeName(child);
                if (tag == "ListBoxItem" || tag == "BoxItem" || tag == "TreeNode")
                    isTemplate = true;
                break;
            }
        }
        if (rootTag == "Window" && !isTemplate) {
            out << "    pWindow->AttachBox(p0);\n";
        }
        out << "}\n\n";
    }

    // ---- Auto-embed images referenced by used classes ----
    if (autoEmbed && !s_usedClasses.empty()) {
        out << "// ============================================================\n";
        out << "// Auto-embedded images (only those referenced by generated UI)\n";
        out << "// ============================================================\n\n";
        out << "#include <sys/mman.h>\n#include <unistd.h>\n";
        out << "#include <cstring>\n#include <cstdio>\n\n";

        // Base64 decoder
        out << "static const signed char kDecTbl[256] = {\n";
        for (int i = 0; i < 256; i++) {
            if (i % 16 == 0) out << "    ";
            int v = -1;
            if (i >= 'A' && i <= 'Z') v = i - 'A';
            else if (i >= 'a' && i <= 'z') v = i - 'a' + 26;
            else if (i >= '0' && i <= '9') v = i - '0' + 52;
            else if (i == '+') v = 62;
            else if (i == '/') v = 63;
            out << v << (i < 255 ? "," : "");
            if (i % 16 == 15) out << "\n";
        }
        out << "};\n\n";
        out << "inline DString ImgToMemFd(const char* b64, const char* tag) {\n";
        out << "    int fd=memfd_create(tag,MFD_CLOEXEC); if(fd<0)return _T(\"\");\n";
        out << "    unsigned char buf[8192];\n";
        out << "    const unsigned char* s=(const unsigned char*)b64;\n";
        out << "    size_t di=0;int val=0,vb=-8;\n";
        out << "    while(*s&&di<sizeof(buf)){\n";
        out << "        int c=kDecTbl[*s++];if(c==-1)continue;\n";
        out << "        val=(val<<6)|c;vb+=6;\n";
        out << "        if(vb>=0){buf[di++]=(unsigned char)((val>>vb)&0xFF);vb-=8;}\n";
        out << "    }\n";
        out << "    if(write(fd,buf,di)!=(ssize_t)di){close(fd);return _T(\"\");}\n";
        out << "    char tmp[32];snprintf(tmp,sizeof(tmp),\"%d\",fd);\n";
        out << "    DString p=_T(\"/proc/self/fd/\");\n";
        out << "    for(char* x=tmp;*x;x++)p+=(DString::value_type)(unsigned char)*x;\n";
        out << "    return p;\n}\n\n";

        // Embed each used image
        std::set<std::string> embeddedImages;
        for (const auto& cls : s_usedClasses) {
            auto it = classImages.find(cls);
            if (it == classImages.end()) continue;
            std::string imgPath = it->second;
            if (embeddedImages.count(imgPath)) continue;
            embeddedImages.insert(imgPath);

            // Try to find the image file relative to the global.xml directory
            std::string globalDir = globalPath.substr(0, globalPath.rfind('/'));
            std::string fullPath = globalDir + "/" + imgPath;
            bool ok = false;
            std::string data = readBinaryFile(fullPath, ok);
            if (!ok) {
                // Try alternative paths
                fullPath = globalDir + "/../" + imgPath;
                data = readBinaryFile(fullPath, ok);
            }
            if (!ok) continue;

            std::string var = "kImg_" + imageVarName(imgPath);
            out << "// " << imgPath << " (" << data.size() << " bytes)\n";
            out << "static const char " << var << "[] =\n";
            std::string b64 = base64Encode(data);
            for (size_t j = 0; j < b64.size(); j += 72) {
                out << "    \"" << b64.substr(j, 72) << "\""
                    << (j + 72 >= b64.size() ? ";\n" : "\n");
            }
            out << "inline DString GetPath_" << imageVarName(imgPath) << "() {\n";
            out << "    static DString p;\n";
            out << "    if(p.empty()) p=ImgToMemFd(" << var << ",\"" << imageVarName(imgPath) << "\");\n";
            out << "    return p;\n}\n\n";
        }

        // Generate class registrations with embedded paths
        if (!embeddedImages.empty()) {
            out << "// Class registrations using embedded images\n";
            out << "inline void RegisterEmbeddedClasses(ui::Window* pWindow) {\n";
            out << "    DString attrs;\n";
            for (const auto& cls : s_usedClasses) {
                auto it = classImages.find(cls);
                auto ai = classAttrs.find(cls);
                if (it == classImages.end() || ai == classAttrs.end()) continue;
                std::string imgVar = imageVarName(it->second);
                // Build the full attribute string using a local DString
                // Replace file='...' with file='[embedded]'
                std::string origAttr = ai->second;
                auto fp = origAttr.find("file='");
                if (fp != std::string::npos) {
                    auto fe = origAttr.find('\'', fp + 6);
                    if (fe != std::string::npos) {
                        std::string before = origAttr.substr(0, fp + 6);
                        std::string after = origAttr.substr(fe);
                        out << "    attrs = _T(\"" << escapeCStr(before) << "\");\n";
                        out << "    attrs += GetPath_" << imgVar << "();\n";
                        out << "    attrs += _T(\"" << escapeCStr(after) << "\");\n";
                        out << "    pWindow->AddClass(_T(\"" << escapeCStr(cls) << "\"), attrs);\n";
                        continue;
                    }
                }
                out << "    pWindow->AddClass(_T(\"" << escapeCStr(cls) << "\"), _T(\""
                    << escapeCStr(origAttr) << "\"));\n";
            }
            out << "}\n\n";
        }
    }

    std::cout << "Generated " << outputPath;
    if (autoEmbed) std::cout << " with " << s_usedClasses.size() << " class(es)";
    std::cout << " from " << xmlFiles.size() << " XML file(s)" << std::endl;
    return 0;
}
