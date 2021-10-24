#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <sys/wait.h>
#include <fstream>
int main()
{
    int x, pid1, pid2, st;
    x=1;
    printf("Double process, x=%d\n",x);
    pid1=fork();  //создаем дочерний процесс от P1
    if(pid1 == 0)
    {
         pid2 = fork(); //создаем дочерний процесс от P2
         if(pid2 == 0) {
             x=x+2;
             printf("New_2, x=%d, pid1=%d, pid2=%d\n",x, getppid(), getpid());
             sleep(5);
         }
         else if (pid2 < 0) printf("Fork error\n"); 
            else{
                x= x+1;
         printf("New_1, x=%d,parent=%d, pid1=%d\n",x, getppid(), getpid());
         sleep(5);
            }
    }
    else 
    { printf("Old, parent=%d, pid1=%d, pid2=%d, x=%d\n",getppid(),pid1,pid2,x);
       sleep(5);
       wait(&st);
    if (pid1 < 0) 
    {
        printf("Fork error");
        return -1;
    }
    }
   wait(&st);
    return 0;
}