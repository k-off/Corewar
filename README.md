# Corewar

Corewar is an algorythmic project at Codam (42). The purpose of this project is an implementation of the programming game **“Core War”**.

The project was performed in a group:
    the virtual machine and the 'champion' were created by @supalarry and Vincent Mulder
    the assembler, disassembler and the visualizer were my duty

[SUBJECT](/COREWAR_SUBJECT.pdf)

[RESOURCES](/resources/)

[Wikipedia](https://en.wikipedia.org/wiki/Core_War)

## Wiki

This project has a guide.

You can read it at the [wiki-pages](../../wiki/).

## Project Structure

This project consists of five parts:

* Champion
* Assembler
* Disassembler (Bonus)
* Virtual Machine
* Visualizer (Bonus, a part of the VM)

## How to clone?

If you want to clone the project, you can use the following command:

```
git clone <repository url>
```

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## Usage

### `asm`

```
Usage: ./asm (champion.s|champion.cor)
    champion.s   — from assemble to bytecode
```

### `dasm`

```
Usage: ./asm (champion.cor)
    champion.cor — from bytecode to assemble
```

### `corewar`

```
Usage: ./corewar [-a (-dump) <num> [-v] [-n <num>] <champion.cor> <...>
    -a          : Print output from "aff" (Default is off)
    -dump <num> : Dump memory (64 octets per line) after <num> cycles and exit
    -v          : Run visualizer
    -n    <num> : Set <num> of the next player
```

## Visualizer

    up/down arrows    : switch between players
    left/right arrows : switch between processes of selected player
    space             : pause/continue execution
    <                 : go to previous cycle if execution is paused
    >, tab            : go to next cycle if execution is paused

To change the history depth, modify the HIST_DEPTH in the visual.h
