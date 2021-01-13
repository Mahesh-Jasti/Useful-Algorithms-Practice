#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int KMP(vector<int> &lps, string &text, string &pat){
	int j=0;
	for(int i=0;i<text.size();){
		if(pat[j]==text[i]){
			i++;
			j++;
			if(j==pat.size()) return i-pat.size();
		}
		else if(j>0) j=lps[j-1];
		else i++;
	}
	return -1;
}

void LPS(vector<int> &lps, string &pat){
	int j=0;
	lps.push_back(0);
	for(int i=1;i<pat.size();){
		if(pat[i]==pat[j]){
			lps.push_back(j+1);
			i++;
			j++;
		}
		else if(j>0) j=lps[j-1];
		else{
			lps.push_back(0);
			i++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
	string text,pat;
	cin >> text >> pat;
	vector<int> lps;
	LPS(lps,pat);
	int ans = KMP(lps,text,pat);
	//for(int i=0;i<lps.size();i++) cout << lps[i] << " ";
	//cout << "\n";
	cout << ans << "\n";
	return 0;
}
