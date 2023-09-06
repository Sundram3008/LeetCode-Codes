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
    public ListNode[] splitListToParts(ListNode head, int k) {
        int listsize = 0;
        for(ListNode temp = head; temp != null; temp = temp.next) listsize++;
        
        ListNode[] ans = new ListNode[k];
        int extra = listsize%k, fixedno = listsize/k, currno=0, groupno=0;
        ListNode prev=head;
        
        for(ListNode temp = head; temp != null; temp = (currno!=0)?temp.next: temp){
            currno++;
            int nodesn = (extra>0)?fixedno + 1: fixedno;
            if(currno== nodesn ){
                currno=0;
                ans[groupno] = prev;
                ListNode nextnode = temp.next;
                temp.next=null;
                temp= nextnode;
                prev = temp;
                groupno++;
                extra = (extra>0)?extra-1:0;
            }
        }
        return ans;
    }
}