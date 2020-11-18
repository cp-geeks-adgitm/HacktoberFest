/*Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    
    public String helper1(TreeNode root, String res){
        if(root==null){
            res+='#';
            res+=' ';
            return res;
        }
        res+= root.val+" ";
        res = helper1(root.left , res);
        res = helper1(root.right , res);
        return res;
    }
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root==null)
            return null;
        String ans = helper1(root, "");
        System.out.println(ans);
        return ans;
    }
    
    
    public TreeNode helper2(String[] arr, int[] idx){
      
        
        if(arr[idx[0]].equals("#")){
            return null;
        }
        
        TreeNode root = new TreeNode(Integer.parseInt(arr[idx[0]]));
        
        idx[0]+=1;
        root.left = helper2(arr, idx);
        idx[0]+=1;
        root.right = helper2(arr, idx);
        return root;
    }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data==null)
            return null;
        String[] arr = data.split(" ");
        int[] idx = {0};
        TreeNode root = helper2(arr,idx);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;