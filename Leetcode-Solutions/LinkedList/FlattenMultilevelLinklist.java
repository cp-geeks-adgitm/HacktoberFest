package LinkedList;

public class FlattenMultilevelLinklist {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	  public Node flatten(Node head) {
	        if(head==null) return null;
	        Node temp=head;
	       flat(head);
	        return temp;
	    }
	    // recursive function
//	     public Node flat(Node head){
	        
//	         Node temp=head;
//	         Node t=null;
//	         while(temp!=null){
//	             if(temp.child!=null){
	                
//	                 Node c=temp.child;
//	                 Node p=temp.next;
//	                 temp.child=null;
//	                 temp.next=c;
//	                 c.prev=temp;
	                
//	               Node tail=flat(c);
//	                 if(p!=null){
//	                 tail.next=p;
//	                 p.prev=tail;
//	                 }    
//	             }
//	             if(temp.next==null){
//	                 t=temp;
//	             }
//	             temp=temp.next;
	            
//	         }
//	         return t;
//	     }
	    /////////////////////////iterative using stack
	    public Node flat(Node head){
	        LinkedList<Node> st=new LinkedList<>();
	        Node temp=head;
	        while(temp!=null){
	            if(temp.child!=null){
	                Node c=temp.child;
	                Node p=temp.next;
	                temp.child=null;
	                temp.next=c;
	                c.prev=temp;
	                if(p!=null){
	                st.addFirst(p);
	            }
	          }
	            
	           if(temp.next==null && st.size()>0 ){
	                Node curr=st.removeFirst();
	                temp.next=curr;
	               curr.prev=temp;
	            }
	            temp=temp.next;
	        }
	        return head;
	    }

}
