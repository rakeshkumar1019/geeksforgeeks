#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minimum(int x,int y,int z){
  return min(x,min(y,z));
}

int minDistanceHelper(string word1,string word2,int s1,int s2){
  int**dp=new int*[s1+1];
  //2d dp array
  for(int i=0;i<=s1;i++){
    dp[i]=new int[s2+1];
    for(int j=0;j<=s2;j++){
      dp[i][j]=-1;
    }
  }
  //main function code
  for(int i=0;i<=s1;i++){
    for(int j=0;j<=s2;j++){
      if(i==0){
        dp[i][j]=j;
      }
      else if(j==0){
        dp[i][j]=i;
      }
     else if(word1[i-1]==word2[j-1]){
        dp[i][j]=dp[i-1][j-1];
      }
      else{
        dp[i1[j]=1+minimun(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
      }

    }
  }

   return dp[s1][s2];
}
int minDistance(string word1, string word2){
  int s1=word1.length();
  int s2=word2.length();
  return minDistanceHelper(word1,word2,s1,s2);
}
int main(){
  string word1,word2;
  cin>>word1>>word2;
  cout<<minDistance(word1,word2);
}
