#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef EMSCRIPTEN_KEEPALIVE
#include <emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include "ihex/kk_ihex_write.h"

static char output[65535];
static unsigned int output_position = 0;

char *
EMSCRIPTEN_KEEPALIVE
strtoihex (char *buffer) {
    struct ihex_state ihex;
    ihex_address_t initial_address = 0;
    ihex_count_t count = strlen(buffer);

    output_position = 0;

    ihex_init(&ihex);
    ihex_write_at_address(&ihex, initial_address);

    ihex_write_bytes(&ihex, buffer, count);
    ihex_end_write(&ihex);

    return output;
}

#pragma clang diagnostic ignored "-Wunused-parameter"

void
EMSCRIPTEN_KEEPALIVE
ihex_flush_buffer(struct ihex_state *ihex, char *buffer, char *eptr) {
    *eptr = '\0';
    strcpy(&output[output_position], buffer);
    output_position += strlen(buffer);
}
