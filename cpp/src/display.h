#include <iostream>
#include <string>
#include <vector>
#ifndef DISPLAY_H
#define DISPLAY_H

std::string print_vec(const std::vector<int> &iv) {
  std::string fmt;
  for (int i : iv) {
    fmt += std::to_string(i) + " ";
  }
  fmt.push_back('\n');
  return fmt;
}

std::string print_matrix(const std::vector<std::vector<int>> &im) {
  std::string fmt;
  for (auto iv : im) {
    fmt += print_vec(iv);
  }
  return fmt;
}

#endif // !DISPLAY_H
