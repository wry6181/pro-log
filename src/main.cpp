#include "commands.h"
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::string> tokens;

std::pair<std::string, std::string> StringSlicer(std::string &str) {
  auto index_to = str.find_first_of(" ");
  if (index_to > str.size()) {
    return std::make_pair(str, "");
  }
  auto first_slice = str.substr(0, index_to);
  auto second_slice = str.substr(index_to, str.size());
  return std::make_pair(first_slice, second_slice);
}

void StringTokenaizer(const std::string &text) {
  if (!text.empty()) {
    auto temp = text;
    while (true) {
      auto res = StringSlicer(temp);
      tokens.push_back(res.first);
      if (res.second == "") {
        break;
      }
      temp = res.second;
    }
  }
}
int main() {

  // while (true) {

  std::string arg{""};
  std::cin >> arg;
  StringTokenaizer(arg);
  for (auto token : tokens) {
    std::cout << token << ", ";
  }
  std::cout << "\n";
  //}
}
