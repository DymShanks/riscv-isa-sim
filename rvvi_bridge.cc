#include <stdio.h>
#include <stdint.h>
#include "rvvi/rvviApi.h"

// 1. Initialization
extern "C" bool_t rvviRefInit(const char* config) {
    printf("RVVI Bridge: Spike is officially listening!\n");
    return 1;
}

// 2. Program Counter (PC) Extraction
extern "C" uint64_t rvviRefPcGet(uint32_t hartid) {
    // TODO: Hook into Spike's processor_t->get_state()->pc
    return 0x80000000; // Return dummy boot PC for now
}

// 3. General Purpose Register (GPR) Extraction
extern "C" uint64_t rvviRefGprGet(uint32_t hartid, uint32_t index) {
    // TODO: Hook into Spike's processor_t->get_state()->XPR[index]
    return 0; // Return dummy register value for now
}
