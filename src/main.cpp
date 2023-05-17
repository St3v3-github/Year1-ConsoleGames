#include <iostream>

//this is the function for the computer to generate a random target number
int randomNumber ()
{
  srand(time(0));   // Generates random number
  int target_num = rand() % 10 + 1; // Makes sure number is between 1 and 10
  return target_num;
}

//this is the function for the computer to generate random r, p or s
char machineGuess ()
{
  srand(time(0));    // Generates random number
  int machine_rand = rand() % 3; // Makes sure number is between 0 and 3

  if (machine_rand == 0)
    return 'r';
  else if (machine_rand == 1)
    return 'p';
  else
    return 's';
}

int main()
{
  int game_mode  = 0; //Variable for switch statements - user chooses game mode 1 or 2
  char main_menu = 'y'; //variable for main menu looping (while loop below)
  while (main_menu == 'y')
  {
    // introduction to the game
    std::cout << "\nWelcome to Console Games!" << std::endl;
    std::cout << "Remember to only use lower case inputs :) \n" << std::endl;
    std::cout << "Would you like to play Guess the Number, or Rock, Paper, Scissors?" << std::endl;
    std::cout << "Please enter 1 for guess the number, and 2 for Rock, Paper, Scissors" << std::endl;
    std::cin >> game_mode;
    main_menu = 'n';

    switch (game_mode)
    {
      case 1:
      {
        std::cout << "\nRandom number generator\n" << std::endl;
        char rand_num_game_running = 'y';    // declares variable for the while loop
        while (rand_num_game_running != 'n') // initialises the while loop so that the game loop will restart to this point
        {
          int local_target_num = randomNumber(); // calls random number function and stores it in a local variable to use
          int user_guess = 0;

          for (int counter = 0; counter < 5; counter++) //for loop to give user 5 attempts to guess the number
          {
            std::cout << "Please guess a random number between 1 and 10: " << std::endl;
            std::cin >> user_guess; // input user guess

            // Ensures User guess is between 1 and 10 before continuing - will go on infinitely until user inputs correct numbers
            if ((user_guess < 1) || (user_guess > 10))
            {
              std::cout << "Please only guess a random number between 1 and 10: " << std::endl;
              std::cin >> user_guess;
            }

            //"less than target number" output
            else if (user_guess < local_target_num)
            {
              std::cout << "\nIncorrect! Your guess is less than the target number, try again: " << std::endl;
            }

            //"more than target number" output
            else if (user_guess > local_target_num)
            {
              std::cout << "\nIncorrect! Your guess is more than the target number, try again: " << std::endl;
            }

            //"correct" output
            else
            {
              std::cout << "\nCorrect! :) " << std::endl;
              break;
            }
          }
          // tells player the target number and asks if they want to play again - will restart game using above while loop based on their response
          std::cout << "The target number was:  " << local_target_num << std::endl;
          std::cout << "Round over, Would you like to play again? (y/n)" << std::endl;
          std::cin >> rand_num_game_running;
        }
        break;
      }

      case 2:
      {
        std::cout << "\nRock, Paper, Scissors \n" << std::endl;

        //Variable to hold User and Computer scores to display at the end
        int user_win_tally = 0;
        int computer_win_tally = 0;

        char rps_game_running = 'y';    // declares variable for restart loop
        while (rps_game_running != 'n') // loop to restart the game using user response
        {
          char rps_user_guess; // local variable for user guess input
          char local_machine_guess = machineGuess(); // calls machine guess function and stores it in a local variable

          std::cout << "Please guess: Rock(r), Paper(p) or Scissors(s)" << std::endl;
          std::cin >> rps_user_guess;

          // Player wins, loses, draws Code
          if (rps_user_guess == 'r' && local_machine_guess == 's' || rps_user_guess == 'p' && local_machine_guess == 'r' || rps_user_guess == 's' && local_machine_guess == 'p')
          {
            std::cout << ("\nYou Win!") << std::endl;
            user_win_tally = user_win_tally + 1;
          }

          else if (local_machine_guess == 'r' && rps_user_guess == 's' || local_machine_guess == 'p' && rps_user_guess == 'r' || local_machine_guess == 's' && rps_user_guess == 'p')
          {
            std::cout << ("\nYou Lose!") << std::endl;
            computer_win_tally = computer_win_tally + 1;
          }

          else
          {
            std::cout << ("\nDraw!") << std::endl;
          }

          // tells player what computer played and asks if they want to play again - will restart based on their response
          std::cout << "\nComputer played " << local_machine_guess << std::endl;
          std::cout << "Round over, Would you like to play again? (y/n) " << std::endl;
          std::cin >> rps_game_running;
          if (rps_game_running == 'n')
          {
            std::cout << "\nPlayer score: " << user_win_tally << std::endl;
            std::cout << "Computer score: " << computer_win_tally << std::endl;
            if (user_win_tally > computer_win_tally)
            {
              std::cout << "User Wins!" <<std::endl;
            }

            else if (user_win_tally == computer_win_tally)
            {
              std::cout << "Draw!" <<std::endl;
            }

            else
            {
              std::cout << "Computer Wins!" <<std::endl;
            }
          }
        }
        break;
      }
    }
    // what happens if user chooses not to replay for both games - loops back to main menu while input = 'y'
    // if user input = 'n', program ends -> 0 is returned
    std::cout << "\nGame Over" << std::endl;
    std::cout << "Would you like to quit to main menu? (y/n)" << std::endl;
    std::cin >> main_menu; //Loops back to main menu if user input != 'n'
  }
  return 0;
}