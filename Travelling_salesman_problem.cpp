#include<bits/stdc++.h>
using namespace std;
int dp[100][10];
int n = 4;
int dist[10][10] = {
                     {0,10,15,20},
                     {10,0,35,25},
                     {15,35,0,30},
                     {20,25,30,0}
                   };
int VISITED = (1<<n)-1;    // using bit  masking to mark every visited ans non visited city
int tsp(int mask,int prevCity){
	 if(mask == VISITED){
	 	return dist[prevCity][0];
	 }
	 if(dp[mask][prevCity] != -1){
	 	  return dp[mask][prevCity];
	 }
     int ans = INT_MAX;
	
	 for(int newCity = 0; newCity < n; newCity++){
	 	   if((mask & (1<<newCity)) == 0){
			   
                      int minimum = dist[prevCity][newCity] +  tsp(mask|(1<<newCity),newCity);

                         ans = min(ans,minimum);
	 	   }
	 }
	 return dp[mask][prevCity] = ans;
}
int main()
{
	memset(dp,-1,sizeof(dp));
   cout<<tsp(1,0)<<"\n";
}
