# Learning C++ | 02 Guess The Number

## Objective
Practice file manipulation, persistence and responsibility separation.

## Concepts Used
- std::random
- std::vector
- structs
- std::fstream
- input buffer cleaning

## How It Works
The player chooses a difficulty, which determines the max score and the points loss.
A random number based on the difficulty chosen is generated with std::random.
For each attemp:
- If it's correct, the player sees the score and can choose to save it.
- If it's incorrect, the score decrease and the program prints if the guess is lower or higher than the correct number.
The player can choose between play, see leaderboard (It will print the scores in the scores file), or exit the program.

## How to Build & Run
```bash
g++ main.cpp -o game
./game
```

## Possible Improvements
- Better use of structs
- Use of constants and references for optimization
