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
string board[301];
int vis[301][301];
queue<pair<int, int> > Q;
vector<int> arr;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
			cin >> board[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == '1' && vis[i][j] == 0){
				ans++;
				Q.push({i,j});
				vis[i][j] = 1;
				int num = 1;
				while(!Q.empty()){
					pair<int, int> cur = Q.front(); Q.pop();
					int cx = cur.X;
					int cy = cur.Y;
					for(int dir = 0; dir < 4; dir++){
						int nx = cx + dx[dir];
						int ny = cy + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
						num++;
					}
				}
				arr.push_back(num);
			}	
		}
	}
	sort(arr.begin(), arr.end());
	cout << ans << '\n';
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << '\n';
	}
	
   return 0;
}