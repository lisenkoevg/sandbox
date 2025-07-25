#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>

using namespace boost::asio;

int main() {
  std::cout << "start" << std::endl;
  io_context iocontext;
  steady_timer timer{iocontext, std::chrono::seconds{3}};
  timer.async_wait([](const boost::system::error_code &ec) {
    std::cout << "3 sec\n" << ec << "\n";
  });
  iocontext.run();
}
