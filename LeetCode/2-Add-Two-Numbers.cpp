/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* left = new ListNode(0, nullptr);
        ListNode* curNode = left;
        while (l1 != nullptr || l2!= nullptr){
            int n1 = 0;
            int n2 = 0;
            if (l1 != nullptr){
                n1 = l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr){
                n2 = l2 -> val;
                l2 = l2 -> next;
            }

            int sum = n1 + n2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit, nullptr);
            curNode -> next = newNode;
            curNode = newNode;
        }
        if (carry == 1){
            ListNode* newNode = new ListNode(1, nullptr);
            curNode -> next = newNode;
        }

        return left -> next;

    }
};
