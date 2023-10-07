# simple

This is a "hello world"-style program for experienced programmers who are new to C.


## Overview

This program goes beyond a prototypical "hello world"-style program because it incorporates C features like header
files, macros, and pointers. But for people already experienced in other programming languages, it's best to jump in at
this level of complexity instead of the simplest "hello world" program.

In particular, I wanted a program that is defined across multiple source code files and I wanted to know the right
compilation and linking steps to build and run the program from the command line. I find the software "build toolchain"
to always be a greater barrier to entry than the programming language itself. Let's take down those barriers early.


## Instructions

Follow these instructions to build and run a sample program.

1. Pre-requisite: Clang
    * This comes with the Xcode Command Line Tools. I can never remember the procedure to install this.
2. Compile the object code:
    * ```shell
      mkdir -p build
      clang -c -o build/swap.o swap.c
      clang -c -o build/sort.o sort.c
      ```
3. Link the object code together:
    * ```shell
      clang -o build/sort build/sort.o build/swap.o
      ```
4. Run the program
    * ```shell
      ./build/sort 3 1 2
      ```
    * Altogether, it will look like this:
      ```txt
      $ mkdir -p build
      $ clang -c -o build/swap.o swap.c
      $ clang -c -o build/sort.o sort.c
      $ clang -o build/sort build/sort.o build/swap.o
      $ ./build/sort 3 1 2
      1 2 3
      ```
    * In a normal project, you would use a Makefile to automate the build process. But for this example, it's important
      to understand the concepts.


## Notes

I'm still figuring out the common/idiomatic naming conventions. Are functions snake case?

Where do I find the C standard library documentation? I'm looking for something comprehensive and readable.


## Reference

* [Book: *Effective C: An Introduction to Professional C Programming by Robert C. Seacord*](https://nostarch.com/Effective_C)
    * Perfect book for experienced programmers that want to learn C (me!).
* [Wikipedia article: *Clang*](https://en.wikipedia.org/wiki/Clang)
    * > Clang is a compiler front end for the C, C++, Objective-C, and Objective-C++ programming languages
* [Codecademy C course](https://www.codecademy.com/catalog/language/c)
    * (UPDATE: no, this is good for beginner programmers, but I'll skip this). I think I'll try this Codecademy course to re-learn C.
