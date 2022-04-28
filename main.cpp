#include <iostream>
#include <unordered_map>
#include <functional>

int main() {
  srand(time(0));
  size_t Draws{0}, CPU_wins{0}, Player_wins{0};

  std::string const actions{"prs"};

  std::unordered_map<char, std::string const> Names {
    {actions[0], "Paper"   },
    {actions[1], "Rock"    },
    {actions[2], "Scissors"}
  };

  std::string const usage{"\'" + std::string{actions[0]} + "\' - " + Names[actions[0]] + "\n"
                          "\'" + std::string{actions[1]} + "\' - " + Names[actions[1]] + "\n"
                          "\'" + std::string{actions[2]} + "\' - " + Names[actions[2]] + "\n"
                          "\'c\' - display score\n"
                          "\'q\' - quit\n"
                          "\'h\' - help"};

  std::unordered_map<char, std::unordered_map<char, std::function<void()>>> Game {
    {actions[0], {{actions[0], [&]() -> void { std::cout << "Draw"     << std::endl; Draws++;      }},
                  {actions[1], [&]() -> void { std::cout << "You win"  << std::endl; Player_wins++;}},
                  {actions[2], [&]() -> void { std::cout << "CPU wins" << std::endl; CPU_wins++;   }}}},
    {actions[1], {{actions[0], [&]() -> void { std::cout << "CPU wins" << std::endl; CPU_wins++;   }},
                  {actions[1], [&]() -> void { std::cout << "Draw"     << std::endl; Draws++;      }},
                  {actions[2], [&]() -> void { std::cout << "You win"  << std::endl; Player_wins++;}}}},
    {actions[2], {{actions[0], [&]() -> void { std::cout << "You win"  << std::endl; Player_wins++;}},
                  {actions[1], [&]() -> void { std::cout << "CPU wins" << std::endl; CPU_wins++;   }},
                  {actions[2], [&]() -> void { std::cout << "Draw"     << std::endl; Draws++;      }}}}
  };

  std::cout << "Let's play Paper, Rock, Scissors\nUsage:\n" << usage << std::endl;
  std::cout << ">> ";
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
          size_t const ran{rand() % actions.length()};
          auto const iter2{iter1->second.find(actions[ran])};
          if (iter2 != iter1->second.end()) {
            std::cout << "You : " << Names[iter1->first] << "\tCPU : " << Names[actions[ran]] << std::endl;
            iter2->second();
          } else std::cout << "Map key not found" << std::endl;
        } else if (input == "c") {
          std::cout << "Player wins\tComputer wins\tDraws\n" << Player_wins << "\t\t" << CPU_wins << "\t\t" << Draws << std::endl;
        } else if (input == "h") {
          std::cout << usage << std::endl;
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
