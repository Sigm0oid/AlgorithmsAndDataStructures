#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    map<char,int> s1,s2;
    int length1=0,length2=0;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {s1[s[i]]++;length1++;}
    cin>>s;
    for(int i=0;i<s.length();i++)
    {s2[s[i]]++;length2++;}
    ll cmp=0;
    for(auto i=s1.begin();i!=s1.end();i++){
        if(s2.find(i->first)!=s2.end())
        cmp+=min(s2[i->first],i->second);
        //cout<<i->first<<" "<<i->second<<endl;
    }
    //cout<<"cmp "<<cmp<<endl;
    ll diff=length1-cmp;
    cout<<diff+(length2-length1+diff)<<endl;
    }
    return 0;
}
