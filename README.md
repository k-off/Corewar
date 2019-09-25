# Corewar

Corewar is an algorythmic project at Codam (42). The purpose of this project is to recode the programming game **“Core War”**.

The project was performed in a group:

the virtual machine and the 'champion' were created by [@supalarry](https://github.com/supalarry) and [@mincentvulder](https://github.com/mincentvulder)
    
the assembler, disassembler and the visualizer were my duty
    
There is [my own buggy vm](/my_buggy_vm/) included in the repo. I am working on it©️.

[SUBJECT](/COREWAR_SUBJECT.pdf)

[RESOURCES](/resources/)

[Wikipedia](https://en.wikipedia.org/wiki/Core_War)

[Championship 2018 (youtube)](https://www.youtube.com/watch?v=R-OkYyzp-DI)

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

### `assembler`

```
Usage: ./asm (champion.s)
    champion.s   — convert from assembly to bytecode
```

### `disassembler`

```
Usage: ./dasm (champion.cor)
    champion.cor — convert from bytecode to assembly
```

### `corewar`

```
Usage: ./corewar [-a (-dump) <num> [-v] [-n <num>] <champion.cor> <...>
    -a          : Print output from "aff" (Default is off)
    -dump <num> : Dump memory (64 octets per line) after <num> cycles and exit
    -v          : Run visualizer
    -n    <num> : Set <num> of the next player
    -L          : Print all the reports 'alive' to the standard output
```

### `visualizer`

```
    up/down arrows    : switch between players
    left/right arrows : switch between processes of selected player
    space             : pause/continue execution
    <                 : go to previous cycle and pause the game
    >, tab            : go to next cycle and pause the game
    To change the history depth(amount of previous cycles available to visualizer), modify the HIST_DEPTH in the visual.h
```

### `tester`

There is a simple tester included in the repo.

To run it:

```
    cd test
    sh test.sh -all
```

It will check makefile, Norminette (complinace with the internal 42 coding standards), assembler, disassembler and the vm against the outputs and behaviour of the reference files `original_asm` and `original_corewar` from the directory `test`.

** Important **

If you don't have the norminette script installed on your machine, you may want to delete or comment out lines 27-34 from the file `test.sh`.
