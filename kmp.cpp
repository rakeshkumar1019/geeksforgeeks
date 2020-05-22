 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int* lpsfind(string partten,int n){
  int* lps=new int[n];
    int j=0;
    int i=1;
    lps[0]=0;
   while(i<n){
      if(partten[i]==partten[j]){
        lps[i]=j+1;
        i++;
        j++;
      }else{
        if(j!=0){
          j=lps[j-1];
        }else{
          lps[i]=0;
          i++;
        }
      }
    }
    return lps;
}
int main(){
  string s1,s2;
  cin>>s1>>s2;
  int n1=s1.size();
  int n2=s2.size();
  int* lps=new int[n2];
  lps=lpsfind(s2,n2);
  int i=0;
  int j=0;
   while(i<n1 && j<n2){
     if(s1[i]==s2[j]){
       i++;
       j++;
     }else{
       if(j!=0){
         j=lps[j-1];
       }else{
         i++;
       }
     }

   }
   int res=-1;
   if(j==n2){
     res=i-j;
   }
   cout<<res<<endl;
}
