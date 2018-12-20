#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  printf("Value of from_client: %d\n", from_client);
  while(from_client){
    printf("from_client: %d\n", from_client);
    char *contents = malloc(100);
    read(from_client, contents, 100);
    printf("[server]read from client: %s\n", contents);
  }
}
