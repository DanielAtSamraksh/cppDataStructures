/// Circular array acting as a buffer

#include<cassert>
#include<iostream>

template <typename T> struct Q {
private:
  unsigned _maxSize;
  unsigned bottom; // points to the next item to be removed
  unsigned _size;
  T * q;
public:
  Q (): _maxSize(1), bottom(0), _size(0) {
    q = new T[_maxSize];
  };
  Q ( unsigned size ): _maxSize(size), bottom(0), _size(0) {
    q = new T[_maxSize];
  };
  ~Q () { delete[] q; };
  void resize ( unsigned newSize ) {
    /* std::cout << "resize ( newSize = " << newSize << ")\n"; */
    /* show(); */
    assert ( newSize >= _size ); // don't lose data
    T * newQ = new T[newSize];
    unsigned i, j;
    for ( i = bottom, j = 0; j < _size; i = ( i + 1 ) % _maxSize, j++ ) {
      newQ[j] = q[i];
      /* std::cout << "copying q[" << i << "] = " << q[i] << " to newQ[" << j << "] = " << newQ[j] << "\n"; */
    }
    delete[] q;
    bottom = 0; q = newQ; _maxSize = newSize;
    /* show(); */
    /* std::cout << "resize ( newSize = " << newSize << ") done\n\n"; */
  };
  bool empty() { return _size == 0; };
  unsigned size() { return _size; };
  bool full() { return _size >= _maxSize; }
  void enq ( T x ) {
    /* std::cout << "enq " << x << "\n"; */
    /* show(); */
    if ( full() ) {
      resize( _size? (_size * 2): 1 );
    }
    assert ( ! full() );
    q[(bottom + _size) % _maxSize] = x;
    _size++;
    /* show(); */
    /* std::cout << "enq " << x << " done\n\n"; */
  };
  T deq () {
    /* std::cout << "deq\n"; */
    /* show(); */
    assert ( ! empty() );
    unsigned oldBottom = bottom;
    bottom = ( bottom + 1 ) % _maxSize;
    _size--;
    /* show(); */
    /* std::cout << "deq done\n\n"; */
    return q[oldBottom];
  };
  /* void show() { */
  /*   std::cout */
  /*     << "Showing: " */
  /*     << "maxSize = " << _maxSize */
  /*     << ", bottom = " << bottom */
  /*     << ", size = " << size() << " = " << _size; */
  /*   assert ( size() == _size ); */
  /*   for ( unsigned i = 0; i < _size; i++ ) { */
  /*     std::cout << ", q[" << i << "] = " << q[i]; */
  /*   } */
  /*   std::cout << "\n"; */
  /* }; */
};
