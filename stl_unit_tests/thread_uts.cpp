#include <iostream> 

#include <vector>

#include <thread>
#include <mutex>
#include <atomic>

std::mutex mtx;

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void thread_func(int v, char c) {
  mtx.lock();
  
  for(int i = 0; i < v; i++)
    std::cout << c;
  std::cout << std::endl;

  mtx.unlock();
}

void thread_examples(void) {
  std::cout << "  test 1:  creating threads..." << std::endl;
  std::thread t1(thread_func, 2, 'a');
  std::thread t2(thread_func, 3, 'b');

  std::cout << "  test 2:  syncronizing threads... " << std::endl;
  t1.join();
  t2.join();
}

void count1m (int id) {
  while(!ready)
    std::this_thread::yield();                 // wait for the ready signal
  
  for(volatile int i = 0; i < 1000000; ++i) {} // go!, count to 1 million
  
  if(!winner.test_and_set()) 
    std::cout << "    thread #" << id << " won!\n";
}

void atomic_examples(void) {
  std::vector<std::thread> threads;

  std::cout << "  test 1:" << std::endl;
  std::cout << "    spawning 10 threads that count to 1 million..." << std::endl;
  
  for(int i = 1; i <= 10; i++)
    threads.push_back(std::thread(count1m, i));
  
  ready = true;
  for (auto& th : threads) th.join();
}
