#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Server received: %s\n", buffer);

    close(fd);

    return 0;
}
