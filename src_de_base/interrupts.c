#include "interrupts.h"

/**
 * Initialise un traitant en encodant son adresse dans la table des
 * interruptions
 */
void init_traitant(void (*traitant)(void), uint8_t n_interrupt)
{
  uint32_t *ad = (uint32_t*)(INTRPT_VECT_ADD + 2 * 4 * n_interrupt);
  *ad = ((KERNEL_CS & 0xFFFF) << 16) | (((uint32_t)(traitant) & 0xFFFF));
  *(ad + 1) = INTRPT_CST_LOWER | ((uint32_t)(traitant) & 0xFFFF0000);
}

/**
 * Démasque une IRQ
 */
void demasque(uint32_t n_irq)
{
  uint8_t o;
  uint8_t mask;
  uint16_t port;
  if (n_irq < 8) {
    mask = 0xFF ^ (0x01 << n_irq);
    port = IRQ_ADD_MASTER;
  } else {
    mask = 0xFF ^ (0x01 << (n_irq - 8));
    port = IRQ_ADD_SLAVE;
  }
  o = inb(port) & mask;
  o = o & mask;
  outb(o, port);
}