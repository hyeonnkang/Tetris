#pragma once

#define BOARD_WIDTH 10  // 테트리스 보드의 가로 길이
#define BOARD_HEIGHT 20 // 테트리스 보드의 세로 길이

#define SCORE_WIDTH 10		// 점수판의 가로 길이
#define SCORE_HEIGHT 5		// 점수판의 세로 길이
#define LEVEL_WIDTH 10		// 레벨판의 가로 길이
#define LEVEL_HEIGHT 5		// 레벨판의 세로 길이
#define NEXT_WIDTH 10		// 다음 나올 블록판의 가로 길이
#define NEXT_HEIGHT 10		// 다음 나올 블록판의 세로 길이

class Board
{
private:
	int board[BOARD_HEIGHT][BOARD_WIDTH+ SCORE_WIDTH]; // 테트리스 보드판. 경계는 -1, 공백은 0, 블럭은 1;
	int score;	// 점수
	int level;  // 레벨
public:

	Board() {
		setboard();

		this->score = 0;
		this->level = 1;
	}

	void setboard();    // 테트리스 게임판 설정 함수
	void print();  // 테트리스 게임판 그리기 함수
};

