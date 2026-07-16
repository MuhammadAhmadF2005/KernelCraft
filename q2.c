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
	int fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
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
	write(fd, "child writing\n", 14);

        exit(0); // Always exit the child cleanly so it doesn't run parent code
    } 
    else {
        // --- PARENT PROCESS ZONE ---
        printf("\n[PARENT] Continuing (PID: %d), Child is (PID: %d)\n", (int)getpid(), rc);
	write(fd, "parent writing\n", 15);

    }
    return 0;
}
	
