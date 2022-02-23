#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

/* The command creates text file in "locked" folder, named it after the command and set the pass inside.*/


int main(int argc,char* argv[]){
int passFile;
char buff[256],lock[8]="locked/",*lockPath;
if(argc!=3) {printf("Wrong input");return(-1);}

lockPath=(char*)malloc(sizeof(char)*(12+strlen(argv[1])));
strcat(lockPath,lock);
strcat(lockPath,argv[1]);
strcat(lockPath,".txt");

//checks if there is already file named after the command if yes - advice to unlock and then change to another password.
if((passFile=open(lockPath,O_RDONLY,0))!=-1) 
                   {
                     printf("Command already locked, please unlock it first using unlockCMD\n"); 
                     return( -1 );
                    }
//locking command by creating new file in locked folder named after the command
else if((passFile=open(lockPath,O_WRONLY | O_CREAT, 0664))==-1) 
                   {
                     perror("Error locking"); 
                     return( -1 );
                    }
//copy the password by the user
        strcpy(buff,argv[2]);
        
//write it inside the file
if( write( passFile, buff, strlen(buff) ) == -1 )
			{ perror( "write" ); return( -1 ); }


printf("The command %s is now locked!\n",argv[1]);




close(passFile);



}

