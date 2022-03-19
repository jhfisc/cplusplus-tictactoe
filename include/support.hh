/*
 * support header file for tic-tac-toe
 */
#include <string>
#include <vector>
#include <algorithm>

void print_board(std::vector<std::string>board);
bool is_valid(std::vector<std::string>board, int col, char row, bool computer = false);
void end_game(std::vector<std::string>board);
std::vector<std::string> initialize_game();
std::vector<std::string> human_move(std::vector<std::string>board);
std::vector<std::string> computer_move(std::vector<std::string>board);
bool continueGame(std::vector<std::string>board);



inline
int which_col(char col) {
    int result = -1;
    switch (col) {
        case 'a': result = 0;
                  break;
        case 'b': result = 1;
                  break;
        case 'c': result = 2;
                  break;
    }
    return result;
}

inline
void print_row(std::string row, int count) {
    std::cout << count + 1 << " ";
    for (int i = 0; i < row.size(); i++) {
        if (row[i] == '-') {
            std::cout << "  ";
        } else {
            std::cout << " " << row[i] ;
        }
        if (i != 2) {
            std::cout << " |";
        }
    }
}

inline
int bvalue(std::vector<std::string>board, int r, int c) {
    return board[r][c] == 'x' ? 1:board[r][c] == 'o' ? -1:0;
}

inline
int rvalue(std::string row, int c) {
    return row[c] == 'x' ? 1:row[c] == 'o' ? -1:0;
}

inline
bool checkWinner(std::vector<int>vect, int value) {
    return std::find(vect.begin(), vect.end(), value) != vect.end();
}