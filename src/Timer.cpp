#include "./Timer.hpp"

Timer::Timer(const std::string &tag) : m_tag(tag) {
  m_start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
  m_end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start);

  std::cout << colors::FBLK << '[' << m_tag << "] " << duration.count() << " ms"
            << colors::RS << '\n';
}
