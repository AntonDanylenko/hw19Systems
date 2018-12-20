#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client
  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  mkfifo("wkp", 0777);
  int from_client;
  from_client = open("wkp", O_RDONLY);
  char *contents = malloc(100);
  read(from_client, contents, 100);
  //char *client_pipe = malloc(100);
  unlink("wkp");
  printf("[server]{handshake}read from client: %s\n", contents);
  *to_client = open(contents, O_WRONLY);
  write(*to_client, "hola", 5);
  printf("[server]{handshake}write to client\n");
  read(from_client, contents, 100);
  printf("[server]{handshake}read from client: %s\n", contents);
  printf("END HANDSHAKE\n");
  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  mkfifo("priv", 0777);
  *to_server = open("wkp", O_WRONLY);
  write(*to_server, "priv", 5);
  printf("[client]{handshake}write to server\n");
  //write(to_server, getpid(), sizeof(getpid()));
  int from_server;
  from_server = open("priv", O_RDONLY);
  char *contents = malloc(100);
  read(from_server, contents, 100);
  unlink("priv");
  printf("[client]{handshake}read from server: %s\n", contents);
  write(*to_server, ACK, 5);
  printf("[client]{handshake}write to server\n");
  printf("END HANDSHAKE\n");
  return from_server;
}

/*=========================
  process data to send back to client.
  each character in input string becomes 1 greater in output.
  =========================*/
/*int process_data(char *input, char *output){
  while(input){
    strcat(output, input[0] + 1);
    input++;
  }
  printf("input: %s\n", input);
  printf("output: %s\n", output);
  return 0;
}*/
