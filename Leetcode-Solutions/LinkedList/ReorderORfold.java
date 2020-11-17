package LinkedList;

public class ReorderORfold {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	  ListNode curr;
	    public void reorderList(ListNode head) {
	        curr=head;
	        order(head,1);
	        
	    }
	    int ts=0;
	    public void order(ListNode head,int size){
	        if(head==null){
	            ts=size;
	            return;
	        }
	        order(head.next,size+1);
	       
	        if(size>ts/2){
	              ListNode n=curr.next;
	            curr.next=head;
	            head.next=n;
	            curr=n;
	        }else if(size==ts/2){
	            curr.next=null;
	        }
	       
	        
	    }

}
