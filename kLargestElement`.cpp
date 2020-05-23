#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int* arr,int n ,int i){
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n && arr[left]>arr[largest]){
         largest=left;
  }
  if(right<n && arr[right]>arr[largest]){
    largest=right;
  }
  if(largest!=i){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
  }
}

void heapsort(int* arr,int n,int k){
  for(int i=n/2-1;i>=0;i--){
    heapify(arr,n,i);
  }
  int count=0;
  
  for(int i=n-1;i>0;i--){
    if(count<k){
      swap(arr[0],arr[i]);  
      heapify(arr,i,0);
      count++;
    }
  }
}
int main(){
  int n;
  cin>>n;
  int* arr=new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int k;
  cin>>k;
  heapsort(arr,n,k);
   for(int i=n-1;i>n-k-1;i--){
    cout<<arr[i]<<" ";
  }
}
