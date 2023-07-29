class Solution {
public:
    pair<ListNode*,ListNode*> *mid(ListNode* head) {
        pair<ListNode*,ListNode*>p;
        if(!head) {
            p.first = NULL;
            p.second = NULL;
            return p;
        }
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode*fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            slow = temp->next;
            fast=fast->next->next;
        }
        p.first = slow;
        while(fast->next!=NULL){
            fast = fast->next;
        }
        p.second = fast;
        return p;
    }
    TreeNode* sortedListToBST_helper(ListNode* head,ListNode*temp,ListNode*end){
        if(temp==end) return NULL;
        ListNode*mid_node = mid(head).first;
        TreeNode<int>*newHead = new TreeNode<int>(mid_node->next->data);
        TreeNode<int>*left = sortedListToBST(head,temp,mid);
        TreeNode<int>*right = sortedListToBST(head,mid->next->next , end);
        newHead->left = left;
        newHead->right = right;
        return newHead;

    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode*temp = head;
        ListNode*end = mid(head).second;
        sortedListToBST_helper(head,temp,end);

    }
};
