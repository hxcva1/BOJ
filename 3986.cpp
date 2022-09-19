#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   	int n;
   	cin >> n;
   	int cnt = 0;
   	for(int i = 0; i < n; i++){
   		stack<char> s;
   		string str = "";
   		cin >> str;
   		for(int j = 0; j < str.size(); j++){
   			if(s.empty()){
   				s.push(str[j]);
   				continue;	
			}
			else{
				if(s.top() == str[j]) s.pop();
				else s.push(str[j]);	
			}		
		}
		if(s.empty()) cnt++; 
	}
    cout << cnt;
    return 0;
}