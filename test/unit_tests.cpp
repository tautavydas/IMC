#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE

#include<boost/test/unit_test.hpp>
#include<Game.hpp>

BOOST_AUTO_TEST_SUITE(Tests)

  BOOST_AUTO_TEST_CASE(Test_Inputs) {
    Game RockPaperScissors;

    BOOST_CHECK_EQUAL(RockPaperScissors.Play('p', RockPaperScissors.ComputerInput()), true);
    BOOST_CHECK_EQUAL(RockPaperScissors.Play('r', RockPaperScissors.ComputerInput()), true);
    BOOST_CHECK_EQUAL(RockPaperScissors.Play('s', RockPaperScissors.ComputerInput()), true);
    BOOST_CHECK_EQUAL(RockPaperScissors.Play('P', RockPaperScissors.ComputerInput()), false);
    BOOST_CHECK_EQUAL(RockPaperScissors.Play('R', RockPaperScissors.ComputerInput()), false);
    BOOST_CHECK_EQUAL(RockPaperScissors.Play('S', RockPaperScissors.ComputerInput()), false);
    BOOST_CHECK_EQUAL(RockPaperScissors.Play('q', RockPaperScissors.ComputerInput()), false);
  }

  BOOST_AUTO_TEST_CASE(Test_Logic) {
    Game RockPaperScissors;

    RockPaperScissors.Play('p', 'p');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 1);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 0);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 0);

    RockPaperScissors.Play('p', 'r');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 1);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 0);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 1);

    RockPaperScissors.Play('p', 's');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 1);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 1);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 1);

    RockPaperScissors.Play('r', 'p');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 1);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 1);

    RockPaperScissors.Play('r', 'r');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 1);

    RockPaperScissors.Play('r', 's');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 2);

    RockPaperScissors.Play('s', 'p');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 3);

    RockPaperScissors.Play('s', 'r');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 2);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 3);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 3);

    RockPaperScissors.Play('s', 's');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 3);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 3);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 3);

    // wrong inputs
    RockPaperScissors.Play('w', 'q');
    BOOST_CHECK_EQUAL(RockPaperScissors.Draws, 3);
    BOOST_CHECK_EQUAL(RockPaperScissors.CPU_wins, 3);
    BOOST_CHECK_EQUAL(RockPaperScissors.Player_wins, 3);
  }

BOOST_AUTO_TEST_SUITE_END()
