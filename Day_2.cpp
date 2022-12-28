// 1.从尾到头打印链表
// 题目要求：输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> vec;
        ListNode *p = head;

        stack<int> st;         //使用栈实现数组的逆序
        while(p != NULL){
            st.push(p->val);
            p = p->next;
        }
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }

        return vec;
    }
};

// 2.反转链表
// 题目要求：定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *temp;

        head = nullptr;
        while(cur != nullptr){
            temp = cur->next;
            cur->next = head;
            head = cur;
            cur = temp;
        }

        return head;
    }
};

// 3.复杂链表的复制
// 题目要求：请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，
// 每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//我的方法：遍历法，第一遍遍历逐个创建新的链表，并给next指针赋值，第二遍去逐个找到元素的random指针指向的元素，并在新链表中复制这种关系
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *res = NULL,*p = head,*q,*u,*v,*tail;

        while(p != NULL){
            Node *temp = new Node(p->val);
            if(p == head){
                res = temp;
                tail = temp;
            }
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
            p = p->next;
        }

        p = head;
        q = res;
        int i = 0;
        while(p != NULL){
            if(p->random == NULL){
                q->random = NULL;
            }else{
                u = head;
                while(u != NULL){
                    if(p->random == u) break;
                    u = u->next;
                    i++;
                }
                v = res;
                for(; i > 0; i--) v = v->next;
                q->random = v;
            }
            p = p->next;
            q = q->next;
        }

        return res;
    }
};
//官方的一种方法：
// 首先将该链表中每一个节点拆分为两个相连的节点，例如对于链表A→B→C，
// 我们可以将其拆分为A→A′→B→B′→C→C′。对于任意一个原节点S，其拷贝节点S'即为其后继节点。
// 这样，我们可以直接找到每一个拷贝节点S'的随机指针应当指向的节点，即为其原节点S的随机指针指向的节点T的后继节点T'。
// 需要注意原节点的随机指针可能为空，我们需要特别判断这种情况。当我们完成了拷贝节点的随机指针的赋值，
// 我们只需要将这个链表按照原节点与拷贝节点的种类进行拆分即可，只需要遍历一次。同样需要注意最后一个拷贝节点的后继节点为空，我们需要特别判断这种情况

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};