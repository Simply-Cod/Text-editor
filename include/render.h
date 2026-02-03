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
    int cursorRow;
    int cursorCol;
}ViewPort;


Vector2 renderGetTerminalSize();


int renderDraw(Buffer *buffer, LineBuffer *currentLine, BufferInfo *bInfo, ViewPort *ViewPort);
