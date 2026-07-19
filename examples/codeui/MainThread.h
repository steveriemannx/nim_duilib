#ifndef EXAMPLES_CODEUI_MAIN_THREAD_H_
#define EXAMPLES_CODEUI_MAIN_THREAD_H_

#include "duilib/duilib.h"

class MainThread : public ui::FrameworkThread
{
public:
    MainThread();
    virtual ~MainThread() override;

private:
    virtual void OnInit() override;
    virtual void OnCleanup() override;
};

#endif
