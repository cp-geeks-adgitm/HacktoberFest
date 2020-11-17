package LinkedList;

public class OddEven {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	 public ListNode oddEvenList(ListNode head) {
	        if(head==null) return null;
	        
	        int count=3;
	        ListNode curr=head;
	        ListNode ohead=head;
	        ListNode otail=head;
	        ListNode ehead=head.next;
	        ListNode etail=head.next;
	        if(etail==null ||etail.next==null){
	            return head;
	        }
	        curr=head.next.next;
	        while(curr!=null){
	            if(count%2==0){
	                // case of even
	                etail.next=curr;
	                etail=etail.next;
	                
	            }else{
	                //case of odd
	                otail.next=curr;
	                otail=otail.next;
	            }
	            curr=curr.next;
	            count++;
	        }
	        etail.next=null;
	        otail.next=ehead;
	        return ohead;
	    }

}
