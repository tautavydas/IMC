#pragma once

#include <iostream>
#include <unordered_map>
#include <functional>

class Game {
 private:
  std::string const actions{"prs"};
  std::unordered_map<char, std::string const> names {
          {actions[0], "Paper"   },
          {actions[1], "Rock"    },
          {actions[2], "Scissors"}
  };
  std::unordered_map<char, std::unordered_map<char, std::function<void()>>> game {
    {actions[0], {{actions[0], [this]() -> void {Draw();      }},
                  {actions[1], [this]() -> void {PlayerWins();}},
                  {actions[2], [this]() -> void {CPUWins();   }}}},
    {actions[1], {{actions[0], [this]() -> void {CPUWins();   }},
                  {actions[1], [this]() -> void {Draw();      }},
                  {actions[2], [this]() -> void {PlayerWins();}}}},
    {actions[2], {{actions[0], [this]() -> void {PlayerWins();}},
                  {actions[1], [this]() -> void {CPUWins();   }},
                  {actions[2], [this]() -> void {Draw();      }}}}
  };

 public:
  size_t Draws{0}, CPU_wins{0}, Player_wins{0};

  Game() {
    srand(time(0));
  }

  std::string Usage() {
    std::string ret{""};
    for(char const& c : actions)
      ret+="\'" + std::string{c} + "\' - " + names[c] + "\n";

    return ret;
  }

  bool Play(char const player_action, char const computer_action) {
    auto const iter1{game.find(player_action)};
    if (iter1 != game.end()) {
      auto const iter2{iter1->second.find(computer_action)};
      if (iter2 != iter1->second.end()) {
        std::cout << "You : " << names[iter1->first] << "\tCPU : " << names[iter2->first] << "\t--->\t";
        iter2->second();
        std::cout << std::endl;
        return true;
      } else std::cout << "Map key not found" << std::endl;
    }
    return false;
  }

  char ComputerInput() const {
    return actions[rand() % actions.length()];
  }

  std::string DisplayScore() const {
    return "Player wins\tComputer wins\tDraws\n" + std::to_string(Player_wins) + "\t\t" + std::to_string(CPU_wins) + "\t\t" + std::to_string(Draws);
  }

 private:
  void Draw() {
    std::cout << "Draw";
    Draws++;
  }

  void PlayerWins() {
    std::cout << "You win" ;
    Player_wins++;
  }

  void CPUWins() {
    std::cout << "CPU wins";
    CPU_wins++;
  }
};
