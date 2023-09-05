/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head==null) return null;
        HashMap<Node, Node> adds= new HashMap<>();
        Node ans=new Node(head.val), itr= ans;
        adds.put(head, ans);
        for(Node temp= head.next; temp!=null;  temp= temp.next){
            itr.next= new Node(temp.val);
            itr= itr.next;
            adds.put(temp, itr);
        }
        itr= ans;
        for(Node temp= head; temp!=null; temp= temp.next){
            if(temp.random!=null) itr.random= adds.get(temp.random);
            itr= itr.next;
        }
        return ans;
    }
}