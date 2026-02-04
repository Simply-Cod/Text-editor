#include "buffer.h"

void correctCursorPos(LineBuffer *line, int *prefCurPos) {
  if (*prefCurPos > line->lineLength) {

    if (line->lineLength > 0)
      line->cursorPosition = line->lineLength - 1;
    else
      line->cursorPosition = 0;
  } else {
    line->cursorPosition = *prefCurPos;
  }
  if (line->buffer[line->cursorPosition] == '\0')
    line->cursorPosition--;

  unsigned char c = line->buffer[line->cursorPosition];
  if (c >= 128 && c <= 191)
      line->cursorPosition--;
}
