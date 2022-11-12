#include <stdio.h>

#ifdef __linux__
extern int prog();
#else
extern int _prog();
#endif

int main(int argc, char const *argv[])
{
#ifdef __linux__
    printf("%d\n", prog());
#else
    printf("%d\n", _prog());
#endif
    return 0;
}