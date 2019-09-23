# Corewar

Corewar is an algorythmic project at Codam (42). The purpose of this project is an implementation of the programming game **“Core War”**.


[corewar.en.pdf](/corewar.en.pdf) is the subject.

Task resources are placed at [the `resources` folder](/sresources/).

## Wiki

This project has a guide.

You can read it [at the wiki-pages](../../wiki/).

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
    -show <num> : Run <num> cycles, dump memory (32 octets per line), pause and repeat
    -s    <num> : Run <num> cycles, dump memory (64 octets per line), pause and repeat
    -l    <num> : Log levels
                   1  : Show lives
                   2  : Show cycles
                   4  : Show operations
                   8  : Show deaths
                   16 : Show PC movements
    -v          : Run visualizer
    -n    <num> : Set <num> of the next player
```

## Visualizer

The best visualizer performance is with **iTerm2**.

![Visualizer](/wiki_resources/visualizer.png)
