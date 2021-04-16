#include <iostream>

#include "stl_ut/data_structure_ut.h"

using namespace std;

int main() {
  cout << "\n========== STL EXAMPLES ==========\n\n";

  cout << "[vector]\n" << endl;
  vector_examples();
  cout << "\n    done!\n\n";

  cout << "[list]\n";;
  list_examples();
  cout << "\n    done!\n\n";

  cout << "[queue]\n";;
  queue_examples();
  cout << "\n    done!\n\n";

  cout << "[stack]\n";;
  stack_examples();
  cout << "\n    done!\n\n";

  cout << "[set]\n";;
  set_examples();
  cout << "\n    done!\n\n";

  cout << "[map]\n";
  map_examples();
  cout << "\n    done!\n\n";

  cout << "[tuple]\n";
  tuple_examples();
  cout << "\n    done!\n\n";

  cout << "[bitset]\n";
  bitset_examples();
  cout << "\n    done!\n\n";

  return 0;
}
