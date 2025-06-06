#ifndef EXAMPLES_DRAG_FROM_H_
#define EXAMPLES_DRAG_FROM_H_

// duilib
#include "duilib/duilib.h"

#if defined (DUILIB_BUILD_FOR_WIN) && !defined (DUILIB_BUILD_FOR_SDL)

/** @class DragForm
  * @brief 模仿系统拖拽功能的半透明窗体，因为使用了低级键盘钩子所以一些安全软件会拦截
  * @copyright (c) 2016, NetEase Inc. All rights reserved
  * @author Redrain
  * @date 2019/3/20
  */
class HBitmapControl;
class DragForm : public ui::WindowImplBase
{
public:
    /**
    * 低级键盘钩子的回调函数
    * @param[in] nCode 操作码
    * @param[in] wParam 附加参数
    * @param[in] lParam 附加参数
    * @return LRESULT    操作结果
    */
    static LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam);

    /**
    * 创建自定义拖拽窗口
    * @param[in] bitmap 拖拽效果位图
    * @param[in] pt_offset 拖拽图像相对于鼠标的偏移
    * @return void    无返回值
    */
    static void CreateCustomDragImage(HBITMAP bitmap, POINT pt_offset);

    /**
    * 关闭自定义拖拽窗口
    * @return void    无返回值
    */
    static void CloseCustomDragImage();

public:    
    // 覆盖虚函数
    virtual DString GetSkinFolder() override;
    virtual DString GetSkinFile() override;

    /**
    * 根据控件类名创建自定义控件
    * @param[in] pstrClass 控件类名
    * @return Control* 创建的控件的指针
    */
    virtual ui::Control* CreateControl(const DString& pstrClass) override;

    /** 当窗口创建完成以后调用此函数，供子类中做一些初始化的工作
    */
    virtual void OnInitWindow() override;

private:
    DragForm();
    virtual ~DragForm() override = default;

    /**
    * 创建一个拖拽效果的窗口
    * @param[in] bitmap 拖拽效果位图对象
    * @param[in] pt_offset 拖拽图像相对于鼠标的偏移
    * @return void    无返回值
    */
    static DragForm* CreateDragForm(HBITMAP bitmap, POINT pt_offset);

    /**
    * 设置拖拽效果的位图
    * @param[in] bitmap 拖拽效果位图对象
    * @return void    无返回值
    */
    void SetDragImage(HBITMAP bitmap);

private:
    static HHOOK s_mouse_hook;
    static DragForm* s_drag_form;
    static POINT s_point_offset;
    HBitmapControl* m_pBitmapControl;
};

#endif //(DUILIB_BUILD_FOR_WIN) && !defined (DUILIB_BUILD_FOR_SDL)

#endif //EXAMPLES_DRAG_FROM_H_
