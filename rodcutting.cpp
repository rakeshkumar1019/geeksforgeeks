#include<bits/stdc++.h>
using namespace std;
int rodcut(int* price,int n,int* dp){
    
    
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int max_val=INT_MIN;
    for(int i=0;i<n;i++){
        max_val=max(max_val,price[i]+rodcut(price,n-i-1,dp));
    }
    dp[n]=max_val;
    return max_val;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    
    int n;
    cin>>n;
    int* price=new int[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int* dp=new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    
    cout<<rodcut(price,n,dp)<<endl;
    }
}
