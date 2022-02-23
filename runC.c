#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){
char *exeName,*Path,dotSlash[3]="./";
int i=0,mis1=1,mis2=0,pid; //mis1 - running compiler first, mis2 - running the programs

//initializing
exeName=(char*)malloc(sizeof(char)*(strlen(argv[1])));
Path=(char*)malloc(sizeof(char)*(3+strlen(argv[1])));

if (argc!=2||(argv[1][strlen(argv[1])-1]!='c')) 
       {printf("Wrong input"); return;}

else
       { 

        //cut off ".c" so the exe will be named without it
        strcpy(exeName,argv[1]);
        exeName[strlen (exeName) - 2] = '\0';

pid=fork();
if(pid==0 && mis1==1){
                 execl("/bin/gcc","gcc",argv[1],"-o",exeName,0);
                 printf("Execute program failed");
                 return(-1);
        }

//wait for first mission to be complete.
wait();
mis1=0;
mis2=1; // now mission 2 - exe the program.
        strcpy(Path,dotSlash);
        strcat(Path,exeName);
        
pid=fork();
if (pid==0&& mis2==1){
        execl(Path,exeName,0);
        printf("Execute program failed");
                 return(-1);
            }

//wait for mis2 to be complete then delete the exe file.
wait();
execl("/bin/rm","rm",exeName,0);

}
         
            


}

