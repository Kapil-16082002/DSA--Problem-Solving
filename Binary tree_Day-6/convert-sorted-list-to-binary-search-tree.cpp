class Solution {
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast and fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

    TreeNode *build(ListNode *head)
{
        if (!head)
            return NULL;
        if (middleNode(head) == head)
            return new TreeNode(head->val);
        ListNode *middle = middleNode(head);

        TreeNode *root = new TreeNode(middle->val);
        ListNode *ptr = head;
        while (ptr->next != middle)
            ptr = ptr->next;

        ListNode *first = head;
        ListNode *second = middle->next;

        ptr->next = NULL;
        middle->next = NULL;

        root->left = build(first);
        root->right = build(second);

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head) return NULL;
        return build(head);
    }
};
