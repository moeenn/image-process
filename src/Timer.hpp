#pragma once
#include <chrono>
#include <iostream>

class Timer {
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;

public:
  Timer();
  ~Timer();
};