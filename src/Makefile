BIN_FILES = servidor-sock app-cliente-1 app-cliente-2 app-cliente-3 app-cliente-4 app-cliente-5 app-cliente-6
INSTALL_PATH = $(PWD)

CC = gcc

CFLAGS = -Wall -Ofast -march=native
# CFLAGS = -Wall -Ofast -march=native -DDEBUG

LDFLAGS = -L$(INSTALL_PATH)
LDLIBS = -lclaves

all: libclaves.so $(BIN_FILES)

servidor-sock: servidor-sock.o claves.o pet-resp.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

app-cliente-1: app-cliente-1.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

app-cliente-2: app-cliente-2.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

app-cliente-3: app-cliente-3.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

app-cliente-4: app-cliente-4.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

app-cliente-5: app-cliente-5.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

app-cliente-6: app-cliente-6.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

libclaves.so: libclaves.o pet-resp.o
	$(CC) $(CFLAGS) $(LDFLAGS) -shared $^ -o $@

libclaves.o: proxy-sock.c
	$(CC) $(CFLAGS) -fpic -c $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BIN_FILES) *.o *.so
