#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m, d;
int cnt = 0, ans = 0;
int board[20][20];
int tmp[20][20];

int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};

int dist[20][20];
int arc_loc[11]; // 궁수의 위치
bool visited[16];// 방문여부 
queue<pair<int,int>> kill_list;


// 끝났는지 확인
bool finish(){
	bool end = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 1) end = false;
		}
	}
	return end;
} 
//한턴지나기
void move(){
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(board[i][j] == 1){
				if(i== n-1){
					board[i][j] = 0;
				}
				else{
					board[i][j] = 0;
					board[i+1][j] = 1;	
				}
			}
		}
	}
} 
void bfs(){
	for(int loc = 0; loc < 3; loc++){
		queue<pair<int, int>> Q;
		dist[n-1][arc_loc[loc]] = 1;
		Q.push({n-1, arc_loc[loc]});
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			if(dist[cur.X][cur.Y] > d){
				continue;
			}
			if(board[cur.X][cur.Y] == 1){
				kill_list.push({cur.X,cur.Y});
				break;
			}
			for(int dir = 0; dir < 3; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if(dist[nx][ny] > 0 ) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({nx,ny});
			}
		}
		for(int i = 0; i < n; i++){
			fill(dist[i], dist[i]+m,0);
		}
	}
	int s = kill_list.size();
	for(int i = 0; i < s; i++){
		auto target = kill_list.front(); kill_list.pop();
		int tx = target.X;
		int ty = target.Y;
		if(board[tx][ty] == 1){
			board[tx][ty] = 0;
			cnt++;
		}
	}
}
// 잡는 함수 
void stage(){
	while(1){
		bfs();
		move();
		if(finish()) break;
	}
}

// 궁수를 배치하는 함수 
void location(int idx, int count){
	if(count == 3){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				board[i][j] = tmp[i][j];
			}
		}
		stage();
		ans = max(ans,cnt);
		cnt = 0;
		return;
	}
	else{
		for(int i = idx; i < m; i++){
			if(visited[i] == true) continue;
			visited[i] = true;
			arc_loc[count] = i;
			location(i, count+1);
			visited[i] = false;
		}
	}
} 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m >> d;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tmp[i][j] = board[i][j];
		}
	}
	location(0, 0);
	cout << ans;
}