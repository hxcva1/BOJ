//바킹독님의 풀이 방식과 차이가 난다. 다시 한번 바킹독님의 풀이 방식을 참고하자!

#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
int vis[10];
vector<int> used;
vector<int> output;

void func(int cnt, int idx){
	if(cnt == m){
	int sum = 0;
		bool use = false;
		for(int i = 0; i < output.size(); i++){
			sum = output[i] + (sum * 10);
		}
		for(int i = 0; i < used.size(); i++){
			if(sum == used[i]){
				use = true;
				break;
			}
		}
		if(use){
			return;
		}
		else{
			used.push_back(sum);
			for(int i = 0; i < output.size(); i++){
				cout << output[i] << ' ';
			}
			cout << '\n';
			return;
		}
	}
	for(int i = 0; i < n; i++){
		if(vis[i] == 1) continue;
		vis[i] = 1;
		output.push_back(arr[i]);
		func(cnt + 1, idx + 1);
		output.pop_back();
		vis[i] = 0;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	func(0, 0);
	
    return 0;
}