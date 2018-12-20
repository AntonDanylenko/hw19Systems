#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  char *contents = malloc(100);
  char *response = malloc(100);

  signal(SIGINT, sighandler);

  while(1){
    from_client = server_handshake( &to_client );

    //printf("Value of from_client: %d\n", from_client);
    while(from_client){
      //printf("from_client: %d\n", from_client);
      read(from_client, contents, 100);
      printf("[server]read from client: %s\n", contents);
      //process_data(contents, response);
      strcpy(response, contents);
      strcat(response, "-BACK");
      write(to_client, response, 100);
      //printf("[server]wrote to client: %s\n", response);
    }

    printf("Client Exited\n");
  }
}
