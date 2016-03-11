    #include "header.h"
    #define MYPORT 38884
    int main(int argc,char *argv[])
    {
    int sd,confd,ret;
    struct sockaddr_in serveraddress,cliaddress;
    sd=socket(AF_INET,SOCK_STREAM,0);
    if(0>sd)
             {
                     perror("socket");
                     exit(1);
             }
             memset(&serveraddress,0,sizeof(serveraddress));
             serveraddress.sin_family=AF_INET;
             serveraddress.sin_port=htons(MYPORT);
             serveraddress.sin_addr.s_addr=htonl(INADDR_ANY);
             ret=bind(sd,(struct sockaddr*)&serveraddress,sizeof(servaddress));
             if(-1==ret)
             {
                    perror("bind fails");
                     exit(1);
             }
            listen(sd,5);
             socklen_t len;
             char *buffer=NULL;
             for(;;)
             {
                     printf("I am waiting----start of Main Loop\n");
                     len=sizeof(cliaddress);
                     confd=accept(sd,(struct sockaddr*)&cliaddress,&len);
                     if(0>confd)
                    {
                             if(errno==EINTR)
                             printf("interrupted system calls\n");
                             continue;
                     }
                     printf("connection started\n");
                    int plen;
                     inet_ntop(AF_INET,&cliaddress.sin_addr,buff,sizeof(buff));
                     while(1)
                     {
                             ret=my_read(confd,&buffer);
                             if(0==ret_bin)
                             {
                printf("error in reading\n");
                             }
                             ret_bin=process(&buffer,ret);
                            if(0==ret_bin)
                             {
                                printf("error in processing\n");
                             }
                             my_write(confd,&buffer,ret);
                             free(buffer);
                     }
                     printf("completed serving client\n");
                     close(confd);
             }
     }

 