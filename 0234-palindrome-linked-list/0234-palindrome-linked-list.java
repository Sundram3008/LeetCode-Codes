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
    public boolean isPalindrome(ListNode head) {
        ListNode fast= head.next, slow = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode prev= null, curr = slow.next, nextNode;
        while(curr!=null){
            nextNode = curr.next;
            curr.next = prev;
            prev= curr;
            curr= nextNode;
        }
        fast= head;
        while(prev!=null){
            if(prev.val!= fast.val) return false;
            prev= prev.next;
            fast= fast.next;
        }
        return true;
    }
    
}

// 1221
//     1212
// // 12324