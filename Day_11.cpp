/**
 * 题目：剑指 Offer 18. 删除链表的节点
 * 题目要求:给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
 * 链接：https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 * 思路：双指针法
 * 遍历链表，一个指针指向当前节点，另一个执行前一个节点。找到要删除的节点后，修改前一个指针的next执行当前节点的next，然后退出即可
 *
 * 若当前节点为头结点，即头结点即为要删除元素，直接修该head指针即可
 * 数据结构定义：
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * */

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pre = head, *cur = head;
        while(cur){
            if(cur->val == val){
                if(cur == head) head = cur->next;
                else pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = pre->next;
        }

        return head; 
    }
};

/**
 * 题目：剑指 Offer 22. 链表中倒数第k个节点
 * 题目要求:输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
 * 例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
 * 链接：https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 * 思路：双指针法
 * 遍历链表，双指针遍历链表，一个指针end用来寻找末尾，另一个指针start当end走了k-1个节点后，开始和end同步向后，当end走到结尾时，start指向的即为倒数第k个节点
 *
 * 开始时两指针同时指向head，end每走一步，k减一，当k小于等于1时，start开始往后走
 * 数据结构定义：
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *start = head, *end = head;
        while(end->next){
            if(k <= 1) start = start->next;
            end = end->next;
            k--;
        }
        return start;
    }
};