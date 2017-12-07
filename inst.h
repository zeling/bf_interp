static uintptr_t *pc;
static unsigned char *sp;

#define INST_LIST(T) \
  T(DEC, dec)        \
  T(INC, inc)        \
  T(SHL, shl)        \
  T(SHR, shr)        \
  T(JNZ, jnz)        \
  T(JZ,  jz)         \
  T(PUT, put)        \
  T(GET, get)        

#define DEC_IMPL { \
  (*sp)--;         \
}                  

#define INC_IMPL { \
  (*sp)++;         \
}

#define SHL_IMPL { \
  sp--;            \
}

#define SHR_IMPL { \
  sp++;            \
}

#define JNZ_IMPL { \
  if (*sp) pc += (signed) (*pc); \
  ++pc;                          \
}

#define JZ_IMPL { \
  if (!*sp) pc += (signed) (*pc); \
  ++pc;                           \
}

#define PUT_IMPL { \
  putchar(*sp);       \
}

#define GET_IMPL { \
  *sp = getchar(); \
}
