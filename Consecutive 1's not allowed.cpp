  //for tutorial 
 //https://www.youtube.com/watch?v=Bq9lgqC1YwE
 //https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
 #include<iostream>
 #include<bits/stdc++.h>
using namespace std;
long long int  count(int n){
  long long int a[n];
  long long int b[n];
  long long mod = pow(10,9)+7;
  a[0]=b[0]=1;
  for(int i=1;i<n;i++){
    a[i]=(a[i-1]%mod+b[i-1]%mod)%mod;
    b[i]=a[i-1]%mod;
  }
  return (a[n-1]%mod+b[n-1]%mod)%mod;

}
 int main(){
   int t;
   cin>>t;
   while(t--){
     long long int  n;
     cin>>n;
    cout<<count(n)<<endl;
   }
 
 }
