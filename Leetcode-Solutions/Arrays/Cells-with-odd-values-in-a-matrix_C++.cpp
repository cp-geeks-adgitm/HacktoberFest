class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans=0;
        vector<vector<int>>arr(n,vector<int>(m,0));
        for(int i=0;i<indices.size();i++){
            for(int j=0;j<n;j++){
                arr[j][indices[i][1]]+=1;
            }
            for(int k=0;k<m;k++){
                arr[indices[i][0]][k]+=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]%2!=0)
                    ans+=1;
            }
        }
        return ans;
    }
};
