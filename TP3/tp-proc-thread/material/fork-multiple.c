#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t rv1, rv2;
  printf("[%8d/%8d] printf-1 Executing main process\n", (int)getpid(),
         (int)getppid());

  rv1 = fork();

  printf("[%8d/%8d] printf-2  First  fork(), returned value : %8d\n",
         (int)getpid(), (int)getppid(), rv1);

  rv2 = fork();

  if (rv1 == 0 && rv2 == 0)
  {
       sleep(1);
  }
  
   
  printf("[%8d/%8d] printf-3  Second fork(), returned value : %8d\n",
         (int)getpid(), (int)getppid(), rv2);

  return 0;
}
