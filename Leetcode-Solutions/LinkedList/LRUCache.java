package LinkedList;
import java.util.*;

import Apr5LinkedList.LinkList.Node;
public class LRUCache {

	 public class Node{
	        Node next;
	        Node prev;
	        int data=0;
	        int k=0;
	        Node(Node prev,Node next,int data,int k){
	            this.prev=prev;
	            this.next=next;
	            this.data=data;
	            this.k=k;
	        }
	        
	        
	        @Override
			public  String toString() {
				Node temp=head;
				while(temp!=null) {
					
					System.out.print(temp.data+ "-->");
					temp=temp.next;
					
				}
				
				System.out.print("null");
				return " ";
			}
	    }
	    Node head;
	    Node tail;
	    int si=0;
	     HashMap<Integer,Node> map;
	    public LRUCache(int c) {
	        map=new HashMap<>();
	        si=c;
	        head=new Node(null,tail,0,0);
	        tail=new Node(head,null,0,0);
	    }
	    
	    public int get(int key) {
	       
	        if(!map.containsKey(key)) return -1;
	        
	        Node a=map.get(key);
	        Node deleted=delete(a);// delete karke nikal ayaa
	        int res=deleted.data;
	        add(deleted);// last me add karvadia
	        //System.out.println(head);
	        return res;
	    }
	    public Node delete(Node h){
	        // delete the head.nextnode;
	        Node temp=head;
	        while(temp.next!=h){
	            temp=temp.next;
	        }
	        Node curr=temp.next;
	        Node n=curr.next;
	        temp.next=n;
	        n.prev=temp;
	        curr.next=null;
	        curr.prev=null;
	        
	        return curr;
	    }
	    public void add(Node h){// isme vhi node bhejunga jo add karni hai
	        // add before the tail
	        
	        Node pr=tail.prev;
	        pr.next=h;
	        h.prev=pr;
	        tail.prev=h;
	        h.next=tail;
	        
	    }
	    
	    public void put(int key, int value) {
	        if(map.containsKey(key)){         
	            Node curr=map.get(key);
	            Node del=delete(curr);
	            del.data=value;
	            add(del);
	            map.put(key,del);
	            return ;
	        }
	          else if( map.size()==si){
	           Node d= delete(head.next);
	            int val=d.k;
	            map.remove(val);
	        }
	        
	        Node n=new Node(null,null,value,key);
	        map.put(key,n);
	        add(n);
	    }
}
