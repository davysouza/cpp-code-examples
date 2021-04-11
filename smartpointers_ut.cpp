#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// 
// Smart Pointers - references:
// 
//  - https://www.geeksforgeeks.org/smart-pointers-cpp/
//  - https://www.internalpointers.com/post/move-smart-pointers-and-out-functions-modern-c
//  - https://en.wikipedia.org/wiki/Smart_pointer#shared_ptr_and_weak_ptr
// 

// unique_ptr:
// 
//  - not able of making a copy
//  - only one pointer can point this obj at one time
//  - need to use std::move
void unique_ptr_ut() {
  unique_ptr<int> ptr(new int(2));
  cout << "  ptr: " << *ptr << endl << endl;

  unique_ptr<vector<int>> vptr(new vector<int>());
  vptr->push_back(2);
  vptr->push_back(3);

  cout << "  vptr[0]: " << vptr->at(0) << endl;
  cout << "  vptr[1]: " << vptr->at(1) << endl << endl;

  // doesnt work
  // unique_ptr<vector<int>> vptr2(vptr);

  cout << "  moving..." << endl;
  unique_ptr<vector<int>> vptr2;
  vptr2 = move(vptr);

  cout << "    vptr2[0]: " << vptr2->at(0) << endl;
  cout << "    vptr2[1]: " << vptr2->at(1) << endl;
}

// shared_ptr:
// 
//  - more than one pointer can point to this one object
//  - has a counter
void shared_ptr_ut(void) {
  shared_ptr<int> ptr0(new int(7));
  shared_ptr<int> ptr1(new int(8));

  cout << "  ptr0: " << *ptr0 << endl;
  cout << "  ptr1: " << *ptr1 << endl << endl;

  shared_ptr<int> ptr2(ptr0);
  cout << "  pointing ptr2 to ptr0..." << endl;
  cout << "    ptr2: " << *ptr2 << endl << endl;

  cout << "    counter(ptr0): " << ptr0.use_count() << endl;
  cout << "    counter(ptr1): " << ptr1.use_count() << endl << endl;

  ptr2 = ptr1;
  cout << "  pointing ptr2 to ptr1..." << endl;
  cout << "    ptr2: " << *ptr2 << endl << endl;
  cout << "    counter(ptr0): " << ptr0.use_count() << endl;
  cout << "    counter(ptr1): " << ptr1.use_count() << endl;
}

// weak_ptr:
// 
//  - similar to shared_ptr but without counter
void weak_ptr_ut(void) {
  shared_ptr<int> p1 = make_shared<int>(5);
  weak_ptr<int> wp1 {p1};  // p1 owns the memory.

  {
    shared_ptr<int> p2 = wp1.lock();  // Now p1 and p2 own the memory.
    // p2 is initialized from a weak pointer, so you have to check if the
    // memory still exists!
    if (p2) {
      cout << "  ptr2: " << *p2 << endl << endl;
    }
  }
  // p2 is destroyed. Memory is owned by p1.

  p1.reset();  // Free the memory.

  shared_ptr<int> p3 = wp1.lock(); 
  // Memory is gone, so we get an empty shared_ptr.
  if (!p3) {
    cout << "  p3 is empty" << endl;
  }
}

int main(int argc, char* argv[]) {
  cout << "\n========== SMART POINTERS EXAMPLES ==========\n" << endl;

  cout << "unique_ptr..." << endl;
  unique_ptr_ut();
  cout << "...done!\n" << endl;

  cout << "shared_ptr..." << endl;
  shared_ptr_ut();
  cout << "...done!\n" << endl;

  cout << "weak_ptr..." << endl;
  weak_ptr_ut();
  cout << "...done!\n" << endl;
}
