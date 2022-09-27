#include <bits/stdc++.h>

using namespace std;

int nums[30];
char oper[30];
int n, op_size;
long long ans = -10000000000;

long long cal(int a, int b, char c){
	if(c == '+') return a + b;
	else if(c == '-') return a - b;
	else return a * b;
}

void dfs(int idx, long long cur){
	if(idx >= op_size){
		ans = max(ans, cur);
		return; 
	}
	dfs(idx+1, cal(cur,nums[idx+1], oper[idx])); 
	if(oper[idx+1] != 0){
		long long tmp = cal(nums[idx+1],nums[idx+2], oper[idx+1]);
		dfs(idx+2, cal(cur, tmp, oper[idx]));
	} 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
		
	cin >> n; 
	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(i%2 == 0){
			nums[a] = c - '0';
			a++; 
		}
		else{
			oper[b] = c;
			b++;
		}
	}
	op_size = b;	
	dfs(0, nums[0]);
	cout << ans;
	
    return 0;
}