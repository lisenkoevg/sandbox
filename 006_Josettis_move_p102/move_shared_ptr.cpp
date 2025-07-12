#include <iostream>
#include <memory>

class SharedInt {
private:
  std::shared_ptr<int> sp;

public:
  explicit SharedInt(int val) : sp{std::make_shared<int>(val)} {}
  std::string asString() const { return sp ? std::to_string(*sp) : "not defined"; }
};

int main() {
  SharedInt s11{42};
  std::cout << s11.asString() << '\n';

  SharedInt s12{std::move(s11)};
  std::cout << s12.asString() << '\n';

  std::cout << s11.asString() << '\n';
}
