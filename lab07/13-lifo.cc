// Compile with:
// g++ -Wall -o 13-lifo 13-lifo.cc

#include <iostream>

class LIFO {

  public:

    typedef       char   value_type;

    typedef       char * pointer;
    typedef const char * const_pointer;

    typedef       char & reference;
    typedef const char & const_reference;

    typedef       char * iterator;
    typedef const char * const_iterator;

    typedef size_t       size_type;

  private:

    size_type stack_size;
    size_type stack_capacity;
    pointer   stack_data;

  public:

    LIFO(size_type cap = 100); // default constructor
    LIFO(const LIFO & lifo);   // copy constructor
   ~LIFO();                    // destructor

    LIFO & operator = (const LIFO & lifo); // assignment operator

    // The most important interface methods are push() and pop(). These provide
    // core functionality of the class.

    void       push(const_reference c);
    value_type pop();

    // We must provide status information with empty() and full().

    // We can check if the LIFO is empty.
    bool empty() const {
      return(stack_size == 0 ? true : false);
    }
    /*
    if (stack_size == 0){
        return true;
    }
    else {
        return false;
    }
    */

    // We can check if the LIFO is full.
    bool full() const {
      return(stack_size == stack_capacity ? true : false);
    }

    // We define other useful methods to make life easier.

    // We can examine the topmost element.
    const_reference top() const;

    // This method gives the size of the LIFO (number of data elements stored).
    size_type size() const {
      return(stack_size);
    }

    // This method gives the capacity of the LIFO (maximum number of data
    // elements that can be stored in the stack).
    size_type capacity() const {
      return(stack_capacity);
    }

    // With this operator[] we can see what is inside our LIFO.
    // It is defined const as we may not modify elements in the stack.
    const_reference operator [] (size_type n) const {
      return(stack_data[n]);
    }

    // This method gives a pointer to the first element in the stack.
    const_iterator begin() const {
      return(stack_data);
    }

    // The result of this method points to the element after the last one in the stack.
    const_iterator end() const {
      return(stack_data+stack_size);
    }

    // Now that we have begin() and end() we do not need the friend declaration any more.
    // friend std::ostream & operator << (std::ostream & s, const LIFO & lifo);
};

LIFO::LIFO(LIFO::size_type cap) :
stack_size     (0  ),
stack_capacity (cap),
stack_data     (new value_type [stack_capacity]) {
}

LIFO::LIFO(const LIFO & lifo) :
stack_size     (lifo.stack_size                ),
stack_capacity (lifo.stack_capacity            ),
stack_data     (new value_type [stack_capacity]) {
  for (size_type i = 0; i < stack_size; i++) {
    stack_data[i] = lifo.stack_data[i];
  }
}

LIFO::~LIFO() {
  if (stack_data) {
    delete [] stack_data;
  }
}

LIFO & LIFO::operator = (const LIFO & lifo) {
  stack_size = lifo.stack_size;
  if (stack_capacity != lifo.stack_capacity) {
    if (stack_data) {
      delete [] stack_data;
    }
    stack_capacity = lifo.stack_capacity;
    stack_data     = new value_type [stack_capacity];
    if (!stack_data) {
      // this is the place of error handling
    }
  }
  for (size_type i = 0; i < stack_size; i++) {
    stack_data[i] = lifo.stack_data[i];
  }
  return(*this);
}

void LIFO::push(LIFO::const_reference c) {
  if (stack_size < stack_capacity) {
    stack_data[stack_size++] = c;
  }
  else {
    // this is the place of error handling
  }
}

LIFO::value_type LIFO::pop() {
  if (stack_size > 0) {
    return(stack_data[--stack_size]);
  }
  else {
    // this is the place of error handling
  }
  return(0);
}

// 8 4 3 5 6
LIFO::const_reference LIFO::top() const {
  // When LIFO is empty and we want to return something, we need a static
  // local variable as the result (because of the reference).
  static value_type dummy = 0;
  if (stack_size > 0) {
    return(stack_data[stack_size-1]);
  }
  else {
    // this is the place of error handling
  }
  return(dummy);
}

std::ostream & operator << (std::ostream & s, const LIFO & lifo) {
  s << "LIFO(" << lifo.size() << "," << lifo.capacity() << ")[";
  for (LIFO::const_iterator p = lifo.begin(); p != lifo.end(); p++) {
    s << (p == lifo.begin() ? "" : ",") << *p;
  }
  s << "]";
  return(s);
}

int main(int argc, char **argv) {

  LIFO stack;

  for (int i = 0; i < argc; i++) {
    std::cout << "i=" << i << std::endl;
    for (char *c = argv[i]; *c; c++) {
      std::cout << *c;
      stack.push(*c);
    }
    std::cout << std::endl;
    if (i < argc-1) {
      stack.push(' ');
    }
  }

  std::cout << stack << "\n";

  do {
    std::cout << stack.pop();
  } while (!stack.empty());

  std::cout << "\n";
  std::cout << stack << "\n";

  return(0);
}
