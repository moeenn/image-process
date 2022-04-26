#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>

struct Flag {
  const char* flag;
  const char* desc;
  const char* *target;
};

class ArgsParser {
private:
  uint m_count;
  std::vector<char*> m_args;
  char* m_bin_name;
  std::vector<Flag> m_flags;
  int getFlagIndex(const char* flag);

public:
  ArgsParser(int argc, char *argv[]);
  void flag(const char* flagName, const char*, const char* *target);
  void parse();
  void printHelp();
};