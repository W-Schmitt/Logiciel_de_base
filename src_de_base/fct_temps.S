/* void demasque(uint32_t n_irq)
{
  uint8_t o = inb(IRQ_ADD);
  uint8_t mask = 0xFF ^ (0x01 << n_irq);
  o = o & mask;
  outb(o, IRQ_ADD);
} */
  .globl demasque_ass
  .text
#include "const.h"
  # 8(%ebp): n_irq
  # -8(%ebp): o
  # -16(%ebp): mask
demasque_ass:
  enter $16, $0
  movw $IRQ_ADD_MASTER, %dx
  inb %dx, %al
  movb %al, -8(%ebp)
  movb $0xFF, %al
  # 0x01 << n_irq
  movb $0x01, %dl
  movb 8(%ebp), %cl
  shlb %cl, %dl
  xorb %dl, %al
  andb -8(%ebp), %al
  outb %al, $IRQ_ADD_MASTER
  leave
  ret

/* void set_freq(void)
{
  outb(CLK_FREQ_SET_ENABLE_VAL, CLK_FREQ_SET_ENABLE_PORT);
  outb((QUARTZ / CLOCKFREQ) % 256, CLK_FREQ_PORT);
  outb((uint8_t)((QUARTZ / CLOCKFREQ) >> 8), CLK_FREQ_PORT);
} */
  .globl set_freq
  .text
set_freq:
  enter $0, $0
  movw $CLK_FREQ_SET_ENABLE_PORT, %dx
  movb $CLK_FREQ_SET_ENABLE_VAL, %al
  outb %al, %dx
  # QUARTZ / CLOCKFREQ
  movl $QUARTZ, %eax
  movl $0, %edx
  movl $CLOCKFREQ, %ecx
  divl %ecx
  movw $CLK_FREQ_PORT, %dx
  outb %al, %dx
  movb %ah, %al
  outb %al, %dx
  leave
  ret