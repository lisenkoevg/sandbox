/*
  Experiments for book Josuttis C++ Move Semantics
  p.49, Figure 3.1. Rules for automatic generation of special member functions
*/

#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::initializer_list;
using std::string;

class A {};

class B {
public:
  std::string s;
  B() = delete;
  B(initializer_list<string>) = delete;
  //   B(B&&) = default;
  //   ~B() = default;
private:
//   int i;
};

int main() {
  //   A a1{}, a2{};
  //   cout << "sizeof(a) = " << sizeof(A) << endl;
  //   cout << "address of a1: " << static_cast<void *>(&a1) << endl;
  //   cout << "address of a2: " << static_cast<void *>(&a2) << endl;
  B b{};
  //   cout << "address of b: " << static_cast<void *>(&b) << endl;
  //   cout << "address of b.s: " << static_cast<void *>(&b.s) << endl;
  //   for (int i = 0; i != 3; ++i) {
  //     b.s.push_back('A');
  //     cout << i << ". address of b.s[0]: " << static_cast<void *>(&b.s[0])
  //       << ", capacity: " << b.s.capacity() << endl;
  //   }
  //   B b2{b};
  //   cout << "address of b2.s[0]: " << static_cast<void *>(&b2.s[0]) << endl;
  //
  //   B b3{std::move(b)};
  //   cout << "address of b3.s[0] after move from b: " << static_cast<void
  //   *>(&b3.s[0]) << endl; cout << "value of b.s after moving from: '" << b.s
  //   << "'" << endl;
}
