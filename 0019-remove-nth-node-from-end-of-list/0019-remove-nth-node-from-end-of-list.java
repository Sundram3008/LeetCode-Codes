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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        int sz=0;
        while(temp!= null){
            temp= temp.next;
            sz++;
        }
        if(sz==n) return head.next;
        n= sz-n-1;
        temp=head;
        for(int i=1; i<=n; i++){
            temp= temp.next;
        }
        temp.next= temp.next.next;
        return head;
    }
}