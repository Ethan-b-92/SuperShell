#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[]){

if(argc!=4||argv[1][1]!='\0') {printf("Parameter Missing or Invalid.\n"); return (-1);}

int i,x=atoi(argv[2]),wfile;
char buff[x],letter=argv[1][0];

if(argc!=4) {printf("Wrong input"); return(-1);}

for(i=0;i<x;i++)
    buff[i]=letter;
//if file exists - delete content, if not - create
if( (wfile=open(argv[3],O_WRONLY | O_CREAT,0664))==-1)

                   {
                     perror("wfile"); 
                     return( -1 );
                    }
else
//go to end of file
lseek( wfile, 0, SEEK_END);


//write the letter
if( write( wfile, buff, x )  == -1 )
			{ perror( "write" ); return( -1 ); }



close(wfile);


}
