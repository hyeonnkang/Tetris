#include "Board.h"
#include <iostream>
using namespace std;


void Board::setboard() {
    // 총 블럭 공백으로 초기화
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH + SCORE_WIDTH; j++) {
            board[i][j] = 0;
        }
    }

    // 실제 게임 보드 초기화
    for (int i = 0; i < BOARD_HEIGHT; i++) {    // 세로 경계 설정
        board[i][0] = -1;
        board[i][BOARD_WIDTH - 1] = -1;
    }

    for (int i = 0; i < BOARD_WIDTH; i++) {    // 가로 경계 설정
        board[0][i] = -1;
        board[BOARD_HEIGHT - 1][i] = -1;
    }

    // 점수판 경계 초기화
    for (int i = 0; i < SCORE_HEIGHT; i++) {    // 세로 경계 설정
        board[i][BOARD_WIDTH] = -1;
        board[i][BOARD_WIDTH + SCORE_WIDTH - 1] = -1;
    }

    for (int i = BOARD_WIDTH; i < BOARD_WIDTH+SCORE_WIDTH; i++) {    // 가로 경계 설정
        board[0][i] = -1;
        board[SCORE_HEIGHT - 1][i] = -1;
    }
    for (int i = BOARD_WIDTH + 2; i < BOARD_WIDTH + LEVEL_WIDTH - 1; i++) { // 텍스트 적는 부분 설정
        board[2][i] = 1;
    }

    // 레벨판 경계 초기화
    for (int i = SCORE_HEIGHT; i < SCORE_HEIGHT+LEVEL_HEIGHT; i++) {    // 세로 경계 설정
        board[i][BOARD_WIDTH] = -1;
        board[i][BOARD_WIDTH + LEVEL_WIDTH - 1] = -1;
    }

    for (int i = BOARD_WIDTH; i < BOARD_WIDTH + LEVEL_WIDTH; i++) {    // 가로 경계 설정
        board[SCORE_HEIGHT][i] = -1;
        board[SCORE_HEIGHT + LEVEL_HEIGHT - 1][i] = -1;
    }

    for (int i = BOARD_WIDTH + 2; i < BOARD_WIDTH + LEVEL_WIDTH - 1; i++) { // 텍스트 적는 부분 설정
        board[SCORE_HEIGHT +2][i] = 1;
    }

    // 다음 블럭이 나오는 판 경계 초기화
    for (int i = SCORE_HEIGHT + LEVEL_HEIGHT; i < BOARD_HEIGHT; i++) {    // 세로 경계 설정
        board[i][BOARD_WIDTH] = -1;
        board[i][BOARD_WIDTH + NEXT_WIDTH - 1] = -1;
    }

    for (int i = BOARD_WIDTH; i < BOARD_WIDTH + NEXT_WIDTH; i++) {    // 가로 경계 설정
        board[SCORE_HEIGHT + LEVEL_HEIGHT][i] = -1;
        board[BOARD_HEIGHT - 1][i] = -1;
    }

    for (int i = BOARD_WIDTH + 2; i < BOARD_WIDTH + LEVEL_WIDTH - 1; i++) { // 텍스트 적는 부분 설정
        board[SCORE_HEIGHT + LEVEL_HEIGHT + 2][i] = 1;
    }
}

void Board::print() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        // 게임 보드판 출력
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == -1) cout << "▦";
            else if (board[i][j] == 0) cout << "  ";
            else cout << '▣';
        }

        if (i >= 0 && i < SCORE_HEIGHT) {
            // 점수판 출력
            cout << "\t";
            for (int j = BOARD_WIDTH; j < BOARD_WIDTH + SCORE_WIDTH; j++) {
                if (board[i][j] == -1) cout << "▦";
                else if (board[i][j] == 1) {
                    if (j == BOARD_WIDTH+2) cout << "현";
                    else if (j == BOARD_WIDTH + 3) cout << "재";
                    else if (j == BOARD_WIDTH + 4) cout << "점";
                    else if (j == BOARD_WIDTH + 5) cout << "수";
                    else if (j == BOARD_WIDTH + 6) cout << " :";
                    else if (j == BOARD_WIDTH + 7) cout << (score/10)%10;
                    else cout << score%10 << "  ";
                }
                else cout << "  ";
            }
        }
        else if (i >= SCORE_HEIGHT && i < SCORE_HEIGHT + LEVEL_HEIGHT) {
            // 레벨판 출력
            cout << "\t";
            for (int j = BOARD_WIDTH; j < BOARD_WIDTH + LEVEL_WIDTH; j++) {
                if (board[i][j] == -1) cout << "▦";
                else if (board[i][j] == 1) {
                    if (j == BOARD_WIDTH + 2) cout << "현";
                    else if (j == BOARD_WIDTH + 3) cout << "재";
                    else if (j == BOARD_WIDTH + 4) cout << "레";
                    else if (j == BOARD_WIDTH + 5) cout << "벨";
                    else if (j == BOARD_WIDTH + 6) cout << " :";
                    else if (j == BOARD_WIDTH + 7) cout << (level / 10) % 10;
                    else cout << level << "  ";
                }
                else cout << "  ";
            }
        }
        else {
            // 다음에 나올 블럭 출력
            cout << "\t";
            for (int j = BOARD_WIDTH; j < BOARD_WIDTH + NEXT_WIDTH; j++) {
                if (board[i][j] == -1) cout << "▦";
                else if (board[i][j] == 1) {
                    if (j == BOARD_WIDTH + 2) cout << "다";
                    else if (j == BOARD_WIDTH + 3) cout << "음";
                    else if (j == BOARD_WIDTH + 4) cout << "블";
                    else if (j == BOARD_WIDTH + 5) cout << "록";
                    else if (j == BOARD_WIDTH + 6) cout << " :";
                    else if (j == BOARD_WIDTH + 7) cout << (level / 10) % 10;
                    else cout << level << "  ";
                }
                else cout << "  ";
            }
        }
        
        cout << endl;
    }
}