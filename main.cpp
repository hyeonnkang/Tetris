// Tetris.cpp : 테트리스 게임입니다.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ▦

#define BOARD_WIDTH 20  // 테트리스 보드의 가로 길이
#define BOARD_HEIGHT 40 // 테트리스 보드의 세로 길이

void startmenu();   // 게임의 시작 화면
void setboard(int[][BOARD_WIDTH]);    // 테트리스 게임판 설정 함수
void printboard(int[][BOARD_WIDTH]);  // 테트리스 게임판 그리기 함수

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

    int board[BOARD_HEIGHT][BOARD_WIDTH];   // 경계는 -1, 공백은 0, 블럭은 1;
    setboard(board);
    printboard(board);
}

void startmenu() {
    cout << "\n\n\n" << "▒▒▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒▒"
        << "\n" << "     ▒▒▒        ▒▒▒                  ▒▒▒        ▒▒▒      ▒▒▒         ▒▒▒          ▒▒▒      ▒▒▒"
        << "\n" << "     ▒▒▒        ▒▒▒                  ▒▒▒        ▒▒▒      ▒▒▒         ▒▒▒          ▒▒▒▒▒▒"
        << "\n" << "     ▒▒▒        ▒▒▒▒▒▒▒▒▒▒▒▒▒        ▒▒▒        ▒▒▒▒▒▒▒▒▒▒▒▒         ▒▒▒             ▒▒▒▒▒▒"
        << "\n" << "     ▒▒▒        ▒▒▒                  ▒▒▒        ▒▒▒▒▒▒               ▒▒▒                ▒▒▒▒▒▒"
        << "\n" << "     ▒▒▒        ▒▒▒                  ▒▒▒        ▒▒▒   ▒▒▒            ▒▒▒          ▒▒▒      ▒▒▒"
        << "\n" << "     ▒▒▒        ▒▒▒▒▒▒▒▒▒▒▒▒▒        ▒▒▒        ▒▒▒      ▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒▒      ▒▒▒▒▒▒▒▒▒▒▒▒" << endl;

    cout << "\n\n" << setw(10) << right << "start -> press 1"
        << "\n" << setw(10) << right << "exit  -> press -1" << "\n>>";
}

void setboard(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < BOARD_HEIGHT; i++) {    // 세로 경계 설정
        board[i][0] = -1;
        board[i][BOARD_WIDTH-1] = -1;
    }

    for (int i = 0; i < BOARD_WIDTH; i++) {    // 가로 경계 설정
        board[0][i] = -1;
        board[BOARD_HEIGHT-1][i] = -1;
    }
}

void printboard(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == -1) cout << "▦";
            else if (board[i][j] == 0) cout << ' ';
            else cout << '▣';
        }cout << endl;
    }
}