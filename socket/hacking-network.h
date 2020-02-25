int send_string (int sockfd, unsigned char *buffer) {
  int sent_bytes, bytes_to_sent;
  bytes_to_sent = strlen(buffer);
  while (bytes_to_sent > 0) {
    sent_bytes = send(sockfd, buffer, bytes_to_sent, 0);
    if (sent_bytes == -1) {
      return 0;
    }
    bytes_to_sent -= sent_bytes;
    buffer += sent_bytes;
  }
  return 1;
}

int recv_line (int sockfd, unsigned char *dest_buffer) {
#define EOL "\r\n"
#define EOL_SIZE 2
  unsigned char *ptr;
  int eol_matched = 0;

  ptr = dest_buffer;

  while (recv(sockfd, ptr, 1, 0) == 1) {
    if (*ptr == EOL[eol_matched]) {
      eol_matched++;
      if (eol_matched == EOL_SIZE) {
        *(ptr+1 - EOL_SIZE) = '\0';
        return strlen(dest_buffer);
      }
    } else {
      eol_matched = 0;
    }
    ptr++;
  }
  return 0;
}
