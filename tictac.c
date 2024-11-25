#include <stdio.h>

char gridChar(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
    return ' ';
}

void draw(int board[9]) {
    printf(" %c | %c | %c\n", gridChar(board[0]), gridChar(board[1]), gridChar(board[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", gridChar(board[3]), gridChar(board[4]), gridChar(board[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", gridChar(board[6]), gridChar(board[7]), gridChar(board[8]));
    printf("\n");
}

int checkWinner(const int board[9]) {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (int i = 0; i < 8; ++i) {
        if (board[wins[i][0]] != 0 &&
            board[wins[i][0]] == board[wins[i][1]] &&
            board[wins[i][0]] == board[wins[i][2]]) {
            return board[wins[i][0]];
        }
    }
    return 0;
}

void playerMove(int board[9], int player) {
    int move = 0, validMove = 0;

    while (!validMove) {
        printf("Player %c, enter your move (0-8): ", (player == -1) ? 'X' : 'O');
        scanf("%d", &move);

        if (move >= 0 && move < 9 && board[move] == 0) {
            board[move] = player;
            validMove = 1;
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }
}

int main() {
    int board[9] = {0,0,0,0,0,0,0,0,0};
    int player = -1;
    int moves = 0;

    printf("Welcome to Tic-Tac-Toe!\n");
    
    while (1) {
        draw(board);
        playerMove(board, player);
        moves++;

        int winner = checkWinner(board);
        if (winner != 0) {
            draw(board);
            printf("Player %c wins!\n", (winner == -1) ? 'X' : 'O');
            break;
        }
        
        if (moves == 9) {
            draw(board);
            printf("It's a draw!\n");
            break;
        }

        player = -player;  // Switch player
    }
    
    return 0;
}