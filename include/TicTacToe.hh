#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class TicTacToe {
    private:
        enum winner { YOU, COMPUTER, TIE, NONE };
        
        std::vector<std::string>board;

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
        char switch_col(int col)
        {
            char acol;

            switch (col) {
                case 0: acol = 'a';
                        break;
                case 1: acol = 'b';
                        break;
                case 2: acol = 'c';
                        break;
            }
            return acol;
        }
        winner winningPlayer();
        bool is_valid(int row, char col, bool computer=false);

        void end_game();
        void print_board();
        void human_move();
        void computer_move();
        bool continueGame();

    public:
        TicTacToe();
        void reset();
        void play();
};