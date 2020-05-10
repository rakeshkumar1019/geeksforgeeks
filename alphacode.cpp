#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 10000000007
int alphacode(long long int* arr,int n){
    if(n==0 ||  n==1){
        return 1;
    }
    
    long long int output=alphacode(arr,n-1);
    long long int val = arr[n-2]*10 + arr[n-1];
    if(val >= 10 and val <= 26){
        output=(output)%MOD+(alphacode(arr,n-2))%MOD;
    }
    
    return output;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while(true){
        cin>>s;
        if(s=="0"){
            break;
        }
        long long int* arr=new long long int[s.size()];
        for(long long int i=0;i<s.size();i++){
            arr[i]=s[i]-'0';
            cout<<arr[i]<<" ";
        }
        cout<<"output"<<endl;
        cout<<alphacode(arr,s.size())<<endl;
        
        
    }
}
