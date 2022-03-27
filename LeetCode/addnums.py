# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        result = head
        carry = 0
        
        while (l1 != None) and (l2 != None):
            result.val = l1.val + l2.val + carry
            carry = int(result.val/10)
            result.val = result.val%10
            prev = result
            result.next = ListNode()
            result = result.next
            l1 = l1.next
            l2 = l2.next
        
        if l1==None:
            remain = l2
        else:
            remain = l1
            
        while(remain!=None):
            result.val = remain.val + carry
            carry = int(result.val/10)
            result.val = result.val%10
            prev = result
            result.next = ListNode()
            result = result.next
            remain = remain.next
        
        if carry != 0:
            result.val = carry
        else:
            prev.next = None
        
        return head
