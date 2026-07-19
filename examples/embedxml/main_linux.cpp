#if defined(linux) || defined(__linux) || defined(__linux__)

#include "duilib/duilib_config_linux.h"
#include "MainThread.h"

int main(int argc, char** argv)
{
    MainThread thread;
    thread.RunMessageLoop();
    return 0;
}

#endif
