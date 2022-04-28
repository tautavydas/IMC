#include <iostream>
#include <unordered_map>
#include <functional>

int main() {
  srand(time(0));
  size_t Draws{0}, CPU_wins{0}, Player_wins{0};

  std::string const Actions{"prs"};

  std::unordered_map<char, std::string const> Names {
    {Actions[0], "Paper"   },
    {Actions[1], "Rock"    },
    {Actions[2], "Scissors"}
  };

  std::string const Usage{"\'" + std::string{Actions[0]} + "\' - " + Names[Actions[0]] + "\n"
                          "\'" + std::string{Actions[1]} + "\' - " + Names[Actions[1]] + "\n"
                          "\'" + std::string{Actions[2]} + "\' - " + Names[Actions[2]] + "\n"
                          "\'c\' - display score\n"
                          "\'q\' - quit\n"
                          "\'h\' - help"};

  std::unordered_map<char, std::unordered_map<char, std::function<void()>>> Game {
    {Actions[0], {{Actions[0], [&]() -> void {std::cout << "Draw"     << std::endl; Draws++;      }},
                  {Actions[1], [&]() -> void {std::cout << "You win"  << std::endl; Player_wins++;}},
                  {Actions[2], [&]() -> void {std::cout << "CPU wins" << std::endl; CPU_wins++;   }}}},
    {Actions[1], {{Actions[0], [&]() -> void {std::cout << "CPU wins" << std::endl; CPU_wins++;   }},
                  {Actions[1], [&]() -> void {std::cout << "Draw"     << std::endl; Draws++;      }},
                  {Actions[2], [&]() -> void {std::cout << "You win"  << std::endl; Player_wins++;}}}},
    {Actions[2], {{Actions[0], [&]() -> void {std::cout << "You win"  << std::endl; Player_wins++;}},
                  {Actions[1], [&]() -> void {std::cout << "CPU wins" << std::endl; CPU_wins++;   }},
                  {Actions[2], [&]() -> void {std::cout << "Draw"     << std::endl; Draws++;      }}}}
  };

  std::cout << "Let's play Paper, Rock, Scissors\nUsage:\n" << Usage << "\n>> ";
  while (true) {
    if (std::cin.peek() == '\n') {
      std::cin.ignore();
      std::cout << ">> ";
    } else {
      std::string input;
      std::cin >> input;
      if (input.length()==1) {
        auto const iter1{Game.find(input.c_str()[0])};
        if (iter1!=Game.end()) {
          auto const iter2{iter1->second.find(Actions[rand() % Actions.length()])};
          if (iter2 != iter1->second.end()) {
            std::cout << "You : " << Names[iter1->first] << "\tCPU : " << Names[iter2->first] << std::endl;
            iter2->second();
          } else std::cout << "Map key not found" << std::endl;
        } else if (input == "c") {
          std::cout << "Player wins\tComputer wins\tDraws\n" << Player_wins << "\t\t" << CPU_wins << "\t\t" << Draws << std::endl;
        } else if (input == "h") {
          std::cout << Usage << std::endl;
        } else if (input == "q") {
          std::cout << "Player wins\tComputer wins\tDraws\n" << Player_wins << "\t\t" << CPU_wins << "\t\t" << Draws << std::endl;
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
