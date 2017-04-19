#include "module.h"
#include "bootpack.h"

static int init_hello(void)
{
    hrb_print("init_hello is called.\n");
    return 0;
}

static void exit_hello(void)
{
    hrb_print("exit_hello is called. bye...\n");
}

struct module this_module
__attribute__((section(".this_module"))) = {
    .init = init_hello,
    .exit = exit_hello
};
