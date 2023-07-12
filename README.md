# Tic Tac Toe with Minimax and Alpha-Beta Pruning

## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Resources](#resources)

## Introduction
This repository contains the code for a console-based Tic Tac Toe game written in C. The unique aspect of this program is its utilization of the Minimax algorithm with Alpha-Beta Pruning to drive the game AI. The AI is designed to make the most optimal move at every turn, ensuring a high level of difficulty.

### Minimax Algorithm & Alpha-Beta Pruning

The Minimax algorithm is a decision-making algorithm for minimax games, typically used in game theory and decision theory. It finds the optimal move for a player, assuming that the opponent is also playing optimally. In the context of this Tic Tac Toe game, it's used to decide the AI's next move by examining all the possible future game states (or the game tree) to pick the one which will be most beneficial for the AI.

However, traversing the entire game tree can be computationally expensive. That's where Alpha-Beta Pruning comes in. Alpha-Beta Pruning is an optimization technique for the Minimax algorithm. It reduces the computation by a significant amount by pruning the branches in the game tree which need not be explored because there already exists a better move available.

## Getting Started

### Prerequisites

To clone and run this application, you'll need:

- [Git](https://git-scm.com)
- A C compiler like [GCC](https://gcc.gnu.org/)

### Cloning The Repository

Open your terminal/command line and run the following command to clone this repository:
```
git clone https://github.com/moufidayoub11/tictactoe_minimax_alphabeta.git
```

### Running The Game

Navigate into the cloned directory:
```
cd tictactoe_minimax_alphabeta
```

Compile the code:
```
gcc main.c -o tictactoe
```

Run the game:
```
./tictactoe
```

Follow the prompts in the console to play the game.

## Resources

For more information on the Minimax algorithm and Alpha-Beta Pruning, check out the following resources:

1. [Minimax Algorithm in Game Theory](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/)
2. [Alpha-Beta Pruning](https://www.geeksforgeeks.org/alpha-beta-pruning-in-minimax-algorithm/)
3. [Algorithms Explained – minimax and alpha-beta pruning](https://www.youtube.com/watch?v=l-hh51ncgDI)
