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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy= new ListNode(0,head), temp=dummy;
        for(int i=0; i<left-1; i++){
            temp=temp.next;
        }
        ListNode prev=null,curr=temp.next, nextptr;
        for(int i=0; i<right-left+1; i++){
            nextptr=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nextptr;
        }
        temp.next.next=curr;
        temp.next=prev;
        return dummy.next;
    }
}