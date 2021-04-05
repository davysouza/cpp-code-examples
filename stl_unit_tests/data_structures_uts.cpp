#include <iostream>

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tuple>
#include <bitset>

void vector_examples(void) {
  std::vector<int> my_vector;
  my_vector.push_back(2);
  my_vector.push_back(3);
  my_vector.push_back(5);

  // printing
  std::cout << "  test 1: my_vector: ";
  for(auto v : my_vector)
    std::cout << v << " ";
  std::cout << std::endl;

  // index
  std::cout << "  test 2: idx[0]: " << my_vector[0] << std::endl;
  std::cout << "  test 3: at(1): " << my_vector.at(1) << std::endl;
}

void list_examples(void) {
  int values[5] = {2, 3, 7, 8, 11};
  std::list<int> my_list(values, values + sizeof(values) / sizeof(int));
  
  // printing
  std::cout << "  test 1: my_list: ";
  for(auto v : my_list)
    std::cout << v << " ";
  std::cout << std::endl;

  // insert
  std::list<int>::iterator it = my_list.begin();
  it++; it++;
  my_list.insert(it, 5);
  std::cout << "  test 2:  insert: ";
  for(auto v : my_list)
    std::cout << v << " ";
  std::cout << std::endl;

  // remove
  my_list.remove(8);
  std::cout << "  test 2:  remove: ";
  for(auto v : my_list)
    std::cout << v << " ";
  std::cout << std::endl;
}

void queue_examples(void) {
  std::queue<int> my_queue;
  my_queue.push(2);
  my_queue.push(3);
  my_queue.push(5);
  my_queue.push(7);

  std::cout << "  test 1:  my_queue: ";
  while(!my_queue.empty()) {
    int v = my_queue.front();
    my_queue.pop();
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

void stack_examples(void) {
  std::stack<int> my_stack;
  my_stack.push(2);
  my_stack.push(3);
  my_stack.push(5);
  my_stack.push(7);

  std::cout << "  test 1:  my_stack: ";
  while(!my_stack.empty()) {
    int v = my_stack.top();
    my_stack.pop();
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

void set_examples(void) {
  std::set<int> my_set;
  my_set.insert(2);
  my_set.insert(3);
  my_set.insert(5);
  my_set.insert(5);

  std::cout << "  test 1:  my_set: ";
  for(auto v : my_set)
    std::cout << v << " ";
  std::cout << std::endl;
}

void map_examples(void) {
  std::map<std::string, int> my_map;
  my_map["a"] = 2;
  my_map["b"] = 3;
  my_map["c"] = 5;

  std::cout << "  test 1:  my_map: ";
  for(auto item : my_map)
    std::cout << "[" << item.first << "]:" << item.second << " ";
  std::cout << std::endl;
}

void tuple_examples(void) {
  std::tuple<char, int, float> my_tuple = {'a', 2, 3.78};
  std::cout << "  test 1:  my_map: {";
  std::cout << std::get<0>(my_tuple) << ", ";
  std::cout << std::get<1>(my_tuple) << ", ";
  std::cout << std::get<2>(my_tuple);
  std::cout << "}" << std::endl;
}

void bitset_examples(void) {
  std::bitset<4> my_bitset;

  my_bitset[1] = 1;
  std::cout << "  test 1:  my_bitset: " << my_bitset << std::endl;
}
