#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Structure for message queue
struct msgbuf
{
    long mtype;
    char mtext[100];
};

int main()
{
    struct msgbuf message;

    // Create message queue
    int msgid = msgget(1234, 0666 | IPC_CREAT);

    // Set message type
    message.mtype = 1;

    // Copy message
    strcpy(message.mtext, "Hello Queue");

    // Send message
    msgsnd(msgid, &message, sizeof(message.mtext), 0);

    printf("Message Sent Successfully\n");

    return 0;
}
