/*
 * support functions for tic-tac-toe
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "support.hh"

std::vector<std::string> initialize_game() {
    srand (time(NULL));
    return std::vector<std::string>{"---", "---", "---"};
}

std::string winningPlayer(std::vector<std::string>board) {
    std::string winner = "";
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
        winner = "human";
    } else if (checkWinner(rows, -3) || checkWinner(cols, -3) || checkWinner(diag, -3)) {
        winner = "computer";
    }

    return winner;
}

std::vector<std::string> computer_move(std::vector<std::string>board) {
    int row = rand() % 3;
    int col = rand() % 3;
    char acol;
    switch (col) {
        case 0: acol = 'a';
                break;
        case 1: acol = 'b';
                break;
        case 2: acol = 'c';
                break;
    }
    while (! is_valid(board, row, acol, true)) {
        row = rand() % 3;
        col = rand() % 3;
        switch (col) {
            case 0: acol = 'a';
                    break;
            case 1: acol = 'b';
                    break;
            case 2: acol = 'c';
                    break;
        }

    }
    board[row][col] = 'o';

    return board;
}

bool continueGame(std::vector<std::string>board) {
    bool result = false;
    std::string winner = winningPlayer(board);

    if (std::find(board.begin(), board.end(), "-") != board.end()) {
        result = true;
    } else if (winner == "") {
        result = true;
    }
    return result;
}

void print_board(std::vector<std::string>board) {
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

bool is_valid(std::vector<std::string>board, int row, char col, bool computer) {
    bool result = true;
    int icol = -1;

    switch (col) {
        case 'a': icol = 0;
                  break;
        case 'b': icol = 1;
                  break;
        case 'c': icol = 2;
                  break;
        default:  result = false;
                  if (!computer) {
                      std::cout << "Invalid column (" << col << ")\n";
                  }
                  break;
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

void end_game(std::vector<std::string>board) {
    std::string winner = winningPlayer(board);
    print_board(board);
    if (winner == "") {
        std::cout << "\nTie game!!\n";
    } else {
        std::cout << "\n" << winner << " is the winner\n";
    }
}

std::vector<std::string> human_move(std::vector<std::string>board) {
    bool valid = false;
    int row;
    char col;
    while (!valid) {
        std::cout << "Enter desired row: ";
        std::cin >> row;
        row--;

        std::cout << "Enter desired col: ";
        std::cin >> col;

        valid = is_valid(board, row, col);
    }
    board[row][which_col(col)] = 'x';

    return board;
}