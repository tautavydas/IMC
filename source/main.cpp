#include<Game.hpp>

int main() {
  srand(time(0));

  Game RockPaperScissors;

  std::string const Usage{RockPaperScissors.Usage() +
                          "\'d\' - display score\n"
                          "\'q\' - quit\n"
                          "\'h\' - help"};

  std::cout << "Let's play Paper, Rock, Scissors\nUsage:\n" << Usage << "\n>> ";
  while (true) {
    if (std::cin.peek() == '\n') {
      std::cin.ignore();
      std::cout << ">> ";
    } else {
      std::string input;
      std::cin >> input;
      if (input.length()==1) {
        if (RockPaperScissors.Play(input.c_str()[0], RockPaperScissors.ComputerAction())) {
        } else if (input == "d") {
          RockPaperScissors.DisplayScore();
        } else if (input == "h") {
          std::cout << Usage << std::endl;
        } else if (input == "q") {
          RockPaperScissors.DisplayScore();
          break;
        } else {
          std::cout << "wrong command" << std::endl;
        }
      } else {
        std::cout << "wrong command" << std::endl;
      }
    }
  }

  return EXIT_SUCCESS;
}
