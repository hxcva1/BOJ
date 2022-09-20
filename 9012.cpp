#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   	int t;
   	cin >> t;
   	while(t--){
   		stack<char> S;
		string str;
		bool b = false;
		cin >> str;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '(') S.push(str[i]);
			else{
				if(S.empty()){
					b = true;
					break;
				}
				else S.pop();
			}
		}
		if(b == true || !S.empty()){
			cout << "NO" << '\n';
			continue;
		}	
		else cout << "YES" << '\n';
	}
    return 0;
}