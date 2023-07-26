#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
    
const char* process = NULL;
void read_from_fd(int fd) {
    char c;
    printf ("Process [%s] Reading from descriptor %d \n", process, fd);
    while(read(fd, &c, 1) != 0) {
          printf("%c", c);
    }
    printf("\n");
}
int main(int argc, char** argv) {
    process = "PARENT";
    int fd[2];
    if (pipe(fd) != 0) {
          printf ("Error creating pipe. %s", strerror(errno));
          exit(errno);
     }
     
     int pid = fork();
     if (pid == -1) {
         printf ("Error creating pipe. %s", strerror(errno));
         exit(errno);
      } else if (pid == 0) {
         //child        
         process = "CHILD";
         /* Close the write end of the pipe in child process.It is not used */
          close(fd[1]);  
          read_from_fd(fd[0]);
          exit(0);
        } else {
         /* Close the read end of the pipe in parent process.It is not used */
          close(fd[0]); 
          const char* data = "Data";
          printf("Process [%s] Writing data to pipe\n", process);        
          write(fd[1], data, strlen(data));
          /* After writing all data, close the write end */
          close(fd[1]);
          /* Wait for the child to finish */
          waitpid(pid, 0, 0);
          exit(0);                        
     }
}
