#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // The game board

const char PLAYER = 'X';
const char COMPUTER = 'O';
const char EMPTY = 'e'; // Represents an empty spot on the board
const char DRAW = 'd'; // Represents a draw

// Function declarations
void play_game();
void reset_board();
void print_board();
void computer_move();
int minimax(int depth, int is_max, int alpha, int beta);
void player_move();
int is_full();
char check_winner();
int game_over();
int max(int num1, int num2);
int min(int num1, int num2);

int main(void) {
    // Game Loop
    do {
        play_game();
    } while(game_over());

    return (0);
}

void play_game() {
    reset_board();
    print_board();

    // Main game loop
    while (check_winner() == EMPTY)
    {
        player_move();
        computer_move();
        print_board();
    }
}


// Resets the game board to empty
void reset_board() {
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

// Prints the current state of the game board
void print_board() {
    system("clear");
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char value = board[i][j];
            if (value == EMPTY)
                printf(" %d ", i * 3 + j + 1); // For empty spots, display the index
            else
                printf(" %c ", value); // For occupied spots, display the player or computer symbol

            if (j < 2) {
                printf("|"); // Print vertical divider except for the last column
            }
        }
        if(i < 2)
        {
            printf("\n");
            printf("---|---|---"); // Print horizontal divider except for the last row
        }
        printf("\n");
    }
}

// Determines and executes the computer's move
void computer_move() {
    if(check_winner() != EMPTY) return; // If game is over, do not make a move

    int best_value = -1000;
    int row = -1, col = -1;

    // Iterate through the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If cell is empty
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER; // Try the cell for COMPUTER
                int move_value = minimax(0, 0, -1000, 1000); // Calculate the value of the move
                board[i][j] = EMPTY; // Reset cell

                // If the value of the current move is more than the best value
                if (move_value > best_value)
                {
                    row = i;
                    col = j;
                    best_value = move_value;
                }
            }
        }
    }

    board[row][col] = COMPUTER; // Implement the move
}

// Get and execute the player's move
void player_move() {
    int index, row, col;

    do {
        printf("\nEnter a spot (1-9): ");
        scanf("%d", &index);

        row = (index - 1) / 3;
        col = (index - 1) % 3;
    }
    while ((index < 1 || index > 9) || board[row][col] != EMPTY); // Check for invalid input or occupied spot

    board[row][col] = PLAYER; // Implement the move
}

// Minimax function, which is the heart of the computer's decision making
int minimax(int depth, int is_max, int alpha, int beta) {
    char result = check_winner();

    if (result == COMPUTER)
        return 10 - depth;

    if (result == PLAYER)
        return depth - 10;

    if (result == DRAW)
        return 0;

    // If current move is of COMPUTER
    if (is_max) {
        int best = -1000;
        // Traverse the board to calculate the best value
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = COMPUTER; // Try the cell for COMPUTER
                    best = max(best, minimax(depth+1, !is_max, alpha, beta));
                    board[i][j] = EMPTY; // Reset cell

                    // Alpha-Beta pruning part
                    alpha = max(alpha, best);
                    if (beta <= alpha) {
                        return best;
                    }
                }
            }
        }

        return best;
    } else { // If the current move is of PLAYER
        int min_best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER; // Try the cell for PLAYER
                    min_best = min(min_best, minimax(depth+1, 1, alpha, beta));
                    board[i][j] = EMPTY; // Reset cell

                    // Alpha-Beta pruning part
                    beta = min(beta, min_best);
                    if (beta <= alpha) {
                        return min_best;
                    }
                }
            }
        }

        return min_best;
    }
}

// Check if the board is full
int is_full() {
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] == EMPTY) {
                return 0;
            }
        }
    }

    return 1;
}

// Check who the winner is
char check_winner() {
    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if(board[row][0] != EMPTY && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return board[row][0];
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if(board[0][col] != EMPTY && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return board[0][col];
        }
    }

    // Check diagonals
    if(board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if(board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // If the board is full and no one has won yet, it's a draw
    if (is_full())
        return DRAW;

    return EMPTY; // If the game is still on
}

// End the game and ask to play again
int game_over() {
    char winner = check_winner();
    char want_to_play;

    if (winner == PLAYER) {
        printf("\nYou won!\n");
    } else if (winner == COMPUTER) {
        printf("\nComputer won!\n");
    } else {
        printf("\nIt's a draw\n");
    }

    // Ask to play again
    printf("Do you want to play again? (Y/N): ");
    scanf("\n%c", &want_to_play);

    return (want_to_play == 'Y' || want_to_play == 'y');
}

int max(int num1, int num2) {
    return (num1 > num2 ) ? num1 : num2;
}

int min(int num1, int num2) {
    return (num1 > num2 ) ? num2 : num1;
}
