#include <iostream>
#include <string>
#include <chrono>
#include <thread>

/**
 * A helper method to generate cosmetic lines in the terminal.
 * 
 * @params newLine Whether or not a new empty line will be generated after the line
 * @return void
 */

void generateLine(bool newLine) {
    if(newLine == false) {
    std::cout << "#--------------------------------------#" << std::endl;
    }
    else {
    std::cout << "#--------------------------------------#\n" << std::endl;
    }
}

/**
 * Main method to play the RPS game an infinite number of times.
 * The game continues until user quits.
 */

int main() {

    int programScore = 0;
    int userScore = 0;

    std::string selections[3] = {"Rock", "Paper", "Scissors"};
    generateLine(true);
    std::cout << "Welcome to Rock Paper Scissors in C++. Press enter to continue.\n" << std::endl;
    generateLine(false);
    std::cin.ignore();

    while(1) {

        int randomizer = rand() % 3;
        std::string randomSelection = selections[randomizer];
        std::string input;
        std::cout << "Enter your selection - \n 1: Rock\n 2: Paper\n 3: Scissors\n q: Quit" << std::endl;
        std::cin >> input;
        
        if(input != "1" && input != "2" && input != "3" && input != "q") {
            std::cout << "Incorrect input. Please use a valid input...\n" << std::endl;
            generateLine(true);
            continue;
        }
        else if(input == "q") {
            break;
        }
        else {
            generateLine(true);
            std::cout << "Rock,\n" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
            std::cout << "Paper,\n" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
            std::cout << "Scissors,\n" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
            std::cout << "Shoot!\n" << std::endl;
            generateLine(true);

            std::cout << "Your selection: " << selections[std::stoi(input) - 1] << "\n" << std::endl;
            std::cout << "Program's selection: " << randomSelection << "\n" << std::endl;

            //Rock
            if(input == "1") {
                if(randomSelection == "Paper") {
                    goto loss;
                }
                if(randomSelection == "Scissors") {
                    goto win;
                }
                else {
                    goto tie;
                }
            }
            //Paper
            else if(input == "2") {
                if(randomSelection == "Scissors") {
                    goto loss;
                }
                if(randomSelection == "Rock") {
                    goto win;
                }
                else {
                    goto tie;
                }
            }
            //Scissors
            else {
                if(randomSelection.compare("Rock")) {
                    goto loss;
                }
                if(randomSelection.compare("Paper")) {
                    goto win;
                }
                else {
                    goto tie;
                }

        }

        loss:
            programScore += 1 ;
            std::cout << "You lose! Your score is " << userScore << ". The program's score is " << programScore << ".\n" << std::endl;
            generateLine(true);
            continue;
        win:
            userScore += 1;
            std::cout << "You win! Your score is " << userScore << ". The program's score is " << programScore << ".\n" << std::endl;
            generateLine(true);
            continue;
        tie:
            std::cout << "A tie! Your score is " << userScore << ". The program's score is " << programScore << ".\n" << std::endl;
            generateLine(true);
            continue;

    }

}

}