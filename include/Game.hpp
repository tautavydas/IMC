#pragma once

#include <iostream>
#include <unordered_map>
#include <functional>

class Game final {
 private:
  std::string const actions{"prs"};
  std::unordered_map<char, std::string const> names {
    {actions[0], "Paper"   },
    {actions[1], "Rock"    },
    {actions[2], "Scissors"}
  };
  std::unordered_map<char, std::unordered_map<char, std::function<std::string()>>> game {
    {actions[0], {{actions[0], [this]() -> std::string {return Draw();      }},
                  {actions[1], [this]() -> std::string {return PlayerWins();}},
                  {actions[2], [this]() -> std::string {return CPUWins();   }}}},
    {actions[1], {{actions[0], [this]() -> std::string {return CPUWins();   }},
                  {actions[1], [this]() -> std::string {return Draw();      }},
                  {actions[2], [this]() -> std::string {return PlayerWins();}}}},
    {actions[2], {{actions[0], [this]() -> std::string {return PlayerWins();}},
                  {actions[1], [this]() -> std::string {return CPUWins();   }},
                  {actions[2], [this]() -> std::string {return Draw();      }}}}
  };

  std::string message;

 public:
  size_t Draws{0}, CPU_wins{0}, Player_wins{0};

  explicit Game() {
    srand(time(0));
  }

  [[nodiscard]] std::string Usage() noexcept {
    std::string ret{""};
    for(char const& c : actions)
      ret+="\'" + std::string{c} + "\' - " + names[c] + "\n";

    return ret;
  }

  bool Play(char const& player_action, char const& computer_action) noexcept {
    auto const iter1{game.find(player_action)};
    if (iter1 != game.end()) {
      auto const iter2{iter1->second.find(computer_action)};
      if (iter2 != iter1->second.end()) {
        message = "You : " + names[iter1->first] + "\tCPU : " + names[iter2->first] + "\t--->\t" + iter2->second();
        return true;
      }
    }
    message = "Map key not found";
    return false;
  }

  [[nodiscard]] char ComputerInput() const noexcept {
    return actions[rand() % actions.length()];
  }

  [[nodiscard]] std::string const& DisplayMessage() const noexcept {
    return message;
  };

  [[nodiscard]] std::string DisplayScore() const noexcept {
    return "Player wins\tComputer wins\tDraws\n" + std::to_string(Player_wins) + "\t\t" + std::to_string(CPU_wins) + "\t\t" + std::to_string(Draws);
  }

 private:
  [[nodiscard]] std::string Draw() noexcept {
    Draws++;
    return "Draw";
  }

  [[nodiscard]] std::string PlayerWins() noexcept {
    Player_wins++;
    return "You win";
  }

  [[nodiscard]] std::string CPUWins() noexcept {
    CPU_wins++;
    return "CPU wins";
  }
};
