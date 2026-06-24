#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("myfifo", O_WRONLY);

    write(fd, "Hello from Client", 18);

    close(fd);

    return 0;
}
