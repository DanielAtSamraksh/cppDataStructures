#include<iostream>
using std::cout;

#include "q.h"

int main() {
  Q<int> q;
  q.enq(1);
  q.enq(2);
  q.enq(3);
  cout << q.deq() << "\n";
  cout << q.deq() << "\n";
  cout << q.deq() << "\n";
}
