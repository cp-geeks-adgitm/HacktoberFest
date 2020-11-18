package ipTrees;

public class KdistanceNodes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	HashMap<TreeNode,TreeNode> map=new HashMap<>();
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        TreeNode e=new TreeNode(-1);
          map.put(root,e);
        Make(root,map);
        
        List<Integer> list=new ArrayList<>();
        LinkedList<TreeNode> queue=new LinkedList<>();
        queue.add(target);
        boolean[] visited=new boolean[500];
        int level=0;
        while(queue.size()!=0){
            int size=queue.size();
            while(size-->0){
                TreeNode rem=queue.removeFirst();
                if(k==level){
                    list.add(rem.val);
                }
                visited[rem.val]=true;
                
                if(rem.left!=null && !visited[rem.left.val]){
                       queue.add(rem.left);
                }
                 
                if(rem.right!=null && !visited[rem.right.val]){
                    //nodedis n1=new nodedis(rem.right,d);
                    queue.add(rem.right);
                }
                 if(map.get(rem).val!=-1 && visited[map.get(rem).val]==false){
                     //nodedis n2=new nodedis(map.get(rem.node),d);
                     queue.add(map.get(rem));
                 }  
            }
            level++;
            
        }
        return list;
    }
    public void Make(TreeNode node,HashMap<TreeNode,TreeNode> map){
        if(node==null){
            return;
        }
        if(node.left!=null){
            map.put(node.left,node);
        }
        if(node.right!=null){
            map.put(node.right,node);
        }
        Make(node.left,map);
        Make(node.right,map);
    }

}
