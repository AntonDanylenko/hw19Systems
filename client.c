#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  printf("value of from_server: %d\n", from_server);
  while(from_server){
    char *input = malloc(500);
    char *contents = malloc(100);
    printf("Send data: ");
    fgets(input, 500, stdin);
    printf("Given input: %s\n", input);
    write(to_server, input, 500);
    read(from_server, contents, 100);
    printf("[client]read from server: %s\n", contents);
  }
}
