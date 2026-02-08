package Java;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList {

    static Node LinkedListTraversing(int[] arr) {
        Node head = new Node(arr[0]);
        Node mover = head;

        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover = temp;
        }
        return head;
    }

    static int LengthofLL(Node head) {
        Node temp = head;
        int cnt = 0;
        while (temp != null) {
            temp = temp.next;
            cnt++;
        }

        return cnt;
    }

    static boolean SearchingofEl(Node head, int val) {
        Node temp = head;
        while (temp.data == val)
            return true;
        return false;
    }

    public static void main(String[] args) {
        int[] arr = { 99, 4, 45, 5 };
        Node head = LinkedListTraversing(arr);
        System.out.println(head.data);

        int length = LengthofLL(head);
        System.out.println(length);

        boolean search = SearchingofEl(head, 9786);
        System.out.println(search);
    }
}
