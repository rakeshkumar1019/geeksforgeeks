#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int add(int a,int b){
    int sum,carry;
 while(b!=0){
    sum=a^b;
    carry=a&b;
    a=a^b;
    b=carry<<1;
 }
 cout<<sum<<endl;
}
int main(){
    int a,b;
    cin>>a>>b;
    add(a,b);
}
