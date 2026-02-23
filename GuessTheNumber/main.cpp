#include <iostream>
#include <random>
#include <string>
#include <cstdlib>

// Description:
// A simple GuessTheNumber game in console, with persistence of max score and cumulative score system.

struct Difficult {
    int initial_pts;
    int pts_loss;
};

int genNumber(char difficult){
    int start = 1;
    int end;

    switch (difficult) {
        case 'E':
            end = 10;
            break;
        case 'M':
            end = 50;
            break;
        case 'H':
            end = 100;
            break;
        default:
            end = 10;
            break;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(start, end);
    
    return dist(gen);
}

bool checkGuess(int num, int guess){
    if (num > guess) {
        std::cout << "Low...\n";
    } else if (num < guess) {
        std::cout << "High...\n";
    } else if (num == guess) {
        std::cout << "Correct!\n";
        return true;
    }
    return false;
}

Difficult getStruct(char difficult){
    Difficult diff;
    switch (difficult) {
        case 'E':
            diff.initial_pts = 100;
            diff.pts_loss = 10;
            break;
        case 'M':
            diff.initial_pts = 200;
            diff.pts_loss = 25;
            break;
        case 'H':
            diff.initial_pts = 300;
            diff.pts_loss = 50;
            break;
        default:
            diff.initial_pts = 100;
            diff.pts_loss = 10;
            break;
    }
    return diff;
}

void play(){
    std::string trash;
    char difficult;
    int num;
    int guess;
    bool check;
    int attemps = -1;
    int score;


    std::cout << "\nChoose difficult(E=Easy M=Medium H=Hard): ";
    
    std::cin >> difficult;
    std::getline(std::cin, trash);
    Difficult diff = getStruct(difficult);
    score = diff.initial_pts;
    num = genNumber(difficult);

    do {
        attemps++;
        std::cout << "\nYour guess: ";
        std::cin >> guess;
        check = checkGuess(num, guess);
    } while (!(check));

    score = score - (diff.pts_loss * attemps);
    if (score < 1){ score = 1;}

    std::cout << "Your score: " << score;
    char save;
    std::cout << "\nDo you want to save the score?(Y/N): ";
    std::cin >> save;
    std::getline(std::cin, trash);
    
    if (save == 'Y'){
        std::cout << "Saving..." << std::endl; // Score saving code goes here :p
    }

    return;
}
int main(){
    char select;
    while (true){
        std::system("clear");
        
        std::cout << "Guess The Number | v1.0\n\n";
        std::cout << "Options:\n1. Play\n2. See leaderboard\n3. Exit\n\n";
        std::cout << "Selection: ";
        
        std::cin >> select;

        switch (select) {
            case '1':
                play();
                break;
            case '2':
                std::cout << "Leaderboard..." << std::endl;
                break;
            case '3':
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default: continue;
        }
    }
}
