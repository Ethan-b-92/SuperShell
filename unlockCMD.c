#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

/* The command checks text file in "locked" folder,  the pass inside.*/


int main(int argc,char* argv[]){
int pid,passFile,rbytes,wbytes,found=0;
char *lockPath, trypass[256],pass[256],lock[8]="locked/";

if(argc!=3) {printf("Wrong input"); return(-1);}

lockPath=(char*)malloc(sizeof(char)*(12+strlen(argv[1])));
strcat(lockPath,lock);
strcat(lockPath,argv[1]);
strcat(lockPath,".txt");

//search the command in the locked folder, if not file its already unlocked

if((passFile=open(lockPath,O_RDONLY,0))==-1) 
                   {
                    printf("Command already unlock!\n");
                     return( -1 );
                    }



else


//if there is file check the password given with the one in the file
strcpy(trypass,argv[2]);


if(read(passFile,pass,256)==-1) 
{

printf("Bad reading");



}
trypass[strlen (trypass) - 2] = '\0';
        pass[strlen (pass) - 2] = '\0';

if(strncmp(trypass, pass,sizeof(trypass)) == 0) 

{ 
pid=fork();
if(pid==0){
execl("/bin/rm","rm",lockPath,0);
printf("ERROR ERROR ERROsR\n");
        exit(1);

}
wait();
printf("The command %s is now unlocked!\n",argv[1]);
}
else 
printf("Wrong Password!\n");


close(passFile);

}
