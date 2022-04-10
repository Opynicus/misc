/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* prev, *head;
    void InOrder(Node* root) {
        if (root == nullptr)
        {
            return ;
        }
        InOrder(root->left);
        if (prev)
        {
            prev->right = root;
        }
        else
        {
            head = root;
        }
        root->left = prev;
        prev = root;
        InOrder(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
        {
            return NULL;
        }
        InOrder(root);
        head->left = prev;
        prev->right = head;
        return head;
        
    }
};