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

int n, m, max = 0;
int board[301][301];
int dist[301][301];
queue<pair<int, int> > Q;
int arr[100];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0, ans = 0;
	int k, n, m, x1, y1, x2, y2;
	cin >> n >> m >> k;

	while(k--){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = x1; i < x2; i++){
			for(int j = y1; j < y2; j++){
				board[j][i] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 0){
				ans++;
				Q.push({i,j});
				board[i][j] = 1;
				int num = 0;
				while(!Q.empty()){
					num++;
					pair<int, int> cur = Q.front(); Q.pop();
					int cx = cur.X;
					int cy = cur.Y;
					for(int dir = 0; dir < 4; dir++){
						int nx = cx + dx[dir];
						int ny = cy + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if(board[nx][ny] == 1) continue;
						board[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
				arr[cnt] = num;
		    	cnt++;
			}
				
		}
	}
	sort(arr, arr+cnt);
	cout << ans << '\n';
	for(int i = 0; i < cnt; i++){
		cout << arr[i] << ' ';
	}
	
   return 0;
}