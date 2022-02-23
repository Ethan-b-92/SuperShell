#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[]){

int xfile,yfile,zfile,xbytes,ybytes,zbytes;
char buff[256];
if(argc!=4) {printf("Wrong input"); return(-1);}

//open files
if((xfile=open(argv[1],O_RDONLY))==-1) 
                   {
                     perror("xfile"); 
                     return( -1 );
                    }

if( (yfile=open(argv[2],O_RDONLY))==-1)

                   {
                     perror("yfile"); 
                     return( -1 );
                    }

//if file exists - delete content, if not - create and set him write permission
if( (zfile=open(argv[3],O_CREAT|O_WRONLY|O_TRUNC,0664))==-1)

                   {
                     perror("zfile"); 
                     return( -1 );
                    }


//read from first file xfile and copy to zfile
if( ( xbytes = read( xfile, buff, 256 ) ) == -1 )
		 { perror( "read 1" ); return( -1 ); }

	while( xbytes > 0 )    {
		if( ( zbytes = write( zfile, buff, xbytes ) ) == -1 )
			{ perror( "write" ); return( -1 ); }
		if( zbytes != xbytes )
			{ fprintf( stderr, "bad write\n" ); return( -1 ); }
		if( ( xbytes = read( xfile, buff, 256 ) ) == -1 )
		 	{ perror( "read 2" ); return( -1 ); }
	}

//read from first file yfile and copy to zfile
if( ( ybytes = read( yfile, buff, 256 ) ) == -1 )
		 { perror( "read 1" ); return( -1 ); }

	while( ybytes > 0 )    {
		if( ( zbytes = write( zfile, buff, ybytes ) ) == -1 )
			{ perror( "write" ); return( -1 ); }
		if( zbytes != ybytes )
			{ fprintf( stderr, "bad write\n" ); return( -1 ); }
		if( ( ybytes = read( yfile, buff, 256 ) ) == -1 )
		 	{ perror( "read 2" ); return( -1 ); }
	}

close(xfile); close(yfile); close(zfile);
}
