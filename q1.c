#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    // --- PRE-FORK SETUP ZONE ---
    int x = 100;

    printf("Starting main process (PID: %d)\n", (int)getpid());

    // --- THE SPLIT ---
    pid_t rc = fork();

    if (rc < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // --- CHILD PROCESS ZONE ---
        printf("\n[CHILD] Waking up (PID: %d)\n", (int)getpid());
	printf("Child x before modding %d",x);
	x=50;
	printf("Child X after modding %d",x);
        exit(0);
    }
    else {
        // --- PARENT PROCESS ZONE ---
        printf("\n[PARENT] Continuing (PID: %d), Child is (PID: %d)\n", (int)getpid(), rc);
	printf("Parent x before modding %d", x);
	x=200;
	printf("parent x after modding %d", x);
    }


    return 0;
}

