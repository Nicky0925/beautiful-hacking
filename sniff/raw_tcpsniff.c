#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include"../socket/hacking.h"

int main(void) {
  int i, recv_length, sockfd;
  u_char buffer[9000];

  if ((sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
    printf("ソケットが生成できませんでした。\n");
  }

  for (i = 0; i < 3; i++) {
    recv_length = recv(sockfd, buffer, 8000, 0);
    printf("%dバイトのパケットを取得しました。\n", recv_length);
    dump(buffer, recv_length);
  }

  return 0;
}