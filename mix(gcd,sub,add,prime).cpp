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
    return sum;
}
int sub(int a,int b){
    int sum,carry;
    while(b!=0){
    sum=a^b;
    carry=~a&b;
    a=a^b;
    b=carry<<1;
    }
    return sum;
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    gcd(b,a%b);
}
void prim_no(int n){
    bool* arr=new bool[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++){
        if(arr[i]==true){
            for(int j=i*i;j<=n;j+=i){
                arr[j]=false;
            }
        }
    }
    //O(nloglogn^(1/2))
    for(int i=0;i<=n;i++){
        if(arr[i]==true){
            cout<<i<<" ";
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b;
    cin>>a>>b;
   cout<< add(a,b)<<endl;
   cout<<sub(a,b)<<endl;
   cout<<gcd(a,b)<<endl;
   prim_no(b);
   
}
