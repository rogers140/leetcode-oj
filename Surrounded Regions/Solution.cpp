#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char> >& board) {
		if (board.size() <= 2 || board[0].size() <= 2) // can not form a surrounding
			return;
		// From outside to inside, find every 'O' it can reach and mark it as 'M'
		for (int i = 0; i < board[0].size(); ++i) {  // Top row
			penetrate(0, i, board);
		}
		for (int i = 1; i < board.size(); ++i) {  // Right column
			penetrate(i, board[0].size() - 1, board);
		}
		for (int i = 0; i < board[0].size() - 1; ++i) {  // Bottom row
			penetrate(board.size() - 1, i, board);
		}
		for (int i = 1; i < board.size() - 1; ++i) {  // Left column
			penetrate(i, 0, board);
		}
		for(int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				board[i][j] = board[i][j] == 'M' ? 'O' : 'X';
			}
		}
	}
	void penetrate(int i, int j, vector<vector<char> >& board) {
		if (board[i][j] == 'X' || board[i][j] == 'M')
			return;
		board[i][j] = 'M';
		// Left
		if (j - 1 > 0) penetrate(i, j - 1, board);
		// Right
		if (j + 1 < board[0].size()) penetrate(i, j + 1, board);
		// Top
		if (i - 1 > 0) penetrate(i - 1, j, board);
		// Bottom	
		if (i + 1 < board.size()) penetrate(i + 1, j, board);
	}
};
int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	// vector<vector<char> > board(5, vector<char>(5, 'X'));
	// board[0][0] = 'O';
	// board[0][3] = 'O';
	// board[1][1] = 'O';
	// board[1][2] = 'O';
	// board[1][4] = 'O';
	// board[2][1] = 'O';
	// board[2][3] = 'O';
	// board[3][0] = 'O';
	// board[3][2] = 'O';
	// board[3][3] = 'O';
	// board[3][4] = 'O';
	// board[4][2] = 'O';
	// board[4][4] = 'O';

	vector<vector<char> > board(4, vector<char>(6, 'X'));
	board[0][1] = 'O';
	board[0][3] = 'O';
	board[0][5] = 'O';

	board[1][0] = 'O';
	board[1][2] = 'O';
	board[1][4] = 'O';

	board[2][1] = 'O';
	board[2][3] = 'O';
	board[2][5] = 'O';

	board[3][0] = 'O';
	board[3][2] = 'O';
	board[3][4] = 'O';
	
	cout<<"Before:"<<endl;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	s->solve(board);
	cout<<"After:"<<endl;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}