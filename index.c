#include <stdio.h>
#include <stdlib.h>
// Global variables
char board[3][3];   // 3x3 Tic-Tac-Toe grid
char currentPlayer; // Current player ('X' or 'O')
// Function prototypes
void initializeBoard();
void displayBoard();
int isWinner();
int isDraw();
void switchPlayer();
void makeMove();
int main()
{
    int gameStatus = 0; // 0 = ongoing, 1 = winner, 2 = draw       
    // Initialize game
    initializeBoard();
    currentPlayer = 'X';
    printf("Welcome to Tic-Tac-Toe!\n");
    while (1)
    {
        displayBoard();
        makeMove();
        if (isWinner())
        {
            displayBoard();
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            break;
        }
        if (isDraw())
        {
            displayBoard();
            printf("It's a draw! Well played.\n");
            break;
        }
        switchPlayer();
    }
    return 0;
} 
// Initialize the board
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '1' + (i * 3 + j); // '1' to '9'       
        }
    }
} 
// Display the board
void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
} 
// Check for a winner
int isWinner()
{ 
    // Check rows, columns, and diagonals   
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1; // Row       
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1; // Column   
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1; // Diagonal   
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1; // Diagonal   
    return 0;
} 
// Check for a draw
int isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}
// Switch to the other player
void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
// Make a move
void makeMove()
{
    int choice;
    int row, col;
    while (1)
    {
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &choice);
        if (choice < 1 || choice > 9)
        {
            printf("Invalid move! Try again.\n");
            continue;
        }
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = currentPlayer;
            break;
        }
        else
        {
            printf("Cell already occupied! Try again.\n");
        }
    }
}