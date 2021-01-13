#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
	string s;
	getline(cin,s);
	stack<string> ans;
	for(int i=0;i<s.size();){
		string temp="";
		while(s[i]!=' ' && i<s.size()){
			temp.push_back(s[i]);
			i++;
		}
		ans.push(temp);
		i++;
	}
	while(!ans.empty()){
		cout << ans.top();
		ans.pop();
		if(ans.empty()) break;
		cout << " ";
	}
	return 0;
}

