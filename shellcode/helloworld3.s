BITS 32

jmp short one

two:
  pop ecx
  xor eax, eax
  mov al, 4
  xor ebx, ebx
  inc ebx
  xor edx, edx
  mov dl, 15
  int 0x80

mov al, 1
dec ebx
int 0x80

one:
  call two
  db "Helloworld!", 0x0a, 0x0d

