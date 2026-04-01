#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[1001];
int dp[1001];
int DP(int n){
	if (n==0) return dp[0];
	if (dp[n]!=-1) return dp[n];
	dp[n]=data[n];
	for (int i=0;i<(n/2+n%2);i++){
		if((DP(n-i-1)+DP(i))>dp[n]){
			dp[n]=DP(n-i-1)+DP(i);
		}
	}
	return dp[n];
}
	
	
	
int main(){
	int n;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	dp[0]=data[0];
	printf("%d",DP(n-1));
	return 0;
}
