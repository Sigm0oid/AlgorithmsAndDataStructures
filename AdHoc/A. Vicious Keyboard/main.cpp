#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    ll res=0;
    for(ll i=0;i<s.length()-1;i++){

            if(s[i]=='V'&&s[i+1]=='K'){

            res++;
            }

    }
    for(ll j=0;j<s.length();j++){
    ll ans=0;
    char c=s[j];
    s[j]='V';
    for(ll i=0;i<s.length()-1;i++){

            if(s[i]=='V'&&s[i+1]=='K'){
            ans++;
            }
    }
    res=max(res,ans);
    ans=0;
    s[j]='K';
    for(ll i=0;i<s.length()-1;i++){

            if(s[i]=='V'&&s[i+1]=='K'){
            ans++;
            }
    }
    res=max(res,ans);
    s[j]=c;
        }

    cout<<res<<endl;
    return 0;
}
