#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    sendto(sockfd, "Hello UDP Server", 17, 0,
           (struct sockaddr*)&server, sizeof(server));

    return 0;
}
