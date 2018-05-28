#include "temps.h"

uint32_t clk_time = 0;
uint32_t hidden_time = 0;

void tic_PIT(void)
{
  outb(0x20, 0x20);
  if (hidden_time % CLOCKFREQ == 0) {
    uint32_t h, m, s;
    char r[CGA_CST_COLS];

    hidden_time = 0;
    s = clk_time % 60;
    m = ((clk_time - s) % 3600) / 60;
    h = (clk_time - m) / 3600;
    uint32_t size = sprintf(r, "UPTIME: %02d:%02d:%02d\n", h, m, s);
    write_pos(r, size, DISP_POS_Y_TOP, DISP_POS_X_RIGHT);
    clk_time++;
  }
  hidden_time++;
}

/* void set_freq(void)
{
  outb(CLK_FREQ_SET_ENABLE_VAL, CLK_FREQ_SET_ENABLE_PORT);
  outb((QUARTZ / CLOCKFREQ) % 256, CLK_FREQ_PORT);
  outb((uint8_t)((QUARTZ / CLOCKFREQ) >> 8), CLK_FREQ_PORT);
} */