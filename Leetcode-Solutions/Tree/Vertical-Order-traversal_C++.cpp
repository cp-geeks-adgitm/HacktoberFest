/* 
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.


Example 1:

Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

Example 2:
Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 

Note:
• The tree will have between 1 and 1000 nodes.
• Each node's value will be between 0 and 1000.

*/

//SOLUTION

class Solution {
   void dfs(TreeNode* node, int r, int c, unordered_map<int, vector<pair<int, int>>>& cache, int& minC, int& maxC){
        if(node == nullptr) return;
        if(cache.count(c)) cache[c].push_back({r, node->val});
        else cache.insert({c, {{r, node->val}}});
        minC = min(minC, c);
        maxC = max(maxC, c);
        dfs(node->left, r+1, c-1, cache, minC, maxC);
        dfs(node->right, r+1, c+1, cache, minC, maxC);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
                
vector<vector<int>> result;
        if(root == nullptr) return result;
        
        unordered_map<int, vector<pair<int, int>>> cache;
        int minC = 0, maxC = 0;
        dfs(root, 0, 0, cache, minC, maxC);
        
        for(int c = minC; c < maxC+1; ++c){
            sort(cache[c].begin(), cache[c].end(), [](pair<int, int>& p1, pair<int, int>& p2){
                return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });
            vector<int> col;
            for(pair<int, int>& p: cache[c])
                col.push_back(p.second);
            result.push_back(col);
        }
        return result;
    }
};
