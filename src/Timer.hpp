#pragma once
#include <chrono>
#include <iostream>

class Timer {
private:
  std::string m_tag;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;

public:
  Timer(const std::string& tag = "elapsed");
  ~Timer();
};