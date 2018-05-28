.text
#include "const.h"
# cette directive sert a rendre l’etiquette publique
.globl traitant_IT_32
# debut du traitant
traitant_IT_32:
  # sauvegarde des registres importants
  pushl %eax
  pushl %edx
  pushl %ecx
  # appel a la fonction C realisant le traitant
  call tic_PIT
  # restauration des registres importants
  popl %ecx
  popl %edx
  popl %eax
  # fin du traitant
  iret

.globl traitant_IT_40
traitant_IT_40:
  # sauvegarde des registres importants
  pushl %eax
  pushl %edx
  pushl %ecx
  # acquittement interrupt 40
  movb $0x20, %al
  movb $0x20, %dx
  outb %al, %dx
  movb $0x20, %al
  movb $0xA0, %dx
  outb %al, %dx

  movb $0x8C, %al
  movb $RTC_CMD_PORT, %dx
  outb %al, %dx
  movb $RTC_DATA, %dx
  inb %dx, %al
  # appel a la fonction C realisant le traitant
  call affiche_date
  # restauration des registres importants
  popl %ecx
  popl %edx
  popl %eax
  # fin du traitant
  iret

.globl traitant_IT_33
traitant_IT_33:
    # sauvegarde des registres importants
  pushl %eax
  pushl %edx
  pushl %ecx
  # acquittement interrupt 40
  movb $0x20, %al
  movb $0x20, %dx
  outb %al, %dx

  call interrupt_clavier
  # restauration des registres importants
  popl %ecx
  popl %edx
  popl %eax
  # fin du traitant
  iret