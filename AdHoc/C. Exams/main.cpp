#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<pair<ll,ll> > exams;
int main()
{
    int n;
    cin>>n;
    exams.resize(n);
    int tmp=n;
    int i=0;
    while(tmp--){
    cin>>exams[i].first;
    cin>>exams[i].second;
    i++;
    }
    sort(exams.begin(),exams.end());
    ll lastday=exams[0].second;
    for(int i=1;i<n;i++){
    if(lastday<=exams[i].second)
    lastday=exams[i].second;
    else
    lastday=exams[i].first;
    }
    cout<<lastday<<endl;



    return 0;
}
