#include <iostream>

#include "stl_unit_tests/data_structures_uts.h"
#include "stl_unit_tests/thread_uts.h"

int main() {
  std::cout << "\n========== STL EXAMPLES ==========\n" << std::endl;

  std::cout << "\n========== DATA STRUCTURES ==========\n" << std::endl;

  std::cout << "std::vector..." << std::endl;
  vector_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "list..." << std::endl;
  list_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "queue..." << std::endl;
  queue_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "stack..." << std::endl;
  stack_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "set..." << std::endl;
  set_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "map..." << std::endl;
  map_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "tuple..." << std::endl;
  tuple_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "bitset..." << std::endl;
  bitset_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "\n========== THREADS ==========\n" << std::endl;

  std::cout << "thread..." << std::endl;
  thread_examples();
  std::cout << "...done!\n" << std::endl;

  std::cout << "atomic..." << std::endl;
  atomic_examples();
  std::cout << "...done!\n" << std::endl;

  return 0;
}
