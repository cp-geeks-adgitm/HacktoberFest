package LinkedList;

public class Kreverse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	public ListNode reverseKGroup(ListNode head, int k) {
		if (head == null || head.next == null)
			return head;

		return reverse(head, size(head), k);
	}

	public ListNode reverse(ListNode head, int count, int k) {
		if (head == null)
			return null;

		if (count - k < 0) {
			return head;
		}

		int c = k - 1;
		ListNode temp = head;
		while (c-- > 0) {
			temp = temp.next;
		}
		ListNode tempn = temp.next;
		temp.next = null;

		ListNode rec = reverse(tempn, count - k, k);

		// here there is a need rto reverse the linklist
		if (k > 1) {
			ListNode a = head;
			ListNode b = head.next;
			ListNode cn = head.next == null ? null : b.next;
			while (b != null) {
				b.next = a;
				a = b;
				b = cn;
				if (cn != null)
					cn = cn.next;
			}
		}
		// then make the necessary attachments
		head.next = rec;

		return temp;
	}

	public int size(ListNode head) {
		if (head == null)
			return 0;

		int si = 1;
		ListNode curr = head;
		while (curr.next != null) {
			si++;
			curr = curr.next;
		}
		return si;
	}
}
