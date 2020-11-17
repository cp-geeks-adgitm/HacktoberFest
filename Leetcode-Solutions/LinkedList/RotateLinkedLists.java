package LinkedList;

public class RotateLinkedLists {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	  public ListNode rotateRight(ListNode head, int k) {
	        if( head==null || head.next==null){
	            return head;
	        }
	        
	        int size=0;
	        
	        ListNode curr=head;
	        while(curr!=null){
	            size++;
	            curr=curr.next;
	        }
	        k=k%size;
	        if(k==0){
	            return head;
	        }
	        k=size-k;
	        
	        ListNode prev=null;
	         curr=head;
	        int i=1;
	        while(curr.next!=null){
	          if(i<=k){
	              prev=curr;
	          }  
	            i++;
	            curr=curr.next;
	        }
	        ListNode nhead=prev.next;
	        prev.next=null;
	        
	        curr.next=head;
	        return nhead;
	    }

}
