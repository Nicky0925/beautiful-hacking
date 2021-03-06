#include<stdio.h>
#include<stdlib.h>

int global_var;
int global_initialized_var = 5;

void function() {
  int stack_var;

  printf("function() -> stack_var:0x%08x\n", &stack_var);
}

int main() {
  int stack_var;
  static int static_initialized_var = 5;
  static int static_var;
  int *heap_var_ptr;

  heap_var_ptr = (int *)malloc(4);

  printf("global_initialized_var addr:0x%08x\n", &global_initialized_var);
  printf("static_initialized_var addr:0x%08x\n", &static_initialized_var);

  printf("static_var addr:0x%08x\n", &static_var);
  printf("global_var addr:0x%08x\n", &global_var);

  printf("heap_var_ptr addr:0x%08x\n", heap_var_ptr);

  printf("stack_var addr:0x%08x\n", &stack_var);
}
