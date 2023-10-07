# c-playground

📚 Learning and exploring the C programming language.

> C is a general-purpose computer programming language. It was created in the 1970s by Dennis Ritchie, and remains very
> widely used and influential.
>
> -- <cite> https://en.wikipedia.org/wiki/C_(programming_language) </cite>


## Overview

I've been avoiding re-learning C since I learned it briefly in college. I need to learn at least a bit. This project is
me doing that.

**NOTE**: This project was developed on macOS. It is for my own personal use.


## Standalone subprojects

This repository illustrates different concepts, patterns and examples via standalone subprojects. Each subproject is
completely independent of the others and do not depend on the root project. This _standalone subproject constraint_
forces the subprojects to be complete and maximizes the reader's chances of successfully running, understanding, and
re-using the code.

The subprojects include:

### `simple/`

This is a "hello world"-style program for experienced programmers who are new to C.

See the README in [simple/](simple/).

### `cmake-with-external-library/`

An example C project that uses CMake and consumes an external library.

See the README in [cmake-with-external-library/](cmake-with-external-library/).


## Wish List

General clean-ups, TODOs and things I wish to implement for this project:

* [x] DONE Create a subproject that uses a Makefile to build the project. I only ever wanted to execute `clang` commands
  directly in my start project (`simple/`) but now I want to do it the faster way. I think I'm going to use CMake and
  consume the popular [CRoaring](https://github.com/RoaringBitmap/CRoaring) bitmap library.
