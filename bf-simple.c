#include <stdint.h>
#include <stdio.h>
#include "inst.h"

#define T(upper, lower) void lower() upper##_IMPL
INST_LIST(T)
#undef T


void interp() {
  while (*pc) {
    ((void (*) ()) (*pc++))();
  }
}

static unsigned char stack[128];

int main(int argc, char *argv[]) {
  uintptr_t echo[] = { (uintptr_t) &shr
                     , (uintptr_t) &jz, 3
                     , (uintptr_t) &dec
                     , (uintptr_t) &jnz, (uintptr_t) -3
                     , (uintptr_t) &shl
                     , (uintptr_t) &get
                     , (uintptr_t) &jz, 6
                     , (uintptr_t) &dec
                     , (uintptr_t) &shr
                     , (uintptr_t) &inc
                     , (uintptr_t) &shl
                     , (uintptr_t) &jnz, (uintptr_t) -6
                     , (uintptr_t) &shr
                     , (uintptr_t) &put
                     , 0 };
  pc = echo;
  sp = stack;
  interp();
  return 0;
}
