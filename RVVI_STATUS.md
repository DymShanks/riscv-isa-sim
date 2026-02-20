# RVVI-API Integration for Spike (WIP)

This branch contains the Work In Progress (WIP) for bridging the RISC-V Verification Interface (RVVI) into the Spike ISA simulator.

## Current Progress
- Successfully imported and linked the official `rvviApi.h` headers.
- Validated strict C-API function signatures for `rvviRefInit`.
- **[NEW]** Mapped the architectural state extraction hooks (`rvviRefPcGet` and `rvviRefGprGet`) directly to Spike's internal `processor_t->get_state()` structure.

## Immediate Next Steps (Blockers)
1. **Build System Integration:** Wire `rvvi_bridge.cc` into Spike's autotools/Makefile build system so it correctly resolves the internal `riscv/processor.h` headers and configuration macros.
2. **Core Initialization:** Identify the correct location in Spike's boot sequence (e.g., inside `sim_t`) to initialize the `global_core` pointer.
