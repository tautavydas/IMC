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
      std::string player_input;
      std::cin >> player_input;
      if (player_input.length()==1) {
        if (RockPaperScissors.Play(player_input[0], RockPaperScissors.ComputerAction())) {
        } else if (player_input == "d") {
          RockPaperScissors.DisplayScore();
        } else if (player_input == "h") {
          std::cout << Usage << std::endl;
        } else if (player_input == "q") {
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
