package LinkedList;

public class CloneWithoutHM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	 public Node copyRandomList(Node head) {
	        if(head==null) return head;
	        // make 
	    
	        Node tempo=head;
	        while(tempo!=null){
	            Node curr=new Node(tempo.val);           
	            curr.next=tempo.next;
	            tempo.next=curr;
	            tempo=tempo.next.next;
	        }
	        
	        //asign random pointers
	        tempo=head;
	       Node tempn=head.next;
	        while(tempo!=null){
	            
	            tempn.random=tempo.random==null?null:tempo.random.next;
	            tempo=tempn.next;
	            if(tempo!=null)
	            tempn=tempo.next;
	        }
	        
	        // break the links
	        
	        Node nhead=head.next;
	        tempo=head;
	         tempn=nhead;
	        while(tempo!=null){
	            tempo.next=tempn.next;
	            if(tempo.next!=null){
	                tempn.next=tempo.next.next;
	            }
	            tempo=tempo.next;
	            tempn=tempn.next;
	        }
	        return nhead;
	    }

}
