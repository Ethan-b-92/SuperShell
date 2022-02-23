#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[]){

int i=0,j=0,rbytes,rfile, counter[26]={0};;
char buff[256];
double p,sum=0;
if(argc!=2) {printf("Wrong input");return(-1);}
//opens the file
if((rfile=open(argv[1],O_RDONLY))==-1) 
                   {
                     perror("rfile"); 
                     return( -1 );
                    }

//read from file
if( ( rbytes = read( rfile, buff, 256 ) ) == -1 )
		 { perror( "read 1" ); return( -1 ); }
//read from file and extract only the letters and place accordingly in counter array
	while( rbytes > 0 )    {
		j=0;
while(buff[j]!='\0'){
          for(i=0;i<26;i++)
          if(buff[j]==(i+65)||buff[j]==(i+97)) 
             counter[i]++;
		j++;
}
		if( ( rbytes = read( rfile, buff, 256 ) ) == -1 )
		 	{ perror( "read 1" ); return( -1 ); }
	}
//sum of letters
for(i=0;i<26;i++)
sum+=counter[i];

//printing precentage 
for(i=0;i<26;i++)
counter[i]!=0?printf(" %c - %.1f%\n",i+97, (double)counter[i]*100.0/ sum):0;


close(rfile);

}

