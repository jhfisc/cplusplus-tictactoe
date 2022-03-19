#include <iostream>
#include <vector>
#include "support.hh"

int main() {
    char answer;
    std::cout << "Would you like to play Tic-Tac-Toe (y/n)? ";
    std::cin >> answer;
    while (answer == 'y') {
        std::vector<std::string> board = initialize_game();
        while (continueGame(board)) {
            print_board(board);
            std::cout << "\n";
            board = human_move(board);

            print_board(board);
            if (continueGame(board)) {
                board = computer_move(board);
            }
            std::cout << "\n";
        }
        end_game(board);
        std::cout << "Would you like to play another game of Tic-Tac-Toe (y/n)? ";
        std::cin >> answer;
    }
}