#include <iostream>
#include <cstdlib>
#include <ctime>

int drawCard();
int calScore(int x, int y, int z);
int findYugiAction(int s);
void checkWinner(int p, int y);

int main() {
    std::srand(std::time(0));

    int playerCard1 = drawCard();
    int playerCard2 = drawCard();
    int playerScore = calScore(playerCard1, playerCard2, 0);

    std::cout << "---------ORE NO TURN, DRAW!!!------------" << std::endl;
    std::cout << "Your cards: " << playerCard1 << " " << playerCard2 << std::endl;
    std::cout << "Your score: " << playerScore << std::endl;

    int playerChoice;
    do {
        std::cout << "(1) Destiny draw (2) Stay, SELECT: ";
        std::cin >> playerChoice;

        if (playerChoice == 1) {
            int playerCard3 = drawCard();
            int newPlayerScore = calScore(playerCard1, playerCard2, playerCard3);
            std::cout << "Player draws the 3rd card!!!" << std::endl;
            std::cout << "Your 3rd card: " << playerCard3 << std::endl;
            std::cout << "Your new score: " << newPlayerScore << std::endl;
            playerScore = newPlayerScore;
        } else if (playerChoice != 2) {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }

    } while (playerChoice != 2);

    std::cout << "------------ Turn end -------------------" << std::endl;

    int yugiCard1 = drawCard();
    int yugiCard2 = drawCard();
    int yugiScore = calScore(yugiCard1, yugiCard2, 0);

    std::cout << "---------YUGI'S TURN, DRAW!!!------------" << std::endl;
    std::cout << "Yugi's cards: " << yugiCard1 << " " << yugiCard2 << std::endl;
    std::cout << "Yugi's score: " << yugiScore << std::endl;

    int yugiChoice = findYugiAction(yugiScore);
    if (yugiChoice == 1) {
        int yugiCard3 = drawCard();
        int newYugiScore = calScore(yugiCard1, yugiCard2, yugiCard3);
        std::cout << "Yugi draws the 3rd card!!!" << std::endl;
        std::cout << "Yugi's 3rd card: " << yugiCard3 << std::endl;
        std::cout << "Yugi's new score: " << newYugiScore << std::endl;
        yugiScore = newYugiScore;
    }

    std::cout << "------------ Turn end -------------------" << std::endl;

    checkWinner(playerScore, yugiScore);

    return 0;
}

int drawCard() {
    return std::rand() % 13 + 1; 
}

int calScore(int x, int y, int z) {
    int sum = x + y + z;
    return sum % 10;
}

int findYugiAction(int s) {
    if (s == 9)
        return 2; 
    else if (s < 6)
        return 1; 
    else {
        return (std::rand() % 100 < 69) ? 1 : 2;
    }
}

void checkWinner(int p, int y) {
    std::cout << std::endl << "---------------------------------" << std::endl;
    if (p > y)
        std::cout << "|          Player wins!!!       |" << std::endl;
    else if (y > p)
        std::cout << "|          Yugi wins!!!         |" << std::endl;
    else
        std::cout << "|             Draw!!!           |" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}
