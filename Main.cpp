#include <iostream>
#include <vector>
#include <limits>

void pauseBeforeClose(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main(){
    //                         0    1    2    3    4    5    6    7    8
    std::vector<char> board { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char turn { 'X' };
    std::string gameStatus { "Running" };

    while (gameStatus == "Running"){
    system("cls");
    for (int i = 0; i < board.size(); i++){
        std::cout << board[i];
        if ((i + 1) % 3 != 0) {
            std::cout << " | ";
        } else {
            std::cout << std::endl;
            if (i < 8) {
                std::cout << "---------" << std::endl;
            }
        }
    }
    std::cout << "The current turn is: " << turn << std::endl;
    std::cout << "Where does " << turn << " want to go? (1-9):";
    int place {};
    if (!(std::cin >> place)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number from 1 to 9." << std::endl;
        continue;
    }
    if (place >= 1 && place <= 9 && board[place - 1] != 'X' && board[place - 1] != 'O') {
        board[place - 1] = turn;
        if (board[0] == board[1] && board[1] == board[2] && board[0] == turn) {
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[3] == board[4] && board[4] == board[5] && board[3] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[6] == board[7] && board[7] == board[8] && board[6] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[0] == board[3] && board[3] == board[6] && board[0] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[1] == board[4] && board[4] == board[7] && board[1] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[2] == board[5] && board[5] == board[8] && board[2] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[0] == board[4] && board[4] == board[8] && board[0] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else if (board[2] == board[4] && board[4] == board[6] && board[2] == turn){
            gameStatus = "Won";
            std::cout << "Player " << turn << " wins!" << std::endl;
            pauseBeforeClose();
        } else {
            // Check for draw
            bool draw { true };
            for (char c : board) {
                if (c != 'X' && c != 'O') {
                    draw = false;
                    break;
                }
            }
            if (draw) {
                gameStatus = "Draw";
                std::cout << "It's a draw!" << std::endl;
                pauseBeforeClose();
            } else {
                if (turn == 'X'){
                    turn = 'O';
                } else {
                    turn = 'X';
                }
            }
        }
    } else {
        std::cout << "Invalid move. Try again." << std::endl;
    }
    }
    return 0;
}