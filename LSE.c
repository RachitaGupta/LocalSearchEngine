  
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<unistd.h>
    #include<sys/stat.h>
    #include<sys/types.h>
    #include<sys/socket.h>
    #include<sys/wait.h>
    #include<errno.h>
    #include<fcntl.h>
    #include<netinet/in.h>
    #include<arpa/inet.h>
    #define SUCCESS 1
    #define FAILURE 0
    int my_read(int, char **buffer);
    int process(char **buffer,int ret);
    int my_write(int confd,char **buffer,int ret);
   
    #include"header.h"
    char vowel[10]={'a','e','i','o','u','A','E','I','O','U'};
    int process(char ** buffer,int ret)
    {
            char *token[20];
            char buff[10]
            memset(buff,0,10);
            memset(token,0,20*sizeof(char*));
            int i=0;
            token[i]=strtok(*buffer," ");
            while(NULL!=token[i])
            {
                    i++;
                    token[i]=strtok(NULL," ");
            }
            free(*buffer);
            int l,vow=0,total=0;
            char vowe[2];
            for(j=0;j<i;j++)
            {
                    strcpy(buff,token[j],strlen(token[j]));
                    for(k=0;k<strlen(buff);k++)
                    {
                            for(l=0;l<10;i++)
                            {
                            if(buff[k]==vowel[l])
                                    vow++;
                            }
                    }
                    sprintf(vowe,"%d",vow);
                    buffer=(char*)realloc(*buffer,len+strlen(token[j])+2);
                    memcpy(*buffer+total,token[j],strlen(token[j]));
                    memcpy(*buffer+total+1,vowe,2);
                    total=strlen(*buffer);
                    vow=0;
            }
    }
    int my_write(int sd,char **buffer,int len)
    {
            int totalbytes=0;
            int pointer=0;
            while(1)
            {
                    ret=write(sd,buffer+pointer,len-totalbytes);
                    if(0>ret)
                    {
                            perror("error in writing");
                            return FAILURE;
                    }
                    pointer+=ret;
                    totalbytes+=ret;
                    if(totalbytes==len)
                    {
                            return totalbytes;
                    }
            }
    }
    int my_read(int sd,char **buffer)
    {
     int total=0;
            int pointer=0;
            char buff[10];
            memset(buff,0,10);
            while(1)
            {
                    ret=read(sd,buff,10);
                    if(0>ret)
                    {
                    }
                    total+=ret;
                    buffer=(char)realloc(buffer,total);
                    memcpy(buffer+pointer,buff,ret);
                    pointer+=ret;
                    if(strstr(*buffer,"$",1))
                    {
                            return totalbytes;
                    }
            }
    }
     