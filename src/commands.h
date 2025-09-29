#include <string>
#include <vector>

struct Command {
  std::string name;
  Command(std::string name) : name(name) {}
  virtual ~Command();
};

struct Init : Command {
  Init(std::string name) : Command(name) {}
};

struct Timer : Command {
  double duration;
  Timer(std::string name, double duration)
      : Command(name), duration(duration) {}
};

std::vector<Command> command_que{};
