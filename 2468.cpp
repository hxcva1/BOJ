#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, mx = 0, ans = 0;
int board[101][101];
int vis[101][101];

queue<pair<int, int> > Q;
int bfs(){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j] == 0){
				Q.push({i,j});
				cnt++;
				while(!Q.empty()){
					pair<int, int> cur = Q.front(); Q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(vis[nx][ny] == 1) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
	}	
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
			mx = max(mx, board[i][j]);
		}
	}
	for(int h = 1; h <= mx; h++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i][j] < h) vis[i][j] = 1;
			}
		}
		ans = max(ans,bfs());
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				vis[i][j] = 0;
			}
		}		
	}
	cout << ans;
   return 0;
}