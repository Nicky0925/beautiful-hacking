#include<stdio.h>
#include<string.h>

char SHELLCODE[] = "\xeb\x13\x59\x31\xc0\xb0\x04\x31\xdb\x43\x31\xd2\xb2\x0f\xcd\x80\xb0\x01\x4b\xcd\x80\xe8\xe8\xff\xff\xff\x48\x65\x6c\x6c\x6f\x77\x6f\x72\x6c\x64\x21\x0a\x0d";

void func(char *str) {
  char buffer[16];
  strcpy(buffer, str);
}

int main(int argc, char *argv[]) {
  func(argv[1]);
  return 0;
}
