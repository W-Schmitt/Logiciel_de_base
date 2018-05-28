/*
uint16_t *ptr_mem(uint32_t lig, uint32_t col)
{
  return ((uint16_t *)(CGA_MEM_START + 2 * (lig * CGA_CST_COLS + col)));
}
*/
  .text
#include "const.h"
  .globl ptr_mem
  # uint16_t *ptr_mem(uint32_t lig, uint32_t col)
  # 8(%ebp): lig
  # 12(%ebp): col
ptr_mem:
  enter $0, $0
  # %eax = CGA_CST_COLS
  movl $CGA_CST_COLS, %eax
  # %eax = lig * CGA_CST_COLS
  mull 8(%ebp)

  # %eax = col + lig * CGA_CST_COLS
  addl 12(%ebp), %eax
  # %eax = 2 * (lig * CGA_CST_COLS + col
  shll $1, %eax
  addl $CGA_MEM_START, %eax
  leave
  ret

/*
void ecrit_car(uint32_t lig, uint32_t col, char c,
  uint32_t coul_texte, uint32_t coul_fond)
{
  // NOTE: bit 7 is 0 due to bad support of blinking cursor
  *ptr_mem(lig, col) = c | (coul_texte << 8) | (coul_fond << 12);
}
*/
  .globl ecrit_car
  # lig: 8(%ebp)
  # col: 12(%ebp)
  # c: 16(%ebp)
  # coul_texte: 20(%ebp)
  # coul_fond: 24(%ebp)
ecrit_car:
  enter $0, $0
  # calling ptr_mem
  pushl 12(%ebp)
  pushl 8(%ebp)
  call ptr_mem
  # resetting stack
  addl $8, %esp
  # %dx = c
  movw 16(%ebp), %dx
  movw 20(%ebp), %cx
  shlw $8, %cx
  orw %cx, %dx
  movw 24(%ebp), %cx
  shlw $12, %cx
  orw %cx, %dx
  movw %dx, (%eax)
  leave
  ret

/* void place_curseur(uint32_t lig, uint32_t col)
{
  uint16_t position = col + 80 * lig;
  uint8_t lower = position & 0x0F;
  outb(VGA_CURSOR_CMD_LOWER, VGA_CURSOR_POSITION_CMD);
  outb(lower, VGA_CURSOR_POSITION_DATA);

  uint8_t upper = (position & 0xF0) >> 8;
  outb(VGA_CURSOR_CMD_UPPER, VGA_CURSOR_POSITION_CMD);
  outb(upper, VGA_CURSOR_POSITION_DATA);
} */
  .globl place_curseur
  # void place_curseur(uint32_t lig, uint32_t col)
  # lig: 8(%ebp)
  # col: 12(%ebp)
place_curseur:
  enter $24, $0
  movb 8(%ebp), %ax
  movw $CGA_CST_COLS, %dx
  mulw %dx
  addw 12(%ebp), %ax
  # position: 8(%ebp)
  movw %ax, 8(%ebp)
  # lower = 12(%ebp)
  movb %al, 12(%ebp)
  # upper = 16(%ebp)
  movb %ah, 16(%ebp)

  # outb lower
  movb $VGA_CURSOR_CMD_LOWER, %al
  movw $VGA_CURSOR_POSITION_CMD, %dx
  outb %al, %dx
  movb 12(%ebp), %al
  movw $VGA_CURSOR_POSITION_DATA, %dx
  outb %al, %dx

  # outb upper
  movb $VGA_CURSOR_CMD_UPPER, %al
  movw $VGA_CURSOR_POSITION_CMD, %dx
  outb %al, %dx
  movb 16(%ebp), %al
  movw $VGA_CURSOR_POSITION_DATA, %dx
  outb %al, %dx
  leave
  ret


