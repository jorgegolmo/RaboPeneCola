# This is a template Makefile generated by rpcgen
CC = gcc

# Parameters
CLIENT = set_client
SERVER = set_server

TARGETS_SVC.c = set_svc.c set_server.c set_xdr.c claves.c
TARGETS_CLNT.c = set_clnt.c set_client.c set_xdr.c

OBJECTS_CLNT = $(TARGETS_CLNT.c:%.c=%.o)
OBJECTS_SVC = $(TARGETS_SVC.c:%.c=%.o)

CPPFLAGS += -D_REENTRANT
CFLAGS += -g -I/usr/include/tirpc
LDLIBS += -lnsl -lpthread -ldl -ltirpc

all : $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT) : $(OBJECTS_CLNT) 
	$(CC) -o $(CLIENT) $(OBJECTS_CLNT) $(LDLIBS)

$(SERVER) : $(OBJECTS_SVC) 
	$(CC) -o $(SERVER) $(OBJECTS_SVC) $(LDLIBS)

 clean:
	$(RM) $(OBJECTS_CLNT) $(OBJECTS_SVC) $(CLIENT) $(SERVER)