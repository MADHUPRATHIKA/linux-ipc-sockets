#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Structure for message queue
struct msgbuf
{
    long mtype;
    char mtext[100];
};

int main()
{
    struct msgbuf message;

    // Access existing message queue
    int msgid = msgget(1234, 0666 | IPC_CREAT);

    // Receive message
    msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);

    // Display message
    printf("Received: %s\n", message.mtext);

    return 0;
}
