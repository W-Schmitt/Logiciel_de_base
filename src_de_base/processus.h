#ifndef PROCESSUS_DEF
#define PROCESSUS_DEF 1
#include "inttypes.h"

#define STACK_HEIGHT 512

enum p_state { Idle, Elected };

#endif

typedef struct processus {
  uint32_t pid;
  char name[80];
  enum p_state state;
  uint32_t register_backup[5];
  uint32_t stack[512];
} processus;
