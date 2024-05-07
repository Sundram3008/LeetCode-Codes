/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head){
        ListNode prev= null, curr= head, nextNode;
        while(curr!=null){
            nextNode = curr.next;
            curr.next= prev;
            prev=curr;
            curr= nextNode;
        }
        return prev;
    }
    public ListNode doubleIt(ListNode head) {
        ListNode temp = reverse(head);
        int carry=0;
        ListNode res= new ListNode(-1), prev= res;
        while(temp!= null || carry>0){
            if(temp!=null){
                carry+= (temp.val*2);
                temp= temp.next;
            }
            prev.next= new ListNode(carry%10);
            carry/=10;
            prev= prev.next;
        }
        return reverse(res.next);
    }
}