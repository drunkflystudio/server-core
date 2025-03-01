#include <drunkfly/vm.h>
#include <stdio.h>
#include <stdlib.h>

/* FIXME */
struct Application
{
    void (*dispatch)(lua_State* L, const char* selector, int nargs, ...);
};
extern struct Application* Application;

static int initServer(lua_State* L)
{
    UNUSED(L);
    return 0;
}

static int runServer(lua_State* L)
{
    Application->dispatch(L, "main", 0);
    return 0;
}

static void printMessage(VMMSGTYPE type, const char* message)
{
    UNUSED(type);
    fprintf(stderr, "%s\n", message);
}

int main(void)
{
    bool success = vmRun(initServer, runServer, printMessage, NULL);
    return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}
