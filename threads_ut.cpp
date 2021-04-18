#include <iostream>

#include <vector>

#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

int value;

mutex mtx;

atomic<bool> ready(false);
atomic_flag winner = ATOMIC_FLAG_INIT;

// this function uses mutex to protect the code execution and access to global 
// variable [value]
void thread_func(int v, char c) {
  mtx.lock();

  value = v;
  for(int i = 0; i < v; i++) {
    // do something amazing...
  }

  mtx.unlock();
}

void count1m (int id) {
  while(!ready)
    this_thread::yield();                 // wait for the ready signal
  
  for(volatile int i = 0; i < 1000000; ++i) {} // go!, count to 1 million
  
  if(!winner.test_and_set()) 
    cout << "    (results): thread #" << id << " won!\n";
}

// A dummy function
void foo(int Z) {
  for (int i = 0; i < Z; i++)
    cout << "    (function pointer): Thread using function pointer as callable\n";
  cout << endl;
}

// A callable object
class thread_obj {
public:
  void operator() (int x) {
    for (int i = 0; i < x; i++)
      cout << "    (function object): Thread using function object as callable\n";
    cout << endl;
  }
};

// 
// ========== main functions ==========
// 

void thread_examples(void) {
  thread t1(thread_func, 2, 'a');
  cout << "    (create thread t1): [thread_func]\n";
  
  thread t2(thread_func, 3, 'b');
  cout << "    (create thread t2): [thread_func]\n";

  t1.join();
  cout << "    (sincronizing thread): [t1]\n";

  t2.join();
  cout << "    (sincronizing thread): [t2]\n";
}

void atomic_examples(void) {
  vector<thread> threads;
  cout << "    (create a vector<thread>): [threads]\n";

  cout << "    (spawning 10 threads that count to 1 million...)" << endl;
  for(int i = 1; i <= 10; i++)
    threads.push_back(thread(count1m, i));
  
  ready = true;
  for (auto& th : threads)
    th.join();
}

// https://www.geeksforgeeks.org/multithreading-in-cpp/
void geekforgeeks_examples(void) {
  cout << "    (threads 1 and 2 and 3 operating independently)\n\n";
  
  // This thread is launched by using 
  // function pointer as callable
  thread th1(foo, 3);
  
  // This thread is launched by using
  // function object as callable
  thread th2(thread_obj(), 3);
  
  // Define a Lambda Expression
  auto f = [](int x) {
    for (int i = 0; i < x; i++)
      cout << "    (lambda expression): Thread using lambda expression as callable\n";
    cout << endl;
  };
  
  // This thread is launched by using 
  // lamda expression as callable
  thread th3(f, 3);

  // Wait for the threads to finish
  // Wait for thread t1 to finish
  th1.join();

  // Wait for thread t2 to finish
  th2.join();

  // Wait for thread t3 to finish
  th3.join();
}

int main() {
  cout << "\n========== MULTITHREADING EXAMPLES ==========\n\n";

  cout << "[thread]\n";
  thread_examples();
  cout << "\n    done!\n\n";

  cout << "[atomic]\n";
  atomic_examples();
  cout << "\n    done!\n\n";

  cout << "[geekforgeeks example]\n";
  geekforgeeks_examples();
  cout << "\n    done!\n\n";

  return 0;
}
