#include "MainThread.h"
#include "MainForm.h"

#ifdef DUILIB_BUILD_FOR_WIN
    #include "resource.h"
#endif

MainThread::MainThread() :
    FrameworkThread(_T("MainThread"), ui::kThreadUI)
{
}

MainThread::~MainThread()
{
}

void MainThread::OnInit()
{
    fprintf(stderr, "[basic] OnInit START\n");
    //初始化全局资源
    constexpr ui::ResourceType resType = ui::ResourceType::kLocalFiles;
    if (resType == ui::ResourceType::kLocalFiles) {
        //使用本地文件夹作为资源
        ui::FilePath resourcePath = ui::FilePathUtil::GetCurrentModuleDirectory();
        resourcePath += _T("resources\\");
        ui::GlobalManager::Instance().Startup(ui::LocalFilesResParam(resourcePath));
        fprintf(stderr, "[basic] GlobalManager::Startup done\n");
    }
    else if (resType == ui::ResourceType::kZipFile) {
        //使用本地zip压缩包作为资源（压缩包位于exe相同目录）    
        ui::ZipFileResParam resParam;
        resParam.resourcePath = _T("resources\\");
        resParam.zipFilePath = ui::FilePathUtil::GetCurrentModuleDirectory();
        resParam.zipFilePath += _T("resources.zip");
        resParam.zipPassword = _T("");
        ui::GlobalManager::Instance().Startup(resParam);
    }
#ifdef DUILIB_BUILD_FOR_WIN
    else if (resType == ui::ResourceType::kResZipFile) {
        //使用exe资源文件中的zip压缩包
        ui::ResZipFileResParam resParam;
        resParam.resourcePath = _T("resources\\");
        resParam.hResModule = nullptr;
        resParam.resourceName = MAKEINTRESOURCE(IDR_THEME);
        resParam.resourceType = _T("THEME");
        resParam.zipPassword = _T("");
        ui::GlobalManager::Instance().Startup(resParam);
    }
#endif
    else {
        fprintf(stderr, "[basic] OnInit: invalid resType, returning\n");
        return;
    }

    // 创建一个默认带有阴影的居中窗口
    fprintf(stderr, "[basic] Creating MainForm...\n");
    MainForm* window = new MainForm();
    fprintf(stderr, "[basic] MainForm created, calling CreateWnd...\n");
    window->CreateWnd(nullptr, ui::WindowCreateParam(_T("basic"), true));
    window->PostQuitMsgWhenClosed(true);
    fprintf(stderr, "[basic] CreateWnd returned, showing window...\n");
    window->ShowWindow(ui::kSW_SHOW_NORMAL);
    fprintf(stderr, "[basic] ShowWindow done\n");
    // window->ShowWindow(ui::kSW_SHOW_MAXIMIZED);
}

void MainThread::OnCleanup()
{
    ui::GlobalManager::Instance().Shutdown();
}
