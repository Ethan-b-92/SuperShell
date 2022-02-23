#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[]){

if(argc!=3) {printf("Wrong input");return(-1);}
//seed for rand() to have a different starting point
srand(time(NULL));

int i=0,wfile,wbytes,x=atoi(argv[1]);
char buff[x];

if(argc!=3) {printf("Wrong input"); return(-1);}

//if file exists - delete content, if not - create
if( (wfile=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0664))==-1)

                   {
                     perror("zfile"); 
                     return( -1 );
                    }

//generating random number for upper or lowercase and random letter
for(i=0;i<x;i++)
//lowercase option
if(rand()%2==1)
buff[i]=(rand()%26) +97;
else
//uppercase option
buff[i]=(rand()%26) +65;

if( ( wbytes = write( wfile, buff, x ) ) == -1 )
			{ perror( "write" ); return( -1 ); }

close(wfile);





}
