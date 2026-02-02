#pragma once
#include <stdbool.h>

enum InputMode {
    NORMAL,
    INSERT,
};

typedef struct BufferInfo {
    unsigned int bufferLength;
    enum InputMode mode;
    bool buffIsDirty;
    bool hasFileName;
    char *fileName;
}BufferInfo;

void infoInit(BufferInfo *bInfo);
int getFileName(BufferInfo *bInfo);
