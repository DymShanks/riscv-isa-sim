# Spike as an RTL Reference Model: Tandem-Mode Integration


This document outlines the methodology for utilizing Spike (riscv-isa-sim) as a Reference Model (RM) in "tandem mode" alongside a Core-Under-Verification (such as CVA6) within a SystemVerilog UVM environment.

## 1. The Bare-Metal / Tandem Concept
In tandem verification, the execution is checked cycle by cycle with a Spike golden model. Spike does not boot a full OS payload. Instead, it is executed via bare-metal code, stepping instruction-by-instruction in sync with the RTL. The architectural state of both the RTL and the RM are continuously exposed to a UVM Scoreboard for comparison.

## 2. Integration Methods

### Method A: Legacy DPI Wrapper (Current CORE-V-VERIF)
Historically, the C++ interface to Spike's internal state was not considered a public API. Verification environments handled this by building custom C++ to SV DPI wrappers that manually exposed Spike's internal `processor_t` state.

### Method B: RVVI-API Standardization (Proposed)
The RISC-V Verification Interface (RVVI) provides a standardized C-API to extract this state, eliminating the need for custom DPI wrappers. 

**Implementation Flow:**
1. **Instantiation:** The testbench instantiates the Spike core and passes the `processor_t` pointer to the RVVI bridge via `rvvi_set_spike_core`.
2. **Execution:** The UVM environment steps the Spike core matching the RTL step.
3. **State Extraction:** The UVM Scoreboard calls standardized RVVI hooks (`rvviRefPcGet`, `rvviRefGprGet`) which natively return the state from the mapped `processor_t` structure.

*(Note: RVVI bridge implementation is currently WIP in `rvvi_bridge.cc`)*
