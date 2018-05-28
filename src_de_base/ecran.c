#include "ecran.h"

static uint32_t pos_x = 0;
static uint32_t pos_y = 0;
static uint8_t col_fg = CGA_COLOR_WHITE;
static uint8_t col_bg = CGA_COLOR_BLACK;

/* uint16_t *ptr_mem(uint32_t lig, uint32_t col)
{
  return ((uint16_t *)(CGA_MEM_START + 2 * (lig * CGA_CST_ROWS + col)));
} */

/* void ecrit_car(uint32_t lig, uint32_t col, char c,
  uint32_t coul_texte, uint32_t coul_fond)
{
  // NOTE: bit 7 is 0 due to bad support of blinking cursor
  *ptr_mem(lig, col) = c | (coul_texte << 8) | (coul_fond << 12);
} */

void efface_ecran(void)
{
  for (uint32_t i = 0; i < CGA_CST_ROWS; i++) {
    for (uint32_t j = 0; j < CGA_CST_COLS; j++) {
      ecrit_car(i, j, ' ', CGA_COLOR_WHITE, CGA_COLOR_BLACK);
    }
  }
}

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

void traite_car(char c) {
  switch (c) {
    case '\b':
      if (pos_x != 0) {
        pos_x--;
      }
      break;
    case '\t':
      pos_x = pos_x % 8 == 0 ? pos_x + 8 : pos_x + pos_x % 8;
      if (pos_x >= CGA_CST_COLS) {
        pos_x = CGA_CST_COLS - 1;
      }
      break;
    case '\n':
      pos_x = 0;
      pos_y = pos_y + 1;
      break;
    case '\f':
      efface_ecran();
      pos_x = 0;
      pos_y = 0;
      break;
    case '\r':
      pos_x = 0;
      break;
    default:
      // Wrapping
      if (pos_y == CGA_CST_ROWS - 1) {
        defilement();
      }
      ecrit_car(pos_y, pos_x, c, col_fg, col_bg);
      pos_x++;
  }
  place_curseur(pos_y, pos_x);
}

void defilement(void)
{
  memmove((int16_t *)CGA_MEM_START, (int16_t *)(CGA_MEM_START + 80*2), 79*25*2);
  place_curseur(--pos_y, pos_x);
  // Effacement dernière ligne
  for (uint8_t i = 0; i < CGA_CST_COLS; i++) {
    ecrit_car(CGA_CST_ROWS - 1, i, ' ', col_fg, col_bg);
  }
}

void clear(void)
{
  traite_car('\f');
}

void console_putbytes(char *chaine, int32_t taille)
{
  for (int32_t i = 0; i < taille; i++) {
    traite_car(chaine[i]);
  }
}

void write_pos(char *chaine, int32_t taille, int32_t position_y, int32_t position_x)
{
  uint32_t old_x, old_y, offset_x, offset_y;
  old_x = pos_x;
  old_y = pos_y;
  offset_x = 0;
  offset_y = 0;
  if (position_x != DISP_POS_X_LEFT) {
    offset_x = CGA_CST_COLS - taille - 1;
  }
  if (position_x == DISP_POS_X_CENTER) {
    offset_x = offset_x / 2;
  }

  if (position_y != DISP_POS_Y_TOP) {
    offset_y = CGA_CST_ROWS - 1;
  }
  if (position_y == DISP_POS_Y_CENTER) {
    offset_y = offset_y / 2;
  }

  pos_x = offset_x;
  pos_y = offset_y;
  place_curseur(pos_y, pos_x);
  console_putbytes(chaine, taille);
  pos_x = old_x;
  pos_y = old_y;
  place_curseur(pos_y, pos_x);
}