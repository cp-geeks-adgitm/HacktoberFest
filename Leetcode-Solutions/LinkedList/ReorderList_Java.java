package LinkedList;

public class Folding {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	Node reorderlist(Node head) {
		// Your code here
		if (head == null || head.next == null || head.next.next == null)
			return head;

		// find the middle node here
		Node slow = head;
		Node fast = slow.next;
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;

		}

		Node middlenext = slow.next;
		slow.next = null;
		Node rev = reverse(middlenext);

		// now merge both the lists
		// by three pointer and a dumny variable
		// Node n=new Node(0);

		Node temp1 = head;
		Node temp2 = rev;

		while (temp1 != null && temp2 != null) {
			Node tempp1 = temp1.next;
			Node tempp2 = temp2.next;

			temp1.next = temp2;
			temp2.next = tempp1;

			temp1 = tempp1;
			temp2 = tempp2;
		}
		return head;
	}

	Node reverse(Node head) {
		if (head.next == null)
			return head;
		Node a = head;
		Node b = head.next;
		Node c = b.next;
		a.next = null;
		while (b != null) {
			b.next = a;
			a = b;
			b = c;
			if (c != null) {
				c = c.next;
			}
		}
		return a;
	}

}
