package LinkedList;

public class Clone {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	// using o(n) extra space
	 Node copyList(Node head) {
	        // your code here
	       HashMap<Node,Node> map=new HashMap<>();
	       Node t=head.next;
	       Node clist=new Node(head.data);
	       Node t2=clist;
	       map.put(head,head.arb);
	       while(t!=null){
	           Node temp=new Node(t.data);
	           t2.next=temp;
	           t2=t2.next;
	           map.put(t,t.arb);
	           t=t.next;
	       }
	       
	       Node curr=clist;
	       Node sh=head;
	       while(curr!=null){
	           
	           curr.arb=map.get(sh);
	           
	           sh=sh.next;
	           curr=curr.next;
	       }
	       
	       return clist;
	  // without using any extra space     
	       
	    }

}
