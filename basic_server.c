#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  char *contents = malloc(100);
  char *response = malloc(sizeof(contents));

  from_client = server_handshake( &to_client );

  printf("Value of from_client: %d\n", from_client);
  while(from_client){
    printf("from_client: %d\n", from_client);
    read(from_client, contents, 100);
    printf("[server]read from client: %s\n", contents);
    //process_data(contents, response);
    strcpy(response, data);
    strcat(response, "BACK");
    write(to_client, response, sizeof(response));
    printf("[server]wrote to client: %s\n", response);
  }
}
