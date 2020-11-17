package LinkedList;

public class MergeKList {

	public static void main(String[] args) {
		
	}
	//MergeSOrt Method
	 public ListNode mergeKLists(ListNode[] lists) {
	       if(lists.length==0){
	           return null;
	       }
	        ListNode ans= mergek(lists,0,lists.length-1);
	      return ans;
	     }
	    public ListNode mergek(ListNode[] lists,int i,int j){
	        if(i==j){
	            return lists[i];
	        }
	        
	        int mid=(i+j)/2;
	        
	        ListNode left=mergek(lists,i,mid);
	        ListNode right=mergek(lists,mid+1,j);
	        ListNode res=merge(left,right);
	        return res;
	    }
//	Iterative Method
//	 public ListNode mergeKLists(ListNode[] lists) {
//	        if(lists.length==0){
//	            return null;
//	        }else if(lists.length==1){
//	            return lists[0];
//	        }
//	        ListNode m=merge(lists[0],lists[1]);
//	        for(int i=2;i<lists.length;i++){
//	            m=merge(m,lists[i]);
//	        }
//	        return m;
//	    }
	    
	     public ListNode merge(ListNode l1, ListNode l2) {
	        if(l1==null ){
	            return l2;
	        }else if(l2==null){
	            return l1;
	        }
	        
	        ListNode nhead=new ListNode(0);// sath sath add krke chalo resukt linklist me node
	        ListNode curr=nhead;
	        while(l1!=null && l2!=null){
	            
	            if(l1.val<=l2.val){
	                curr.val=l1.val;
	                l1=l1.next;
	            }else{
	                curr.val=l2.val;
	                l2=l2.next;    
	            }
	          if(l1!=null || l2!=null){
	            curr.next=new ListNode(0);
	            curr=curr.next;  
	          }   
	        }
	        while(l1!=null){
	                curr.val=l1.val;
	                l1=l1.next;
	           
	            if(l1!=null || l2!=null){
	            curr.next=new ListNode(0);
	            curr=curr.next;
	            }
	        }
	        while(l2!=null){
	                curr.val=l2.val;
	                l2=l2.next;
	         
	            if(l2!=null){
	            curr.next=new ListNode(0);
	            curr=curr.next;
	            }
	        }
	        
	        return nhead;
	    }
}
