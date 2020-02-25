#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#include"hacking.h"
#include"hacking-network.h"

int main(int argc, char *argv[]) {
  int sockfd;
  struct hostent *host_info;
  struct sockaddr_in target_addr;
  unsigned char buffer[4096];

  if (argc < 2) {
    printf("使用方法:%s<ホスト名>\n", argv[0]);
  }
  if ((host_info = gethostbyname(argv[1])) == NULL) {
    printf("ホスト名の検索に失敗しました。\n");
  }
  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    printf("ソケットの作成ができませんでした。\n");
  }

  target_addr.sin_family = AF_INET;
  target_addr.sin_port = htons(80);
  target_addr.sin_addr = *((struct in_addr *)host_info -> h_addr);
  memset(&(target_addr.sin_zero), '\0', 8);

  if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(struct sockaddr)) == -1) {
    printf("相手先サーバと接続できませんでした。\n");
  }

  send_string(sockfd, "HEAD / HTTP/1.0\r\n\r\n");

  while (recv_line(sockfd, buffer)) {
    if (strncasecmp(buffer, "Server:", 7) == 0) {
      printf("%sのウェブサーバは%sです。\n", argv[1], buffer+8);
      exit(0);
    }
  }
  printf("Server行が見つかりませんでした。\n");
  exit(1);
}
