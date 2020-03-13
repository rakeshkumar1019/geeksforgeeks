//this program is for minimum edits to make string1 to string 2 using recursive and dynamic programming 
//O(n*m)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
  return min(min(b,c),a);
}
int  editdistancehelper(string s1,string s2,int size1, int size2){
int**dp=new int*[size1+1];

for(int i=0;i<=size1;i++){
  dp[i]=new int[size2+1];
  for(int j=0;j<=size2;j++){
    dp[i][j]=-1;
  }
}

if(size1==0){
  dp[size1][size2]=size2;
  return size2;
}

if(size2==0){
  dp[size1][size2]=size1;
  return size1;
}
if(dp[size1][size2]!=-1){
  return dp[size1][size2];
}
if(s1[size1-1]==s2[size2-1]){
 int res1=editdistancehelper( s1,s2, size1-1, size2-1);//both string lenght decreseses to -1
 dp[size1][size2]=res1;
 return res1;
}else{
  int res= 1+min(
    editdistancehelper(s1,s2, size1, size2-1),//insert int string1 so string to become s2-1 as compare to s1
    editdistancehelper(s1,s2, size1-1,  size2),//delete in string1 so string s1 become s1-1 as compare to s2
    editdistancehelper(s1, s2, size1-1,  size2-1)//modify or replace so both strings are decreses to -1 as they become same char 
  );
  dp[size1][size2]=res;
  return res;
}



}

int  minDistance(string word1,string word2){
int size1=word1.length();
int size2=word2.length();
  return  editdistancehelper(word1,word2,size1,size2);
}

int main(){
  string s1;
  string s2;
  cin>>s1>>s2;
  cout<<minDistance(s1,s2);

}
