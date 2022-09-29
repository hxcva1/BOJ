#include <bits/stdc++.h>

using namespace std;

int n;
int board[20][20];
int cnt = 0;
// state = 0 가로, state = 1 세로 state = 2 대각선 
void dfs(int x, int y, int state){
	if(x == n || y == n) return;
	if(x == n-1 && y == n-1){
		cnt++;
		return;
	} 
	if(state == 0){
		if(board[x][y+1] != 1) {
			dfs(x, y+1, 0);
		}
		if(board[x+1][y] != 1 && board[x+1][y+1] != 1 && board[x][y+1] != 1){
			dfs(x+1, y+1, 2);
		}
	}
	else if(state == 1){
		if(board[x+1][y] != 1) dfs(x+1, y, 1);
		if(board[x+1][y] != 1 && board[x+1][y+1] != 1 && board[x][y+1] != 1){
			dfs(x+1, y+1, 2);
		}
	}
	else{
		if(board[x+1][y] != 1) dfs(x+1, y, 1);
		if(board[x][y+1] != 1) dfs(x, y+1, 0);
		if(board[x+1][y] != 1 && board[x+1][y+1] != 1 && board[x][y+1] != 1){
			dfs(x+1, y+1, 2);
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	dfs(0,1,0);
	cout << cnt;

	
    return 0;
}