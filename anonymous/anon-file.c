#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/types.h>

/**
 * If one wanted to hide the anonymous file, is there a way to preserve the file in RAM
 * without mapping it such that it is still useful without being easy to detect?
 */
int main(void)
{
    const char* name = "ANON_FILE";
    char* text = "This is an anonymous file.";
    int anon_fd = memfd_create(name, 0);
    char received[100];

    if (anon_fd == -1)
    {
        perror("memfd_create()");
        return errno;
    }

    if (write(anon_fd, text, strlen(text)) == -1)
    {
        perror("read()");
        return errno;
    }

    off_t return_to_start = lseek(anon_fd, 0, 0);
    if (return_to_start == -1)
    {
        perror("lseek()");
        return errno;
    }

    if (read(anon_fd, received, sizeof received) == -1)
    {
        perror("read()");
        return errno;
    }
    printf("%s\n", received);

    return EXIT_SUCCESS;
}
