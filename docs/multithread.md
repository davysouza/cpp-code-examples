# Multithreading
## Definition
The concept of **multithreading** needs proper understanding of these two terms – a **process**  and a **thread**. A process is a program being executed. A process can be further divided into independent units known as threads.

A thread is like a small light-weight process within a process. Or we can say a collection of threads is what is known as a process.

Multithreading is an ability of CPU to provide multiple threads of execution concurrently. This approach differs from multiprocessing. In a multithreaded application, the threads share the resources of a single or multiple cores.

## Advantages
 - **Cache misses**: If a thread gets a lot of cache misses, the other threads can continue taking advantage of the unused computing resources, which may lead to faster overall execution, as these resources would have been idle if only a single thread were executed
 - **Dependencies**: If a thread cannot use all the computing resources of the CPU (because instructions depend on each other's result), running another thread may prevent those resources from becoming idle.

## Disadvantages
 - **Thread interference**: Multiple threads can interfere with each other when sharing hardware resources. 
 - Difficulty wrinting code.
 - Difficulty managing concurrency.
 - Difficulty testing and debugging.

## References
 - [Multithreading](https://en.wikipedia.org/wiki/Multithreading_(computer_architecture))
 - [Multithreading in Operating System](https://www.geeksforgeeks.org/multithreading-in-operating-system/)
 - [Multithreading in C++](https://www.geeksforgeeks.org/multithreading-in-cpp/)
