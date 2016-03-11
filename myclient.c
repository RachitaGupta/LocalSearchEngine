    #include "header.h"
    int main(int argc,char*argv[])
    {
            int sd,ret,len;
            struct sockaddr_in serveraddress;
            if(argc!=4)
            {
                    printf("enter correct number of arguments\n");
                    return FAILURE;
            }
            sd=socket(AF_INET,SOCK_STREAM,0);
            if(0>sd)
            {
            }
            if(NULL==argv[1])
            {
                    printf("enter port number\n");
                    exit(1);
            }
            if(NULL==argv[2])
            {
                    printf("enter IP address\n");
                    exit(1);
            }
            memset(&serveraddress,0,sizeof(serveraddress));
            serveraddress.sin_family=AF_INET;
            serveraddress.sin_port=htons(atoi(argv[1]));
            serveraddress.sin_addr.s_addr=inet_addr(argv[2]);
            char *buffer=NULL;
            if(connect(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress)) < 0 )
            {
                    printf("cannot connect\n");
                    exit(1);
            }
            while(1)
            {
                    len=strlen(argv[3]);
                    char* temp;
                    temp=(char*)realloc(buffer,len+1);
                    if(NULL==buffer)
                    {
                            return FAILURE;
                    }
                    buffer=temp;
                    strncpy(buffer,argv[3],len);
                    strncat(buffer,"$",1);
                    ret=my_write(sd,&buffer,len);
                    if(ret==0)
                    {
                            printf("error in writing");
                            exit(1);
                    }
                    ret=my_read(sd,&buffer);
                    printf("%s",buffer);
                    free(buffer);
                    buffer=NULL;
                    close(sd);
                    exit(1);
            }
     }
            return 0;
    }
     
     
