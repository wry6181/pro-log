#include <string>
#include <vector>

struct Command {};

struct Init : Command {
  std::string name;
};

struct Timer : Command {
  std::string name;
  double duration;
};

std::vector<Command> command_que{};
