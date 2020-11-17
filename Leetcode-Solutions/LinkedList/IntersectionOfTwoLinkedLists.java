package LinkedList;

public class Intersection {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	 public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
	        if(headA==null || headB==null){
	            return null;
	        }
	        ListNode a=headA;
	        ListNode b=headB;
	        int sa=1;
	        int sb=1;
	        while(a.next!=null){
	            sa++;
	            a=a.next;
	        }
	        while(b.next!=null){
	            sb++;
	            b=b.next;
	        }
	        
	        //humesha a size ke diff se chlega  
	        int skip=Math.abs(sa-sb);
	      if(sa>sb){
	          a=headA;
	          b=headB;
	          for(int i=1;i<=skip;i++){
	              a=a.next;
	          }
	          
	          
	      }else{
	          a=headB;
	          b=headA;
	           for(int i=1;i<=skip;i++){
	              a=a.next;
	          }
	      }
	        while(a!=b){
	            a=a.next;
	            b=b.next;
	        }
	        return a;
	    }

}
