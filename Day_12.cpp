/**
 * 题目：剑指 Offer 25. 合并两个排序的链表
 * 题目要求:输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 * 
 * 链接：https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * 思路：双指针法
 * 双指针遍历两个链表，若当前p1所指的节点的值小于等于p2所指的值，就将p1摘下插入到新链表的末尾，p1指向其下一个节点；
 * 反之，就将p2摘下链接到新链表尾部，并将p2指向其下一个节点，直至l1或者l2其中一个遍历完，在将剩下没有遍历完的列表直接链接到新链表的尾部
 * 
 * 考虑到一些特殊情况需要处理，如l1或者l2为空，或者只有一个节点等
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* list = nullptr;
        ListNode* end = nullptr;

        if(p1 != nullptr && p2 == nullptr) return p1;
        else if(p1 ==nullptr && p2 != nullptr) return p2;
        else if(p1 == nullptr && p2 == nullptr) return list;
        if(p1->val <= p2->val){
            list = p1;
            end = p1;
            p1 = p1->next;
        }else{
            list = p2;
            end = p2;
            p2 = p2->next;
        }
        end->next = nullptr;

        while(p1 != nullptr && p2 != nullptr){
            if(p1->val <= p2->val){
                end->next = p1;
                end = p1;
                p1 = p1->next;
            }else{
                end->next = p2;
                end = p2;
                p2 = p2->next;
            }
            end->next = nullptr;
        }
        if(p1 != nullptr) end->next = p1;
        if(p2 != nullptr) end->next = p2;

        return list;
    }
};
// 其他解法：https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/solution/mian-shi-ti-25-he-bing-liang-ge-pai-xu-de-lian-b-2/

/**
 * 题目：剑指 Offer 52. 两个链表的第一个公共节点
 * 题目要求:输入两个链表，找出它们的第一个公共节点。
 * 
 * 链接：https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
 * 思路：双指针法
 * 观察到两个列表尾部对齐之后，从短的链表的位置开始走，比较指针所指的位置是否相同，即可找到相交的第一个公共点
 * 可以先计算两个链表的长度，计算长度差diff，长的链表的指针先走diff步，此时两个链表后面的长度相等，然后上下两个链表同时移动指针进行比较
 * 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        int lenA = 0, lenB = 0, diff = 0;
        ListNode *pA, *pB;

        pA = headA, pB = headB;
        while(pA != nullptr){
            lenA++;
            pA = pA->next;
        }
        while(pB != nullptr){
            lenB++;
            pB = pB->next;
        }

        pA = headA, pB = headB;
        if(lenA > lenB){
            diff = lenA - lenB;
            while(diff--) pA = pA->next;
        }else{
            diff = lenB - lenA;
            while(diff--) pB = pB->next;
        }
        while(pA != nullptr && pB != nullptr){
            if(pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        
        return nullptr; 
    }
};
// 其他解法：https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/jian-zhi-offer-52-liang-ge-lian-biao-de-gcruu/