void fatal(char *message) {
  char error_message[100];

  strcpy(error_message, "[!!]Fatal ERR");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}

void *ec_malloc(unsigned int size) {
  void *ptr;
  ptr = malloc(size);
  if (ptr == NULL) {
    fatal("ec_malloc() memory err");
  }
  return ptr;
}

void dump (const unsigned char *data_buffer, const unsigned int length) {
  unsigned char byte;
  unsigned int i, j;

  for (i = 0; i < length; i++) {
    byte = data_buffer[i];
    printf("%02x ", data_buffer[i]); // byteを16進で表記
    if (((i % 16) == 15) || (i == length - 1)) {
      for (j = 0; j < 15 - (i % 16); j++) {
        printf("  ");
      }
      printf("| ");
      for (j = (i-(i%16)); j <= i; j++) { // 行内の印字可能なバイトを表示
        byte = data_buffer[j];
        if ((byte > 31) && (byte < 127)) {
          printf("%c", byte);
        } else {
          printf(".");
        }
      }
      printf("\n");
    }
  }
}
