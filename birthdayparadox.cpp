//prpbability of not having same birthday of n people is 
//1->365/365 2-> 364/365 3->363/365 ---------------------- 
//p+p'=1| 1-p=p'>=0.6| p<=0.4

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  float prb;
  cin>>prb;
  prb=1-prb;
 float num =365;
 float den=365;
int no=0;
float probability=1;
  
  while(probability>prb){
    probability*=(num/den);
    num--;
    no++;
    //uncomment to debug 
    // cout<<"probability"<<probability<<"no of people"<<no<<endl;
  }
  cout<<no<<endl;

}
