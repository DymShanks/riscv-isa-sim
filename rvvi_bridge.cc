#include <stdio.h>
#include <stdint.h>
#include "rvvi/rvviApi.h"

// Bring in Spike's actual internal architecture headers
#include "riscv/processor.h" 

// This pointer links our RVVI bridge to the live Spike core
processor_t* global_core = nullptr;

// --- TANDEM MODE HAND-OFF ---
// The external testbench will call this after instantiating the Spike core
extern "C" void rvvi_set_spike_core(processor_t* core) {
    global_core = core;
    printf("RVVI Bridge: Tandem core linked successfully!\n");
}

// 1. Initialization
extern "C" bool_t rvviRefInit(const char* config) {
    printf("RVVI Bridge: Initialized.\n");
    return 1;
}

// 2. Program Counter (PC) Extraction
extern "C" uint64_t rvviRefPcGet(uint32_t hartid) {
    if (global_core) {
        return global_core->get_state()->pc; 
    }
    return 0; 
}

// 3. General Purpose Register (GPR) Extraction
extern "C" uint64_t rvviRefGprGet(uint32_t hartid, uint32_t index) {
    if (global_core) {
        return global_core->get_state()->XPR[index]; 
    }
    return 0; 
}
