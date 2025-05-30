#ifndef EXAMPLES_LISTBOX_FORM_H_
#define EXAMPLES_LISTBOX_FORM_H_

// duilib
#include "duilib/duilib.h"

class ListBoxForm : public ui::WindowImplBase
{
public:
    ListBoxForm();
    virtual ~ListBoxForm() override;

    /** 资源相关接口
     * GetSkinFolder 接口设置你要绘制的窗口皮肤资源路径
     * GetSkinFile 接口设置你要绘制的窗口的 xml 描述文件
     */
    virtual DString GetSkinFolder() override;
    virtual DString GetSkinFile() override;

    /** 当窗口创建完成以后调用此函数，供子类中做一些初始化的工作
    */
    virtual void OnInitWindow() override;

private:
    bool OnSelected(const ui::EventArgs& args);

private:
    ui::ListBox* m_pListBox;
};

#endif //EXAMPLES_LISTBOX_FORM_H_
