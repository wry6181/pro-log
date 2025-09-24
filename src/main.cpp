#include "commands.h"
#include <iostream>
#include <vector>

std::vector<std::string> tokens;

void string_tokenaizer(std::string &text) {
  auto index = text.find_first_of(" ");
  auto first = text.substr(0, index);
  std::cout << first << '\n';
}

int main() {

  while (true) {

    std::string arg{""};
    std::cin >> arg;
    string_tokenaizer(arg);
    if (arg == "init") {
      Init i{};
      i.name = "init";
      std::cout << "added to the que\n";
      command_que.push_back(i);
    }
    if (arg == "timer") {
      Timer t{};
      t.name = "timer";
      t.duration = 2000;
      std::cout << "added to the que\n";
      command_que.push_back(t);
    }
  }
}
