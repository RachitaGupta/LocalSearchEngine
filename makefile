
CC=gcc
FLAG=-c -DTRACE_FEATURE -g -Wall -save-temps
OPATH=./../obj/
IPATH=./../include/
BPATH=./../bin/
SPATH=./../src/

all: $(BPATH)server $(BPATH)client

$(BPATH)server: $(OPATH)server.o $(OPATH)func.o $(OPATH)server_function.o $(OPATH)lse_error.o
	$(CC) -o server $(OPATH)server.o $(OPATH)func.o $(OPATH)server_function.o $(OPATH)lse_error.o
	mv server $(BPATH)

$(BPATH)client:$(OPATH)client_function.o $(OPATH)func.o $(OPATH)client.o $(OPATH)lse_error.o
	$(CC) -o client $(OPATH)client_function.o $(OPATH)func.o $(OPATH)client.o $(OPATH)lse_error.o
	mv client $(BPATH)

$(OPATH)client_function.o: $(SPATH)client_function.c $(IPATH)client_header.h
	$(CC) $(FLAG) $(SPATH)client_function.c -I$(IPATH)
	mv client_function.o $(OPATH)

$(OPATH)client.o: $(SPATH)client.c $(IPATH)client_header.h
	$(CC) $(FLAG) $(SPATH)client.c -I$(IPATH) 
	mv client.o $(OPATH)

$(OPATH)func.o: $(SPATH)func.c $(IPATH)client_header.h
	$(CC) $(FLAG) $(SPATH)func.c -I$(IPATH) 
	mv func.o $(OPATH)


$(OPATH)server_function.o: $(SPATH)server_function.c $(IPATH)server_header.h
	$(CC) $(FLAG) $(SPATH)server_function.c -I$(IPATH)
	mv server_function.o $(OPATH)

$(OPATH)server.o: $(SPATH)server.c $(IPATH)server_header.h
	$(CC) $(FLAG) $(SPATH)server.c -I$(IPATH)
	mv server.o $(OPATH)

$(OPATH)lse_error.o: $(SPATH)lse_error.c $(IPATH)LSE_trace.h 
	$(CC) $(FLAG) $(SPATH)lse_error.c -I$(IPATH)
	mv lse_error.o $(OPATH)

clean:
	rm $(BPATH)server
	rm $(OPATH)*.o
	rm $(BPATH)client
