#include "date.h"

uint8_t lit_CMOS(uint8_t reg)
{
  outb((CMOS_MASK | reg), CMOS_CMD);
  uint8_t r = inb(CMOS_DATA);
  uint8_t res = (r & 0x0F) + 10 * ((r & 0xF0) >> 4);
  return res;
}

void affiche_date(void)
{
  char r[CGA_CST_COLS];
  uint32_t size = sprintf(r, "%02d/%02d/%02d - %02d:%02d:%02d",
    lit_CMOS(DATE_REG_DAYOFMONTH), lit_CMOS(DATE_REG_MONTH), lit_CMOS(DATE_REG_YEAR),
    lit_CMOS(DATE_REG_HOUR), lit_CMOS(DATE_REG_MIN), lit_CMOS(DATE_REG_SEC));
  write_pos(r, size, DISP_POS_Y_TOP, DISP_POS_X_LEFT);
}

void set_rtc_freq(uint8_t d)
{
  uint8_t v;
  // Set freq
  outb(RTC_CMD_SETFREQ, RTC_CMD_PORT);
  v = inb(RTC_DATA);
  outb(RTC_CMD_SETFREQ, RTC_CMD_PORT);

  outb(((v & 0xF0) | (d & 0x0F)), RTC_DATA);

  // Set signal type
  outb(RTC_CMD_SETSIGTYPE, RTC_CMD_PORT);
  v = inb(RTC_DATA);
  outb(RTC_CMD_SETSIGTYPE, RTC_CMD_PORT);
  outb((v | 0x40), RTC_DATA);
}