#include "graphics.h"

void load_font_data(void) {
    int i;

    // load font data into the beginning 80 slots of memory
    for(i = 0; i < 80; i++) {
        memory[i] = font_data[i];
    }
}

void initialize_display(void) {
    memset(display, 0, NUM_ROWS * NUM_COLS);
}