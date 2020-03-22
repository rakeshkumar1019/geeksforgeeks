#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int> &nums){
  vector<vector<int>> res;
  int size=nums.size();
  int subsets=(1<<size);//2^size
   for(int i=0;i<subsets;i++){
    vector<int> temp;
    for(int j=0;j<size;j++){
      if(i&(1<<j)){
        temp.push_back(nums[j]);
      }
    }
    
    res.push_back(temp);
  }
   
  return res;
}
int main(){
  int n;
  cin>>n;
  vector<int> nums;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    nums.push_back(a);
  }
  vector<vector<int>> res;
  res=subsets(nums);
  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
  
}
