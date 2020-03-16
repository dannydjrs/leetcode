struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // New list
        ListNode* head;
        ListNode** index = &head;

        int sum, carry = 0;
        while (l1 != NULL || l2 != NULL) {
            sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            (*index) = new ListNode(sum % 10);
            index = &((*index)->next);

            carry = sum / 10;
        }

        // Any remaining overflow
        if (carry > 0) {
            (*index) = new ListNode(carry);
        }

        return head;
    }
};
