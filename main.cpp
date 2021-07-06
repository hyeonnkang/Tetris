// Tetris.cpp : 테트리스 게임입니다.
#include <iostream>
#include <iomanip>
#include <string>
#include "Board.h"
using namespace std;

// ▦



void startmenu();   // 게임의 시작 화면

int main()
{
    startmenu();
    int select;
    while (true) {
        cin >> select;

        if (select == -1) return 0;
        else if (select == 1) break;
    }

    system("cls");

    Board GameBoard;
    GameBoard.print();
}

void startmenu() {
    cout <<"\n" << " TTTTTTTTTTTT  EEEEEEEEEEEEEEE  TTTTTTTTTTTTTT  RRRRRRRRRRRRR  IIIIIIIIIIIII  SSSSSSSSSSSS   "
        << "\n" << "     TTT       EEE                   TTT        RRR       RRR       III       SSSSS     SSSSS"
        << "\n" << "     TTT       EEE                   TTT        RRR       RRR       III          SSSSSS"
        << "\n" << "     TTT       EEEEEEEEEEEEEEE       TTT        RRRRRRRRRRRRR       III              SSSSSS"
        << "\n" << "     TTT       EEE                   TTT        RRRRR               III       SSSSS      SSSS"
        << "\n" << "     TTT       EEE                   TTT        RRR RRRRR           III          SSSSSSSSSSSS"
        << "\n" << "     TTT       EEEEEEEEEEEEEEE       TTT        RRR     RRRRR   IIIIIIIIIIII" << endl;

    cout << "\n\n" << setw(10) << right << "start -> press 1"
        << "\n" << setw(10) << right << "exit  -> press -1" << "\n>>";
}
