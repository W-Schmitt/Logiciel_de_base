#ifndef __START_H__
#define __START_H__

#define FIRST_STACK_SIZE 16384

#ifndef ASSEMBLER

extern char first_stack[FIRST_STACK_SIZE];

#include "ecran.h"
#include "const.h"
#include "temps.h"
#include "date.h"
#include "clavier.h"
#include "interrupts.h"
#include "processus.h"

/* The kernel entry point */
void kernel_start(void);

#endif

#endif
