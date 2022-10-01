#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int w, h;
int board[1001][1001];
int dist[1001][1001];
int fire[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
    	bool exit = false;
    	int ans;
    	queue<pair<int, int>> Q1, Q2; //queue 초기화
		 
		
    	cin >> h >> w;
    	
    	for (int i = 0; i < w; i++) {
        	fill(dist[i], dist[i]+ h, 0);
        	fill(fire[i], fire[i]+ h, 0);
        }
        
    	for (int i = 0; i < w; i++) {
        	for (int j = 0; j < h; j++) {
        		char c;
            	cin >> c;
            	if (c == '#') board[i][j] = -1; 
				else{
            		if (c == '*') {
                		Q2.push({ i,j });
                		fire[i][j] = 1;
            		}
            		if (c == '@') {
                		Q1.push({ i,j });
                		dist[i][j] = 1;
            		}
            	board[i][j] = 0;
            	}
        	}	
   		}
    	while (!Q2.empty()) {
        	auto cur = Q2.front(); Q2.pop();
        	for (int i = 0; i < 4; i++) {
            	int nx = cur.X + dx[i];
            	int ny = cur.Y + dy[i];
            	if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            	if (board[nx][ny] == -1 || fire[nx][ny] > 0) continue;
            	fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            	Q2.push({ nx, ny });
        	}
    	}
    	
    	while (!Q1.empty() && (!exit)) {
        	auto cur = Q1.front(); Q1.pop();
        	for (int i = 0; i < 4; i++) {
            	int nx = cur.X + dx[i];
            	int ny = cur.Y + dy[i];
            	if(nx < 0 || nx >= w || ny < 0 || ny >= h){
        			exit = true;
        			cout << dist[cur.X][cur.Y] << '\n';
        			break;
				}
            	if(board[nx][ny] == -1 || dist[nx][ny] > 0) continue;
            	if(fire[nx][ny] != 0 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
            	dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            	Q1.push({ nx, ny });
        	}
    	}

    	if (exit == false) {
        	cout << "IMPOSSIBLE" << '\n';
    	}
    	
	}
    return 0;
}