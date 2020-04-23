#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int * arr=new int[n];
  int * temp=new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  for(int i=0;i<n;i++){
    temp[i]=arr[i];
  }

  for(int i=0;i<n-1;i++){
     while(__gcd(temp[i],temp[i+1])!=1){
            temp[i]=temp[i]-1;
     }
  }
  //  for(int i=0;i<n;i++){
  //   cout<<temp[i]<<"  ";
  // }
  // cout<<endl;

  int count=0;
  for(int i=0;i<n;i++){
    count+=abs(arr[i]-temp[i]);
  }
 cout<<count<<endl;
}
