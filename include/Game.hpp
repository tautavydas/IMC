#pragma once

#include <iostream>
#include <unordered_map>
#include <functional>

class Game {
 private:
  std::string const Actions{"prs"};
  std::unordered_map<char, std::string const> names {
          {Actions[0], "Paper"   },
          {Actions[1], "Rock"    },
          {Actions[2], "Scissors"}
  };
  std::unordered_map<char, std::unordered_map<char, std::function<void()>>> game {
    {Actions[0], {{Actions[0], [this]() -> void {Draw();      }},
                  {Actions[1], [this]() -> void {PlayerWins();}},
                  {Actions[2], [this]() -> void {CPUWins();   }}}},
    {Actions[1], {{Actions[0], [this]() -> void {CPUWins();   }},
                  {Actions[1], [this]() -> void {Draw();      }},
                  {Actions[2], [this]() -> void {PlayerWins();}}}},
    {Actions[2], {{Actions[0], [this]() -> void {PlayerWins();}},
                  {Actions[1], [this]() -> void {CPUWins();   }},
                  {Actions[2], [this]() -> void {Draw();      }}}}
  };

 public:
  size_t Draws{0}, CPU_wins{0}, Player_wins{0};
  Game() {
    srand(time(0));
  }

  std::string Usage() {
    std::string ret{""};
    for(char const& c : Actions) {
      ret+="\'" + std::string{c} + "\' - " + names[c] + "\n";
    }
    return ret;
  }

  bool Play(char const player_action, char const computer_action) {
    auto const iter1{game.find(player_action)};
    if (iter1!=game.end()) {
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

  char ComputerAction() const {
    return Actions[rand() % Actions.length()];
  }

  void DisplayScore() const {
    std::cout << "Player wins\tComputer wins\tDraws\n" << Player_wins << "\t\t" << CPU_wins << "\t\t" << Draws << std::endl;
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
