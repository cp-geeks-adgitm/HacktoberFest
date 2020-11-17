package LinkedList;

public class removeNFromLast {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	// using 1 pass solution
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return null;
        if(head.next==null) return null;
        
        
        ListNode first=head.next;// first node tell the distance .. when it is null,then second is at the deleted position
        ListNode second=head;// second node depicts the node which to be deleted 
        ListNode prev=null; // prev is the prev node of the seconf node
        for(int i=1;i<n;i++){
            first=first.next;
        }
        while(first!=null){
            first=first.next;
            prev=second;
            second=second.next;
        }
        
        if(prev==null){
            head=second.next;
            return head;
        }
        prev.next=second.next;
        second.next=null;
        return head;
    }

}
