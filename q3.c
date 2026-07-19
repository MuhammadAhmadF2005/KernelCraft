#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
    // --- THE SPLIT ---//
    pid_t rc = fork();
    if (rc < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // --- CHILD PROCESS ZONE ---
        printf("hello \n");
        exit(0); // Always exit the child cleanly so it doesn't run parent code
    }
    else {
        // --- PARENT PROCESS ZONE ---
	sleep(1);
        printf("goodbye \n");
    }
    return 0;
}
