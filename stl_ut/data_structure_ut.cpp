#include <iostream>

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tuple>
#include <bitset>

using namespace std;

void vector_examples(void) {
  vector<int> my_vector;
  my_vector.push_back(2);
  my_vector.push_back(3);
  my_vector.push_back(5);
  cout << "    (initializes vector<int>): [my_vector]\n";
  cout << "    (add value to my_vector): [my_vector[0]=2]\n";
  cout << "    (add value to my_vector): [my_vector[1]=3]\n";
  cout << "    (add value to my_vector): [my_vector[2]=5]\n\n";

  // printing
  cout << "    (printing): [my_vector]: ";
  for(auto v : my_vector)
    cout << v << " ";
  cout << endl << endl;

  // index
  cout << "    (access through []): my_vector[0]= " << my_vector[0] << endl;
  cout << "    (access through at()): myvector.at(1)= " << my_vector.at(1) << endl;
}

void list_examples(void) {
  int values[5] = {2, 3, 7, 8, 11};
  list<int> my_list(values, values + sizeof(values) / sizeof(int));
  
  // printing
  cout << "  test 1: my_list: ";
  for(auto v : my_list)
    cout << v << " ";
  cout << endl;

  // insert
  list<int>::iterator it = my_list.begin();
  it++; it++;
  my_list.insert(it, 5);
  cout << "  test 2:  insert: ";
  for(auto v : my_list)
    cout << v << " ";
  cout << endl;

  // remove
  my_list.remove(8);
  cout << "  test 2:  remove: ";
  for(auto v : my_list)
    cout << v << " ";
  cout << endl;
}

void queue_examples(void) {
  queue<int> my_queue;
  my_queue.push(2);
  my_queue.push(3);
  my_queue.push(5);
  my_queue.push(7);

  cout << "  test 1:  my_queue: ";
  while(!my_queue.empty()) {
    int v = my_queue.front();
    my_queue.pop();
    cout << v << " ";
  }
  cout << endl;
}

void stack_examples(void) {
  stack<int> my_stack;
  my_stack.push(2);
  my_stack.push(3);
  my_stack.push(5);
  my_stack.push(7);

  cout << "  test 1:  my_stack: ";
  while(!my_stack.empty()) {
    int v = my_stack.top();
    my_stack.pop();
    cout << v << " ";
  }
  cout << endl;
}

void set_examples(void) {
  set<int> my_set;
  my_set.insert(2);
  my_set.insert(3);
  my_set.insert(5);
  my_set.insert(5);

  cout << "  test 1:  my_set: ";
  for(auto v : my_set)
    cout << v << " ";
  cout << endl;
}

void map_examples(void) {
  map<string, int> my_map;
  my_map["a"] = 2;
  my_map["b"] = 3;
  my_map["c"] = 5;

  cout << "  test 1:  my_map: ";
  for(auto item : my_map)
    cout << "[" << item.first << "]:" << item.second << " ";
  cout << endl;
}

void tuple_examples(void) {
  tuple<char, int, float> my_tuple = {'a', 2, 3.78};
  cout << "  test 1:  my_map: {";
  cout << get<0>(my_tuple) << ", ";
  cout << get<1>(my_tuple) << ", ";
  cout << get<2>(my_tuple);
  cout << "}" << endl;
}

void bitset_examples(void) {
  bitset<4> my_bitset;

  my_bitset[1] = 1;
  cout << "  test 1:  my_bitset: " << my_bitset << endl;
}
