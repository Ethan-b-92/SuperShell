#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
int j=0,i=0,rfile,wfile,rbytes,wbytes;
char buff[256];

if(argc!=3) {printf("Wrong in44put"); return(-1);}

//open the file
if((rfile=open(argv[1],O_RDONLY))==-1) 
                   {
                     perror("rfile"); 
                     return( -1 );
                    }

if( (wfile=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0664))==-1)

                   {
                     perror("wfile"); 
                     return( -1 );
                    }
//read from file
if( ( rbytes = read( rfile, buff, 256 ) ) == -1 )
		 	{ perror( "read 1" ); return( -1 ); }

while( rbytes > 0 )    {
		j=0;
//change lowercase to uppercase
while(buff[j]!='\0'){
          for(i=0;i<26;i++)
          if(buff[j]==(i+97)) 
             buff[j]=(i+97)-32;
j++;
}
//write to file

		if( ( wbytes = write( wfile, buff, rbytes ) ) == -1 )
			{ perror( "write" ); return( -1 ); }
		if( wbytes != rbytes ) // write problem 
			{ fprintf( stderr, "bad write\n" ); return( -1 ); }
		
	
//keep reading from file
		if( ( rbytes = read( rfile, buff, 256 ) ) == -1 )
		 	{ perror( "read 1" ); return( -1 ); }


	                   }



}
