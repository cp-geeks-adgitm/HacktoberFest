class Solution {
public:
    int minDistance(string A, string B) {
        int i,j,m=A.length(),n=B.length();
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if (i == 0) 
                dp[i][j] = j;
            else if (j == 0) 
                dp[i][j] = i;
                
            else if(A[i-1]==B[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
        }
    }
    return dp[m][n];
        
    }
};