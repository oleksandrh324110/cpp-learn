#include <chrono>
#include <iostream>
#include <thread>

void profiler() {
  using namespace std::chrono;

  auto now = system_clock::now();
  static auto start = now;

  std::cout << std::fixed;
  std::cout << "now: " << duration_cast<seconds>(now.time_since_epoch()).count() << "s";
  if (now != start)
    std::cout << "; duration: " << duration_cast<milliseconds>(now - start).count() << "ms";
  std::cout << '\n';
}

int main() {
  profiler();

  using namespace std::literals::chrono_literals;

  std::this_thread::sleep_for(1s);

  profiler();
}
