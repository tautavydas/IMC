#include<Game.hpp>

int main() {
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
      std::string PlayerInput;
      std::cin >> PlayerInput;
      if (PlayerInput.length() == 1) {
        if (RockPaperScissors.Play(PlayerInput[0], RockPaperScissors.ComputerInput())) {
        } else if (PlayerInput == "d") {
          std::cout << RockPaperScissors.DisplayScore() << std::endl;
        } else if (PlayerInput == "h") {
          std::cout << Usage << std::endl;
        } else if (PlayerInput == "q") {
          std::cout << RockPaperScissors.DisplayScore() << std::endl;
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
