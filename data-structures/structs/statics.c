#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>

static struct test
{
    int a;
    char* b;
};

static struct test test2 =
{
    .a = 0,
    .b = "Yay"
};

int main(void)
{
    struct test t;
    printf("%d", t.a);
    printf("%s", t.b);

    printf("%d", test2.a);
    printf("%s", test2.b);
    return EXIT_SUCCESS;
}
