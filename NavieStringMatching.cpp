#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int navie(string s1,string s2){
  int n1=s1.size();
  int n2=s2.size();

  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
      if(s1[i+j]==s2[j]){
        if(j==n2-1){
           return i;
        }

      } 
        
    }
  }
  return -1;
}
int main(){
  string s1,s2;
  cin>>s1>>s2;
  cout<<navie(s1,s2)<<endl;
}
