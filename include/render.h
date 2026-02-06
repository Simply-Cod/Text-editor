#pragma once
#include "buffer.h"
#include "bufferInfo.h"
#include <stdbool.h>

typedef struct Vector2{
    int x;
    int y;
}Vector2;

typedef struct ViewPort {
    int height;
    int topLine;
    int oldTopLine;
    int cursorRow;
    int cursorCol;
}ViewPort;

typedef enum {
    HL_NORMAL,
    HL_COMMENT,
    HL_STRING,
    HL_NUMBER,
}Highlight;

#define CLR_RESET "\x1b[0m"
#define CLR_DATA "\x1b[34m"
#define CLR_COMMENT "\x1b[38;5;60m"
#define CLR_STRING "\x1b[32m"
#define CLR_NUMBER "\x1b[31m"


Vector2 renderGetTerminalSize();


int renderDraw(Buffer *buffer, LineBuffer *currentLine, BufferInfo *bInfo, ViewPort *ViewPort);


void parseCHighlight(LineBuffer *line, Highlight *hl);
void printHlLine(LineBuffer *line);
