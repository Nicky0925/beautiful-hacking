#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
  int value = 5;
  char buffer_one[8], buffer_two[8];

  strcpy(buffer_one, "one");
  strcpy(buffer_two, "two");

  printf("buffer_two addr -> %p  buffer_two val -> %s\n", buffer_two, buffer_two);
  printf("buffer_one addr -> %p  buffer_one val -> %s\n", buffer_one, buffer_one);
  printf("var value addr -> %p var value val -> %d(0x%08x)\n", &value, value, value);

  printf("[STRCPY]%d byte copy -> buffer_two\n", strlen(argv[1]));
  strcpy(buffer_two, argv[1]);

  printf("buffer_two addr -> %p  buffer_two val -> %s\n", buffer_two, buffer_two);
  printf("buffer_one addr -> %p  buffer_one val -> %s\n", buffer_one, buffer_one);
  printf("var value addr -> %p var value val -> %d(0x%08x)\n", &value, value, value);

}
