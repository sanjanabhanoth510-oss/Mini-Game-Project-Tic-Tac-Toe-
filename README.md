# Mini Game Project - Tic Tac Toe

A two-player, console-based Tic-Tac-Toe game written in C++.

## Objective

To create a console mini game that demonstrates core programming concepts such as loops, arrays and conditional logic.

## Features

- Two players: Player 1 uses `X`, Player 2 uses `O`
- Positions are chosen with numbers 1-9
- The board is redrawn after every valid move
- Win detection for all rows, columns and both diagonals
- Draw detection when all positions are filled with no winner
- Invalid input (letters, numbers outside 1-9, empty input) and already occupied positions are rejected, and the same player is asked again
- Replay option after each game

## Technologies Used

- C++ (C++17)
- Standard library only (`iostream`, `string`, `cstdlib`)

## Programming Concepts Used

- 2D array to store the board
- Loops (`for`, `while`)
- Conditional statements (`if`, `else`)
- Functions with parameters and return values
- Input validation

## How to Compile

```bash
g++ -std=c++17 tic_tac_toe.cpp -o tic_tac_toe
```

## How to Run

```bash
./tic_tac_toe
```

On Windows:

```bash
tic_tac_toe.exe
```

## How to Play

1. The board shows the numbers 1-9, one for each position:

```
  1 | 2 | 3
 ---+---+---
  4 | 5 | 6
 ---+---+---
  7 | 8 | 9
```

2. Player X goes first. Type a number from 1 to 9 and press Enter.
3. The board is redrawn with your symbol in that position, then the other player takes a turn.
4. The first player to get three of their symbols in a row, column or diagonal wins.
5. If all nine positions are filled and nobody has won, the game is a draw.
6. After the game ends, enter `y` to play again or `n` to exit.

## Expected Game Behavior

- Choosing a position that is already taken shows a message, and the same player tries again.
- Entering anything other than a single number from 1 to 9 shows an error message, and the same player tries again.
- The game ends immediately when a player wins or the board is full.
