#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mx=0,cmp=0;
	string s;    
	cin>>s;
	for(int i=0;i<s.length();i++){
	    cmp++;
	if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='Y'){
	mx=max(mx,cmp);
	cmp=0;	
	}
}
	mx=max(mx,cmp+1);
cout<<mx<<endl;
    return 0;
}
	
