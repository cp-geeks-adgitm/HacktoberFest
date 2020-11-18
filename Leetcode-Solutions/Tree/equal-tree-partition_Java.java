public class Solution {
	    /**
	     * @param root: a TreeNode
	     * @return: return a boolean
	     */
	     public class pair{
	         
	         boolean found=false;
	         int sum=0;
	         pair(int sum,boolean found){
	             this.sum=sum;
	             this.found=found;
	         }
	         pair(){
	             
	         }
	     }
	    public boolean checkEqualTree(TreeNode root){
	        // write your code here
	        int tsum=sum(root);
	        pair ans=findhalf(root,tsum,root);
	        return ans.found;
	    }
	    
	    public pair findhalf(TreeNode root,int tsum,TreeNode oroot){
	        if(root==null) return new pair(0,false);
	        pair left=findhalf(root.left,tsum,oroot);
	        pair right=findhalf(root.right,tsum,oroot);
	        pair mypair=new pair();
	        mypair.sum=left.sum+right.sum+root.val;
	        
	        if(root!=oroot){
	             mypair.found=(left.found || right.found || mypair.sum*2==tsum);
	        }else{
	             mypair.found=(left.found || right.found);
	        }
	       
	        return mypair;
	    }
	    
	    public int sum(TreeNode root){
	        if(root==null) return 0;
	        return sum(root.left)+sum(root.right)+root.val;
	    }
	}
