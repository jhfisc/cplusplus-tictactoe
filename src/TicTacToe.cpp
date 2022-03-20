#include <iostream>
#include <string>
#include <vector>

#include "TicTacToe.hh"

TicTacToe::TicTacToe() {
    srand (time(NULL));
    board = std::vector<std::string>{"---", "---", "---"};
}

void TicTacToe::print_board() {
    int j = 0;
    std::cout << "   a   b   c\n\n";
    for (std::string row: board) {
        print_row(row, j);
        j++;
        if (j != board.size()) {
            std::cout << "\n  -----------";
        } 
        std::cout << "\n";
    }
}

void TicTacToe::end_game() {
    TicTacToe::winner winner = winningPlayer();
    std::cout << "\n";
    print_board();
    std::cout << "\n";

    switch (winner) {
        case YOU:       std::cout << "You won!!\n";
                        break;
        case COMPUTER:  std::cout << "The computer won!!\n";
                        break;
        case TIE:       std::cout << "The game ended in a tie.\n";
                        break;
    }
}

void TicTacToe::reset() {
    board = std::vector<std::string>{"---", "---", "---"};
}

TicTacToe::winner TicTacToe::winningPlayer() {
    winner result = NONE;
    
    std::vector<int>rows = {0, 0, 0};
    std::vector<int>cols = {0, 0, 0};
    std::vector<int>diag = {0, 0};

    int i = 0;
    for (std::string row: board) {
        rows[i]  = rvalue(row, 0);
        rows[i] += rvalue(row, 1);
        rows[i] += rvalue(row, 2);
        i++;
    }

    for (int i = 0; i < board.size(); i++) {
        cols[i]  = bvalue(board, 0, i);
        cols[i] += bvalue(board, 1, i);
        cols[i] += bvalue(board, 2, i);
    }

    // top left to lower right diagonal
    diag[0]  = bvalue(board, 0, 0);
    diag[0] += bvalue(board, 1, 1);
    diag[0] += bvalue(board, 2, 2);
    // top right to lower left diagonal
    diag[1]  = bvalue(board, 2, 0);
    diag[1] += bvalue(board, 1, 1);
    diag[1] += bvalue(board, 0, 2);

    if (checkWinner(rows, 3) || checkWinner(cols, 3) || checkWinner(diag, 3)) {
        result = YOU;
    } else if (checkWinner(rows, -3) || checkWinner(cols, -3) || checkWinner(diag, -3)) {
        result = COMPUTER;
    } else {
        std::string checker = board[0] + board[1] + board[2];
        if (checker.find('-') == -1) {
            result = TIE;
        }
    }

    return result; 
}

bool TicTacToe::is_valid(int row, char col, bool computer) {
    bool result = true;
    int icol = col - 'a';
    std::string chars = "abc";
    bool inSet = chars.find(col) != std::string::npos;

    if (!inSet) {
        result = false;
        if (!computer) {
            std::cout << "Invalid col (" << col << ")\n";
        }
    }

    if (result && (row < 0 || row > 3)) {
        result = false;
        if (!computer) {
            std::cout << "Invalid row (" << row << ")\n";
        }
    }

    if (result && board[row][icol] != '-') {
        result = false;
        if (!computer) {
            std::cout << "Position already taken\n";
        }
    }

    return result;
}


void TicTacToe::human_move() {
    bool valid = false;
    int row;
    char col;
    while (!valid) {
        std::cout << "Enter desired row: ";
        std::cin >> row;
        row--;

        std::cout << "Enter desired col: ";
        std::cin >> col;

        valid = is_valid(row, col);
    }
    board[row][which_col(col)] = 'x';
}


void TicTacToe::computer_move() {
    int row = rand() % 3;
    int col = rand() % 3;
    while (! is_valid(row, switch_col(col), true)) {
        row = rand() % 3;
        col = rand() % 3;
    }
    board[row][col] = 'o';
}

bool TicTacToe::continueGame() {
    bool result = true;
    TicTacToe::winner winner = winningPlayer();

    if (winner == YOU || winner == COMPUTER || winner == TIE) {
        result = false;
    }

    return result;
}

void TicTacToe::play() {
    while (continueGame()) {
        print_board();
        human_move();
        if (continueGame()) {
            computer_move();
        }
        std::cout << "\n";
    }
    end_game();
}

int main() {
    TicTacToe game;
    char answer;

    std::cout << "Would you like to play Tic-Tac-Toe (y/n)? ";
    std::cin >> answer;
    while (answer == 'y') {
        game.reset();
        game.play();
        std::cout << "Would you like to play another game of Tic-Tac-Toe (y/n)? ";
        std::cin >> answer;
    }
}