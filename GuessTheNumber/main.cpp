#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

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

void saveScore(int score){
    std::vector<int> scores;
    std::fstream scoreFile;

    scoreFile.open("records.txt", std::ios_base::in);

    if (!scoreFile){
        std::ofstream temp("records.txt");
        temp.close();
        scoreFile.open("records.txt", std::ios_base::in);
    }
    

    int num;
    if (scoreFile.is_open()) {
        while (scoreFile >> num) {
            if (num == score) {
                scoreFile.close();
                return;
            }
            scores.push_back(num);
        }
        scoreFile.close();
        scoreFile.clear();
    }

    scores.push_back(score);
    std::sort(scores.begin(), scores.end(), std::greater<int>());

    scoreFile.open("records.txt", std::ios_base::out | std::ios_base::trunc);
    if (scoreFile.is_open()){
        for (const int& n : scores){
            scoreFile << n << "\n";
        }
    }
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
        saveScore(score);
    }
}

void leaderboard(){
    std::system("clear");
    std::cout << "LEADERBOARD\n\n";

    std::fstream scoreFile;

    scoreFile.open("records.txt", std::ios_base::in);

    if (!scoreFile) {
        std::ofstream temp("records.txt");
        temp.close();
        scoreFile.open("records.txt", std::ios_base::in);
    }

    if (scoreFile.is_open()) {
        int num;
        int index = 1;
        while (scoreFile >> num) {
            std::cout << index << ". " << num << "\n";
            index++;
        }
        scoreFile.close();
    }

    std::cout << "\nPress ENTER to return\n";
    std::cin.get();
}

int main(){
    char select;
    std::string trash;
    while (true){
        std::system("clear");
        
        std::cout << "Guess The Number | v1.0\n\n";
        std::cout << "Options:\n1. Play\n2. Leaderboard\n3. Exit\n\n";
        std::cout << "Selection: ";
        
        std::cin >> select;
        std::getline(std::cin, trash);

        switch (select) {
            case '1':
                play();
                break;
            case '2':
                leaderboard();
                break;
            case '3':
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default: continue;
        }
    }
}
