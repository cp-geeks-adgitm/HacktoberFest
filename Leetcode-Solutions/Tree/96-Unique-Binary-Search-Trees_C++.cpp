//Contributed by: Rishabh Jain 
//this one is a pure dp soln.
class Solution {
public:
    int numTrees(int n)
    {int dp[n+1];
     memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
     dp[3]=5;
     
     for(int i=4;i<=n;i++)
     {
         for(int j=1;j<=i;j++)
         {
             dp[i]+=dp[j-1]*dp[i-j];
         }
     }
       return dp[n];
        
    }
};
