class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> A(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                A[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= A[i][j];
                colSum[j] -= A[i][j];
            }
        }
        return A;
    }
};
