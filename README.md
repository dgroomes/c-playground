# c-playground

NOT YET FULLY IMPLEMENTED

📚 Learning and exploring the C programming language.

> C is a general-purpose computer programming language. It was created in the 1970s by Dennis Ritchie, and remains very
> widely used and influential.
>
> -- <cite> https://en.wikipedia.org/wiki/C_(programming_language) </cite>


## Overview

I've been avoiding re-learning C since I learned it briefly in college. I need to learn at least a bit. This project is
me doing that.

**NOTE**: This project was developed on macOS. It is for my own personal use.


## Instructions

Follow these instructions to build and run a sample program.

1. Pre-requisite: Clang
   * This comes with the Xcode Command Line Tools. I can never remember the procedure to install this. 
2. Compile the object code:
   * ```shell
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
     $ clang -o build/sort sort.c
     $ ./build/sort 3 1 2
     1 2 3
     ```


## Notes

Conveniently compile and run the C program with a shell function:

```shell
doit() {
  clang -o build/sort sort.c && ./build/sort "${@}"
}
```

Invoke it with some arguments of your choosing, like this:

```shell
doit 3 1 2
```

I'm still figuring out the common/idiomatic naming conventions. Are functions snake case?

Where do I find the C standard library documentation? I'm looking for something comprehensive and readable.

## Reference

* [Book: *Effective C: An Introduction to Professional C Programming by Robert C. Seacord*](https://nostarch.com/Effective_C)
  * Perfect book for experienced programmers that want to learn C (me!).
* [Wikipedia article: *Clang*](https://en.wikipedia.org/wiki/Clang)
  * > Clang is a compiler front end for the C, C++, Objective-C, and Objective-C++ programming languages
* [Codecademy C course](https://www.codecademy.com/catalog/language/c)
  * (UPDATE: no, this is good for beginner programmers but I'll skip this). I think I'll try this Codecademy course to re-learn C.