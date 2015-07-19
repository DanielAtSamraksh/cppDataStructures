/// Circular array acting as a buffer
#include <std::queue>
#include<cassert>
#include<iostream>

template <typename T> struct Q {
private:
  std::queue<T> q;
public:
  unsigned size() { return q.size(); };
  bool empty() { return q.empty(); };
  bool top() { return q.top(); };
  void enq(T x) { q.push(x); };
  T deq() { assert(!q.empty()); T x = q.front(); q.pop(); return x; };
};
