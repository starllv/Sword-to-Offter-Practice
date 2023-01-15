/**
 * 题目：剑指 Offer 64. 求1+2+…+n
 * 题目要求: 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 * 
 * 链接：https://leetcode.cn/problems/qiu-12n-lcof/
 * 
 * 思路：使用逻辑运算符的短路效应
 *  参考：https://leetcode.cn/problems/qiu-12n-lcof/solution/mian-shi-ti-64-qiu-1-2-nluo-ji-fu-duan-lu-qing-xi-/
 **/
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

/**
 * 题目：剑指 Offer  68 - I. 二叉搜索树的最近公共祖先
 * 题目要求: 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 *      最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
 *      满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
 * 
 * 思路：根据二叉搜索树的定义，左子树的节点的值 < 父节点的值 < 右子树的节点的值
 *      因此当寻找两个节点的公共祖先的过程中，有如下情况：
 *          (1) 当前节点的值 < 两个节点中的最小值，说明公共祖先在当前节点的右子树中
 *          (2) 当前节点的值 > 两个节点中的最大值，说明公共祖先在当前节点的左子树中
 *          (3) 当前节点的值 >= 两个节点中的最小值，且 <= 两个节点中的最大值，则当前节点就是两个节点的公共祖先
 *  可以使用递归法
 * 
 * 数据结构定义：
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        if(root->val < min(p->val, q->val)) res = lowestCommonAncestor(root->right, p, q);
        if(root->val > max(p->val, q->val)) res = lowestCommonAncestor(root->left, p, q);
        return res;
    }
};

/**
 * 题目：剑指 Offer 68 - II. 二叉树的最近公共祖先
 * 题目要求: 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 *      最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
 *      满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 链接：https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
 * 
 * 思路：根据二叉树中某节点是两个节点的公共祖先节点，满足：
 *      （1）一节点位于该节点的左子树，另一节点位于该节点的右子树
 *       (2)一个节点就是祖先节点，另一节点位于该节点的左子树或右子树中
 * 
 *  查找时需要遍历二叉树，若：
 *      (1)节点的值不等于任意一个目标节点的值，需要到该节点的左子树和右子树中寻找是否存在两个目标节点
 *          若左子树中找不到，则说明该祖先节点和目标节点在右子树中，则去右子树中寻找，反之到左子树中寻找；若左右子树中都能找到一个
 *          节点，则当前节点即为目标节点的公共祖先
 *      (2)若当前节点等于任意一个目标节点，则当前节点即为祖先节点
 * 
 * 数据结构定义：
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        TreeNode* res = root;
        if(root->val != p->val && root->val != q->val){
            bool left_res = search(root->left, p, q), right_res = search(root->right, p, q);
            if(!left_res && right_res){
                res = lowestCommonAncestor(root->right, p, q);
            }else if(left_res && !right_res){
                res = lowestCommonAncestor(root->left, p, q);
            }
        }

        return res;
    }
private:
    bool search(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return false;
        if(root->val == p->val || root->val == q->val) return true;
        return search(root->left, p, q) || search(root->right, p, q);
    }
};
// 其他解法
// 参考：https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};