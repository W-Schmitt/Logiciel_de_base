#include <cpu.h>
#include <inttypes.h>
#include "start.h"

processus p[PROCESS_TABLE_SIZE];

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

void idle(void)
{
    printf("[idle] je tente de passer la main a proc1...\n");
    ctx_sw(p[0].register_backup, p[1].register_backup);
}

void proc1(void)
{
    printf("[proc1] idle m’a donne la main\n");
    printf("[proc1] j’arrete le systeme\n");
    hlt();
}

void kernel_start(void)
{
/*     set_freq();
    set_rtc_freq(14); */
/*     // Uptime
    init_traitant(traitant_IT_32, 32);
    // Clavier
    init_traitant(traitant_IT_33, 33);
    // RTC
    init_traitant(traitant_IT_40, 40); */
    // clear();
    // traite_car('\n');
    /* // Uptime
    demasque(0);
    // Clavier
    demasque(1);
    // RTC
    demasque(2);
    demasque(8); */

    p[0] = (*new_processus(0, "init", 4, Elected, FALSE, FALSE));
    p[1] = (*new_processus(1, "p1", 2, Idle, TRUE, TRUE));

    idle();

    // sti();
    // quand on saura gerer l'ecran, on pourra afficher x
    // (void)x;
    // on ne doit jamais sortir de kernel_start
    /* while (1) {
        // cette fonction arrete le processeur
        hlt();
    } */
}

