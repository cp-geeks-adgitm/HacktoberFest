class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
     int res[n][m];
int count = 0;
memset(res,0,sizeof(res));
for(vector vc: indices)
{
for(int i = 0; i < m;i++)res[vc[0]][i]++;
for(int i = 0; i < n;i++)res[i][vc[1]]++;
}
for(int i = 0; i < n;i++)
{
for(int j = 0;j < m;j++)
{
if(res[i][j]%2!=0)count++;
}
}
return count;
    }
};
