#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int pivot(int* arr,int l,int r){
    int mid=(l+r)/2;
    if(arr[mid]>arr[mid+1]){
     return mid+1;
    }
    if(arr[l]>arr[mid]){
        return pivot(arr,l,mid-1);
    }else{
        return pivot(arr,mid+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    int * arr=new int[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    
    cout<<pivot(arr,0,n-1);
}
