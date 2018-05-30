#include "processus.h"
#include "malloc.c.h"

processus* new_processus(int32_t pid, char *name, uint32_t name_size, enum p_state state, uint8_t init_stack, uint8_t init_backup)
{
  processus *p = malloc(sizeof(processus));
  p->pid = pid;
  p->name = malloc(name_size*sizeof(char));
  p->state = state;
  if (init_backup) {
    p->register_backup = malloc(REGISTER_BACKUP_COUNT*sizeof(uint32_t));
  }
  if (init_stack) {
    p->stack = malloc(STACK_HEIGHT*sizeof(uint32_t));
  }
  return p;
}