# cmake-with-external-library

An example C project that uses CMake and consumes an external library.


## Overview

My aim with this repository is to be a minimal working example of a C project beyond a simple "hello world"-style
example project. In a "hello world"-style project, we would invoke the C compiler directly but in a real-world project,
we want to lean on build tooling like CMake to help us download dependencies, configure builds, and execute builds. In
fact, a given project can have many "depends on" relationships when it comes to downloading, configuring, and building
other parts of the overall software system. These relationships form a directed acyclic graph (DAG) of dependencies.
CMake wires up the DAG for us! 

Specifically, the `cmake-with-external-library` project expresses a demo C program that uses CMake to download and
statically link with an external library: the C implementation of Roaring bitmaps called [CRoaring](https://github.com/RoaringBitmap/CRoaring).

Of note is that we are "statically linking" the CRoaring library into our demo program. I'm curious how the configuration
would differ if we were to dynamically link the CRoaring library into our program.


## Instructions

Follow these instructions to build and run the project.

1. Configure the build system
   * ```shell
     cmake -B build .
     ```
   * Peek at the content in `build/` and make sense of it.
2. Build the project
    * ```shell
      cmake --build build
      ```
3. Run the program
    * ```shell
      ./build/demo
      ```
    * It should look something like the following.
    * ```text
      $ ./build/demo
      'On' bits: {1,20,50,300,1000}
      Cardinality = 5
      Size in bytes = 26
      ```


## Reference

* [GitHub repository: `RoaringBitmap/CRoaring`](https://github.com/RoaringBitmap/CRoaring)
