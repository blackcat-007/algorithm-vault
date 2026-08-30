//linked list cycle detection using fast and slow pointer
ListNode *slow = head;
ListNode *fast = head;

while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast)
        return true;
}

return false;
//find middle of linked list using fast and slow pointer
ListNode *slow = head;
ListNode *fast = head;

while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}

return slow;