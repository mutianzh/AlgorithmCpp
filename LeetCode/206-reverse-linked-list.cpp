class Solution {
public:

    void _helper (ListNode* prev, ListNode* cur, ListNode*& newhead){
        ListNode* next = cur -> next;
        cur -> next = prev;
        if (next != nullptr){
            _helper(cur, next, newhead);
        } else {
            newhead = cur;
            return;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = nullptr;
        if (head == nullptr) {return nullptr;}
        _helper(nullptr, head, newhead);
        return newhead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {return nullptr;}
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr){
            ListNode* next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
