/*****************************************************************************
*
*	FILE NAME:
*
*	DESCRIPTION:
*
*****************************************************************************/
/****************************************************************************
*			HEADER DECLARATION
*****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

/****************************************************************************
*			GLOBAL MACROS	
*****************************************************************************/
#define SUCCESS 1
#define FAILURE 0
#define BLOCKSIZE 100
#define MAXNAME 100
/****************************************************************************
*			FUNCTION PROTOTYPES
*****************************************************************************/
int get_input(char *str);
int case_check(char *str, int *mode);
int send_query(int sd, char *str, int mode);
int read_description(int sd,int *size, char *result);
int remove_newline(char *str);
int myread(int sd,long int n ,void *buffer);
int mywrite(int sd,long int n ,void *buffer);


typedef struct file_details
{
	char file_name[50];
	int file_size;
	char file_desc[BLOCKSIZE];	
}file_details;

int display_details(int num, file_details *fd);
int send_path(int sd,file_details *fd, int num);
int read_content(int sd);
int receive_details(int sd,file_details **fd,int* num);

