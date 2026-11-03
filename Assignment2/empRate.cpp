#include <bits/stdc++.h>
using namespace std;
//O(N)
int main(){
    int n; 
    cin>>n;
    vector<int>a(n);
    for(int &x:a) 
        cin>>x;
    int res=0,cnt=0;
    for(int x:a){
        if(x>6) 
            cnt++;
        else 
            cnt=0;
        res=max(res,cnt);
    }
    cout<<res<<endl;
}