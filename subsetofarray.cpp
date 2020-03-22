#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int subset=(1<<n);
    for(int i=0;i<subset;i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;

    }

    return 0;


}
