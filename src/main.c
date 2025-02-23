#include <drunkfly/vm.h>
#include <stdio.h>
#include <stdlib.h>

static int initServer(lua_State* L)
{
    UNUSED(L);
    return 0;
}

static int runServer(lua_State* L)
{
    UNUSED(L);
    return 0;
}

static void printMessage(VMMSGTYPE type, const char* message)
{
    UNUSED(type);
    fprintf(stderr, "%s\n", message);
}

int main()
{
    bool success = vmRun(initServer, runServer, printMessage, NULL);
    return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}
