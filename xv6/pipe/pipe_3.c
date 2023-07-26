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
        /*Replace standard input of child process with read end of the pipe*/       
        dup2(fd[0], 0);
        /* Close the write end of the pipe in child process.It is not used */
        close(fd[1]);
        
        /* Close the read end of the pipe in child process.We have a copy of it in file descriptor 0*/
         close(fd[0]);         read_from_fd(0);         exit(0);
     } else {
         const char* data = "Data";          
         /*Replace standard output of parent process with write end of the pipe*/
         dup2(fd[1], 1);
            
         /* Close the read end of the pipe in parent process.It is not used */
          close(fd[0]);
            
         /* Close the write end of the pipe in child process.We have a copy of it in file descriptor 1*/
          close(fd[1]);               write(1, data, strlen(data));
            
          /* After writing all data, close the write end */
          close(1);           /* Wait for the child to finish */
           waitpid(pid, 0, 0);
           exit(0);                        
      }
}
