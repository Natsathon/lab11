#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "Press Enter 3 times to reveal your future." << std::endl;
    for (int i = 0; i <3; ++i) {
        std::cin.get();
    }
    std::srand(std::time(0));
    int randomGrade = std::rand() % 9;  
    const char* grades[] = {"A", "B+", "B", "C+", "C", "D+", "D", "F", "W"};
    std::cout << "You will get " << grades[randomGrade] << " in this 261102." << std::endl;
    return 0;
}