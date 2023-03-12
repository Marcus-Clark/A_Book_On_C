/* pipe4.c */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
  int pipefds[2];
    pid_t pid;
  if(pipe(pipefds) == -1){
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  pid = fork();
  if(pid == -1){
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if(pid == 0){
  //replace stdout with the write end of the pipe
    dup2(pipefds[1],STDOUT_FILENO);  
  //close read to pipe, in child    
    close(pipefds[0]);               
    execlp(argv[1],argv[1],NULL);
    exit(EXIT_SUCCESS);
  }else{
  //Replace stdin with the read end of the pipe
        dup2(pipefds[0],STDIN_FILENO);  
  //close write to pipe, in parent
        close(pipefds[1]);               
        execlp(argv[2],argv[2],NULL);
        exit(EXIT_SUCCESS);
    }   
}
