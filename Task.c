#include <stdio.h>


void print_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}


int check_win(char board[3][3], char player) {
    int i, j;
    
 
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    
    
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    
    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Initialize empty board
    int i, j, player = 1, choice, row, col;
    char mark;
    
    do {
        print_board(board); // Print current board
        
        player = (player % 2) ? 1 : 2; // Determine current player
        
        printf("Player %d, enter a number (1-9) to mark: ", player);
        scanf("%d", &choice); // Get user input
        
        row = (choice - 1) / 3; // Calculate row and column from user input
        col = (choice - 1) % 3;
        
        mark = (player == 1) ? 'X' : 'O'; // Determine mark based on current player
        
        if (board[row][col] == ' ') { // Check if chosen square is empty
            board[row][col] = mark;
            player++;
        }
        else {
            printf("Invalid move, try again.\n");
        }
    } while (!check_win(board, 'X') && !check_win(board, 'O') && choice < 9);
    
    print_board(board); // Print final board
    
    if (check_win(board, 'X')) {
        printf("Player 1 (X) wins!\n");
    }
    else if (check_win(board, 'O')) {
        printf("Player 2 (O) wins!\n");
    }
    else {
        printf("Tie game.\n");
    }
    
    return 0;
}
