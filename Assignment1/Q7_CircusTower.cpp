#include <bits/stdc++.h>
//O(N^2)
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>p(n);
    for(auto &x:p)
    {
        cin>>x.first>>x.second;
    }
    sort(p.begin(),p.end());
    vector<int>dp(n,1);
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].first < p[i].first && p[j].second < p[i].second)
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
        }
    }
    cout<<ans<<endl;
}