#include <bits/stdc++.h>

using namespace std;
vector<char>pattern;
int r,g,y,b;
char tab[4]={'R','B','Y','G'};
int tab1[4]={0};
void add()
{
auto p=find(pattern.begin(),pattern.end(),'*');
while(p!=pattern.end())
{
for(int i=0;i<4;i++){
if(tab1[i]==0)
    {
    pattern[p-pattern.begin()]=tab[i];
    tab1[i]++;
    break;
    }
}
p=find(pattern.begin(),pattern.end(),'*');
}
}
int main()
{
    string s;
    cin>>s;
    pattern.assign(4,'*');
    for(int i=0;i<s.length();i++){
    if (s[i]!='!')
    pattern[i%4]=s[i];
    }
    add();
    for(int i=0;i<s.length();i++){
    if(s[i]=='!')
    {
        char c=pattern[i%4];
        if(c=='R')
        tab1[0]++;
        if(c=='B')
        tab1[1]++;
        if(c=='Y')
        tab1[2]++;
        if(c=='G')
        tab1[3]++;
    }
    }
//    cout<<pattern<<endl;
    cout<<tab1[0]<<" "<<tab1[1]<<" "<<tab1[2]<<" "<<tab1[3]<<endl;
    return 0;
}
