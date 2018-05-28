#include <cpu.h>
#include <inttypes.h>
#include "ecran.h"
#include "const.h"
#include "temps.h"
#include "date.h"
#include "clavier.h"
#include "interrupts.h"

// on peut s'entrainer a utiliser GDB avec ce code de base
// par exemple afficher les valeurs de x, n et res avec la commande display

// une fonction bien connue
uint32_t fact(uint32_t n)
{
    uint32_t res;
    if (n <= 1) {
        res = 1;
    } else {
        res = fact(n - 1) * n;
    }
    return res;
}

void kernel_start(void)
{
    set_freq();
    set_rtc_freq(14);
    // Uptime
    init_traitant(traitant_IT_32, 32);
    // Clavier
    init_traitant(traitant_IT_33, 33);
    // RTC
    init_traitant(traitant_IT_40, 40);
    clear();
    traite_car('\n');
    // Uptime
    demasque(0);
    // Clavier
    demasque(1);
    // RTC
    demasque(2);
    demasque(8);

    sti();
    // quand on saura gerer l'ecran, on pourra afficher x
    // (void)x;
    // on ne doit jamais sortir de kernel_start
    while (1) {
        // cette fonction arrete le processeur
        hlt();
    }
}

