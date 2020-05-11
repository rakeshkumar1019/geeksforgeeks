#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* den=new int[n+1];
        den[0]=0;
        for(int i=1;i<=n;i++){
            cin>>den[i];
        }
        int val;
        cin>>val;
        
        int arr[n+1][val+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=val;j++){
                if(i==0 && j==0){
                    arr[i][j]=1;
                }else if(i==0 && j>0){
                    arr[i][j]=0;
                }else{
                       if(den[i]>j){
                         arr[i][j]=arr[i-1][j];
                       }else{
                          arr[i][j]=arr[i-1][j]+arr[i][j-den[i]];
                       }
                
                }
                
            }
        }
        cout<<arr[n][val]<<endl;
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=val;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
}
