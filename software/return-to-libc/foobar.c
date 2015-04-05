#include <stdio.h>

void foo()
{
    system("/bin/sh");
}
int main()
{
    foo();
    return 0;
}
