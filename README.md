# 6502 Emulator

A work-in-progress MOS 6502 CPU emulator written in C.

## Status

23 of the 151 official opcodes are implemented. The CPU is built instruction by instruction by running [Klaus Dormann's 6502 functional test](github.com/Klaus2m5/6502_65C02_functional_tests) and implementing each opcode it halts on.


## What is implemented

- 64KB flat memory with binary ROM loading
- CPU core: registers, status flags, stack, reset vector
- Table-driven instruction decode (name, size in bytes, handler, base cycles)
- Instruction trace
- Implemented opcodes: `BRK` `PHP` `DEX` `DEY` `CMP #` `BEQ` `BNE` `JMP abs`
  `CLD` `LDX #` `LDY #` `LDA #` `TXS` `STA abs`

## Building and running

```
make
./bin/cpu
```

The test ROM is loaded from `roms/6502_functional_test.bin` at address `$0000`, and
execution starts at `$0400`. The CPU halts and prints the opcode when it reaches an
instruction that isn't implemented yet.

## What I learnt
Moving to a 6502 from a CHIP-8 emulator and my own simple 16-bit CPU taught me more about how real hardware behaves:
- **Real instruction sets are full of quirks.** Flag behaviour (what sets N, Z and C,
  and what doesn't, like `TXS`), little-endian operand order, and how the stack
  and branch offsets work all had to match the hardware exactly.
- **A test ROM is a better guide than the docs.** Running Klaus Dormann's functional
  test and implementing whatever it halts on gave me a clear next step each time,
  and caught bugs I'd have missed, like wrong flags and a copy-pasted zero-flag check.
- **Small design choices compound.** Using the instruction table's size field to
  advance the PC, and pulling flag-setting into helpers, removed whole classes of
  bugs that came from repeating the same code in every handler.
- **Build systems can hide bugs.** A stale object file after a header change made the
  CPU ignore its own halt flag until I did a clean rebuild.
