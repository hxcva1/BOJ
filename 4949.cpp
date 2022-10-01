#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
    	stack<char> s;
    	string str = "";
    	bool done = false;
    	getline(cin, str);
    	if(str[0] == '.' && str.size() == 1) break;
    	for(int i = 0; i < str.size(); i++){
    		if(str[i] == '[' || str[i] == '('){
    			s.push(str[i]);
    			continue;
			}
			if(str[i] == ']'){
    			if(!s.empty() && s.top() == '[') s.pop();
    			else {
    				done = true;
    				break;
				}
			}
			if(str[i] == ')'){
    			if(!s.empty() && s.top() == '(') s.pop();
    			else {
    				done = true;
    				break;
				}
			}		
		}
		if(done) {
			cout << "no" << '\n';
			continue;
		}
		if(s.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
    
    return 0;
}