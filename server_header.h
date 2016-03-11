/********************************************************************************
*	FILE NAME	: server_header.h
*	DESCRIPTION	: contains header files, macros and function
*			  prototypes
*
*******************************************************************************/

/*******************************************************************************
				HEADER FILES
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>

/******************************************************************************
				   MACROS
*******************************************************************************/

#define QSIZE 5
#define BUFSIZE 512
#define MYPORT 38902
#define MAXNAME 100
#define BLOCKSIZE 100
#define FILESIZE 50
#define MAX_FILE_SIZE 600 
#define SUCCESS 1
#define FAILURE 0

/*******************************************************************************
			file_details DATA SRUCTURE
*******************************************************************************/

typedef struct file_details
{
        char file_name[FILESIZE];
        int file_size;
        char file_desc[BLOCKSIZE];
} file_details;

/*******************************************************************************
			    FUNCTION PROTOTYPES
*******************************************************************************/

int serverwork (int);
int myread (int, long int, void *);
int mywrite (int, long int, void *);
int file_find (char *);
int file_details_calc ();
int file_size_calc (char *);
int file_two_line_desc (char *, char *);
int receive_path (char *path, int connfd);
int receive_query (char *path, int connfd);
int read_file (char *path, char **buf);
int send_content (int connfd, char *buffer);

