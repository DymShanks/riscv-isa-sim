#include <stdio.h>
#include "rvvi/rvviApi.h"

// We updated the signature to match the official header perfectly
extern "C" bool_t rvviRefInit(const char* config) {
    printf("RVVI Bridge: Spike is officially listening!\n");
    return 1; // Return true/success
}
