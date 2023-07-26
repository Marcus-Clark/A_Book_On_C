#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
    
const char* process = NULL;
void read_from_fd(int fd) {
    char c;
    while(read(fd, &c, 1) != 0) {
        printf("Process [%s] Read Reading from descriptor %d character %c\n", process, fd, c);
        sleep(1);
    }
}
int main(int argc, char** argv) {
    process = "PARENT"; 
    int read_fd = open("/tmp/file1", O_RDONLY);
    char c;
    read(read_fd, &c, 1);
    printf("Process [%s] Reading from descriptor %d character %c\n", process, read_fd, c);
    printf("Forking a new child process \n");
    int pid = fork();
    if (pid == -1) {
       fprintf(stderr, "Erroring creating child process. %s", strerror(errno));
       exit(-1);
    } else if (pid == 0) {
       process = "CHILD";
       read_from_fd(read_fd);
       exit(0);
    } else {
       read_from_fd(read_fd);
       waitpid(pid, 0, 0);
       exit(0);                                
    } 
}
