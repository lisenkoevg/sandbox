#include <iostream>
#include <utility>
#include <vector>
#include <string>

using Coll = std::vector<std::string>;

void bar(Coll &&);
void foo(Coll &&arg) {
  Coll coll;
  bar(std::move(arg));
}

void bar(Coll &&arg) {
  Coll coll = arg;
}

int main() {
  Coll v;
  const Coll c;

  foo(std::move(v));
}
