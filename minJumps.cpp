#include <bits/stdc++.h>
using namespace std;

int ans(int a[],int n){
    if(a[0] == 0){
        return -1;
    }
    
    int dp[n];
    memset(dp,-1,sizeof(dp));
    
    dp[0] = 0;
    int j = 1;
    for(int i=0;i<n;i++){
        if(dp[i] == -1) { return -1; }
        
        while(j<n && j<=i+a[i]){
               dp[j] = dp[i]+1;
               j++;
        }
        
    }
    
  return dp[n-1];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cout<<ans(a,n)<<"\n";
	}
	return 0;
}
