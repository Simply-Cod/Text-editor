#include "buffer.h"
#include <stdio.h>
#include <string.h>

int loadFile(Buffer *buff, char *fName) {
    FILE *file;
    file = fopen(fName, "r");

    if (file == NULL) return 0;

    LineBuffer *line = buff->head;

    while (fgets(line->buffer, sizeof(char) * MAX_LINE_LENGTH, file) != NULL) {
        line->lineLength = strlen(line->buffer);

        if (line->buffer[line->lineLength - 1] == '\n') {
            line->buffer[line->lineLength - 1] = '\0';
            line->lineLength--;
        }

        bufferAddLineBelow(buff, line);
        if (line->next != NULL) {
            line = line->next;
        }
    }
    fclose(file);

    if (line->buffer[0] == '\0') {
        line = line->previous;
        bufferDeleteLine(buff, line->next);
    }
    return 1;
}
