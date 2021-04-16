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

// main functions

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

int main() {
  cout << "\n========== MULTITHREADING EXAMPLES ==========\n\n";

  cout << "[thread]\n";;
  thread_examples();
  cout << "\n    done!\n\n";

  cout << "[atomic]\n";;
  atomic_examples();
  cout << "\n    done!\n\n";

  return 0;
}
