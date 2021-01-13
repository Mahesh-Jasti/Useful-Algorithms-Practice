#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
	string s;
	cin >> s;
	string pat;
	cin >> pat;
	int main_buc[256]={0};
	int use_buc[256]={0};
	for(int i=0;i<pat.size();i++) main_buc[pat[i]]++;
	int idx;
	for(idx=0;idx<s.size();idx++){
		use_buc[s[idx]]++;
		bool flag=true;
		for(int i=0;i<256;i++){
			if(use_buc[i]<main_buc[i]) flag=false; 
		}
		if(flag) break;
	}
	if(idx==s.size()){
		cout << "NO\n";
		return 0;
	}
	int mini=idx+1;
	int temp=0;
	while(temp<=idx){
	    bool flag=true;
	    use_buc[s[temp]]--;
	    for(int i=0;i<256;i++){
	        if(use_buc[i]<main_buc[i]) flag=false;
	    }
	    if(flag) temp++;
	    else{
	        use_buc[s[temp]]++;
	        mini=idx-temp+1;
	        break;
	    }
	}
	int j=0;
	for(int i=idx+1;i<s.size();i++){
		use_buc[s[i]]++;
		while(j<i){
			use_buc[s[j]]--;
			bool flag=true;
			for(int k=0;k<256;k++){
				if(use_buc[k]<main_buc[k]){
					flag=false;
					break;
				}
			}
			if(!flag){
				use_buc[s[j]]++;
				//mini=min(mini,i-j+1);
				break;
			}
			else j++;
		}
		mini = min(mini,i-j+1);
	}
	cout << mini << "\n";
	return 0;
}
