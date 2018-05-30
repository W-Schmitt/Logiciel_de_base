#ifndef __PROCESSUS_H__
#define __PROCESSUS_H__
#include "inttypes.h"

#define STACK_HEIGHT 512
#define REGISTER_BACKUP_COUNT 5

enum p_state { Idle, Elected };

#endif

#include "const.h"

typedef struct processus {
  int32_t pid;
  char* name;
  enum p_state state;
  uint32_t* register_backup;
  uint32_t* stack;
} processus;

processus* new_processus(int32_t pid, char *name, uint32_t name_size, enum p_state state, uint8_t init_stack, uint8_t init_backup);
void ctx_sw(uint32_t* reg1, uint32_t* reg2);