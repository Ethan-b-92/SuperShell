#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>




int main(int argc,char* argv[]){
 

int password=0,flag=0,passFile,t=0,i=0,pid,spe=0;

char *temppass,pass[256],progName[256],trypass[256],*speCMD[10]={"runC","lockCMD","unlockCMD","concatFiles","distABC","uppercase","lowercase","randomFile","putLetter","byebye"};
char *lockPath,*Path,*spePath,*token[5],temp[6]="/bin/",local[3]="./",s[2]=" ",lock[8]="locked/";




while(1)
{
password=0;
spe=0;
t=0;
printf("SuperShell>");
fgets(progName, 256, stdin);


 if ((strlen(progName) > 0) && (progName[strlen (progName) - 1] == '\n'))
        progName[strlen (progName) - 1] = '\0';



for(i=0;i<strlen(progName);i++)
       if(progName[i]==' ')
        t++;

if(t>3) printf("Not Supported\n");
//retrieving the words from the propmt with strtok
token[0] = strtok(progName, s);
i=1;

while(token[i-1]!=NULL)
   token[i++] = strtok(NULL, s);
   
if(token[0]!=NULL) {//in case user pressed "enter"
Path=(char*)malloc(sizeof(char)*(6+strlen(token[0])));
spePath=(char*)malloc(sizeof(char)*(3+strlen(token[0])));
strcpy(spePath,local);
strcat(spePath,token[0]);
strcpy(Path,temp);
strcat(Path,token[0]);
lockPath=(char*)malloc(sizeof(char)*(12+strlen(progName)));
strcat(lockPath,lock);
strcat(lockPath,progName);
strcat(lockPath,".txt");
//checks if its byebye command
if(strncmp(progName,"byebye",sizeof(progName))==0 && token[1]==NULL) return;

//checks if its locked(have a text file inside locked folder that the shell created).
if((passFile=open(lockPath,O_RDONLY,0))!=-1) 
                   {
                     printf("Enter Password:"); 
                     fgets(trypass, 256, stdin);
                     temppass=strtok(trypass,"\n");
                     if(read(passFile,pass,256)==-1){
                       printf("error reading passfile");
                                return (-1);
                                                    } 
                       lseek( passFile, 0, SEEK_SET ) ;
                           if(flag==0){ pass[strlen (pass) - 2] = '\0'; flag=1;}

        
                     if(strncmp(temppass, pass,sizeof(temppass)) == 0) 
                           password=1;



                    }
//either its no locked or user propmt the correct password.
if (password==1 || passFile==-1) {
pid=fork();

        if(t<4 && pid==0)
                {


//check if its spe command
for(i=0;i<10;i++)
if(strncmp(progName, speCMD[i], sizeof(progName)) == 0) spe=1;
        if(spe==1){ 
        execvp(spePath,token);
        printf("ERROR ERROR ERROR\n");
        exit(1);}
else {
        
        execvp(Path,token);
        printf("Not Supported\n");
        exit(1);
     }
                }
                                 }
else printf("Wrong password!!!\n");
}

wait();

}

close(passFile);

}

