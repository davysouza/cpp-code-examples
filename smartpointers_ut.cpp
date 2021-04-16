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
  cout << "    (initializes a unique_ptr<int>): [*ptr=" << *ptr << "]\n\n";

  unique_ptr<vector<int>> vptr(new vector<int>());
  cout << "    (initializes a unique_ptr<vector<int>>): [vptr]\n";

  vptr->push_back(2);
  cout << "    (insert value[2] into vptr): [vptr[0]=" << vptr->at(0) << "]\n";
  
  vptr->push_back(3);
  cout << "    (insert value[3] into vptr): [vptr[1]=" << vptr->at(1) << "]\n\n";
  
  // doesnt work
  // unique_ptr<vector<int>> vptr2(vptr);

  unique_ptr<vector<int>> vptr2;
  cout << "    (initializes a unique_ptr<vector<int>>): [vptr2]\n";
  
  vptr2 = move(vptr);
  cout << "    (moves [vptr] to [vptr2])\n";

  cout << "    (print): [vptr2[0]=" << vptr2->at(0) << "]\n";
  cout << "    (print): [vptr2[1]=" << vptr2->at(1) << "]\n";
}

// shared_ptr:
// 
//  - more than one pointer can point to this one object
//  - has a counter
void shared_ptr_ut(void) {
  shared_ptr<int> ptr0(new int(7));
  cout << "    (initializes shared_ptr<int>): [ptr0=" << *ptr0 << "]\n";
  
  shared_ptr<int> ptr1(new int(8));
  cout << "    (initializes shared_ptr<int>): [ptr1=" << *ptr1 << "]\n\n";

  shared_ptr<int> ptr2(ptr0);
  cout << "    (initializes shared_ptr<int>): [ptr2=ptr0=" << *ptr2 << "]\n\n";
  cout << "    (counter): [ptr0=" << ptr0.use_count() << "]\n";
  cout << "    (counter): [ptr1=" << ptr1.use_count() << "]\n\n";

  ptr2 = ptr1;
  cout << "    (points ptr2 to ptr1): [ptr2=ptr1=" << *ptr2 << "]\n";
  cout << "    (counter): [ptr0=" << ptr0.use_count() << "]\n";
  cout << "    (counter): [ptr1=" << ptr1.use_count() << "]\n\n";
}

// weak_ptr:
// 
//  - similar to shared_ptr but without counter
void weak_ptr_ut(void) {
  shared_ptr<int> ptr1 = make_shared<int>(5);
  cout << "    (initializes shared_ptr<int>): [ptr1=" << *ptr1 << "]\n";

  weak_ptr<int> wptr1 {ptr1};  // p1 owns the memory.
  cout << "    (initializes weak_ptr<int>): [wptr1=ptr1]\n";

  {
    cout << "\n    (new context)\n";
    
    shared_ptr<int> ptr2 = wptr1.lock();  // Now p1 and p2 own the memory.
    // p2 is initialized from a weak pointer, so you have to check if the
    // memory still exists!
    if (ptr2) {
      cout << "        (initializes shared_ptr<int>): [ptr2=wptr1=" << *ptr2 << "]\n";
      cout << "        (counter): [ptr1=" << ptr1.use_count() << "]\n";
    }
    cout << "    (end context)\n\n";
  }
  // p2 is destroyed. Memory is owned by p1.
  cout << "    (counter): [ptr1=" << ptr1.use_count() << "]\n\n";

  ptr1.reset();  // Free the memory.
  cout << "    (releases ptr1)\n";

  shared_ptr<int> ptr3 = wptr1.lock(); 
  // Memory is gone, so we get an empty shared_ptr.
  if (!ptr3) {
  cout << "    (initializes shared_ptr<int>): [ptr3=wptr1=null]\n";
  }
}

int main(int argc, char* argv[]) {
  cout << "\n========== SMART POINTERS EXAMPLES ==========\n\n";

  cout << "[unique_ptr]\n";
  unique_ptr_ut();
  cout << "\n    done!\n\n";

  cout << "[shared_ptr]\n";
  shared_ptr_ut();
  cout << "\n    done!\n\n";

  cout << "[weak_ptr]\n";
  weak_ptr_ut();
  cout << "\n    done!\n";
}
