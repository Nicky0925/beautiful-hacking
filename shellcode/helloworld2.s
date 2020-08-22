BITS 32

jmp short one

two:
;ssize_t write(int fd, const void *buf, size_t count);
  pop ecx
  mov eax, 4
  mov ebx, 1
  mov edx, 15
  int 0x80

;void _exit(int status);
mov eax, 1,
mov ebx, 0
int 0x80

one:
  call two
  db "helloworld!", 0x0a, 0x0d

