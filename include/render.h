#pragma once
#include "buffer.h"
#include "bufferInfo.h"
#include <stdbool.h>

typedef struct Vector2{
    int x;
    int y;
}Vector2;


Vector2 renderGetTerminalSize();


int renderDraw(Buffer *buffer, LineBuffer *currentLine, BufferInfo *bInfo);
