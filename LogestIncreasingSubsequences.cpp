#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int lis(int* input,int n){
    int* output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++){
         output[i]=1;
        for(int j=i-1;j>=0;j--){
            
            if(input[i]>input[j] && output[i]<output[j]+1){
                output[i]=output[j]+1;
            }
           
             
        }
    }
    
    //find height element form output
    int ans=0;
    for(int i=0;i<n;i++){
        if(output[i]>ans){
            ans=output[i];
        }
    }
    //deleteing output array
    
        delete [] output;

    return ans;
    
}
int main() {
	//code
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int* input=new int[n];
	    for(int i=0;i<n;i++){
	        cin>>input[i];
	    }
	    int ans=lis(input,n);
	    cout<<ans<<endl;
	}
	
	
	return 0;
}
