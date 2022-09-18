#include <bits/stdc++.h>

using namespace std;


int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int l, r, c;
char board[31][31][31];
int minute[31][31][31];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int gx, gy, gz;

	while(1){
		tuple<int, int, int> cur;
		queue<tuple<int, int, int> > Q;
    	cin >> l >> r >> c;
    	if(l == 0 && r == 0 && c == 0) break;
    	// time 초기화 
    	for (int i = 0; i < l; i++) {
        	for (int j = 0; j < r; j++) {
            	for (int k = 0; k < c; k++) {
                		minute[i][j][k] = 0; 
            	}
            }
        }
    
    	
    	for (int i = 0; i < l; i++) {
        	for (int j = 0; j < r; j++) {
            	for (int k = 0; k < c; k++) {
                	cin >> board[i][j][k];
                	if (board[i][j][k] == 'S') {
                    	Q.push(make_tuple(i,j,k));
                    	minute[i][j][k] = 1;
                	}
                	if (board[i][j][k] == 'E'){
                		gx = i;
                		gy = j;
                		gz = k;
					}
            	}
        	}
    	}
    	
    	while (!Q.empty()) {
        	cur = Q.front(); Q.pop();
        	if(board[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 'E') break;
        	for (int i = 0; i < 6; i++) {
            	int nx = get<0>(cur) + dx[i];
            	int ny = get<1>(cur) + dy[i];
            	int nz = get<2>(cur) + dz[i];
            	if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >=c ) continue;
            	if (minute[nx][ny][nz] > 0 || board[nx][ny][nz] == '#') continue;
            	minute[nx][ny][nz] = minute[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            	Q.push(make_tuple(nx,ny,nz));
        	}	
    	}
    	
    	if(minute[gx][gy][gz] == 0){
    		cout << "Trapped!" << '\n';
		} 
		else{
			cout << "Escaped in " << minute[gx][gy][gz] - 1 << " minute(s)." << '\n';
		}
	}
    return 0;
}