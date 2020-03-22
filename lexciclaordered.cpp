#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void lexhelper(long long int curr, vector<long long int> &res,long long int n){
      if(curr>n){
		  return;
	  }
	  res.push_back(curr);
	  lexhelper(curr*10,res,n);
	  if(curr%10!=9){
		  lexhelper(curr+1,res,n);
	  }
}
vector<long long int> lexorder(vector<long long int> res,long long int n){
	vector<long long int> ans;
    lexhelper(1,res,n);
	return res;
}
int main() {
	long long int n;
	cin>>n;
	vector<long long int> res;
	res.push_back(0);
	res=lexorder(res,n);
	for(long long int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
