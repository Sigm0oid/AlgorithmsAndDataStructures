#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
        int res=0;
        for(int a_i = 0;a_i < n-1;a_i++){
          if((a[a_i]==0)&&(a[a_i+1]==0)){
          res++;
          a[a_i+1]=1;}
         // cout<<a[a_i]<<" ";

        }
        cout<<res<<endl;
    }
    return 0;
}
