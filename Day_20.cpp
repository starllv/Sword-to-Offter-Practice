/**
 * 题目：剑指 Offer 07. 重建二叉树
 * 题目要求: 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
 *      假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 
 * 链接：https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/
 * 
 * 思路：树的根节点是先序遍历的第一个节点，根据根节点在中序遍历中的位置，
 *      可以将中序序列分成左右子树，而卓优子树的根节点又可以根据先序序列得到
 *      根据分治算法，同样的方法又可以确定各个子树的结构
 * 参考思想：https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-di-gui-fa-qin/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        return rescur(0, 0, preorder.size()-1);
    }
private:
    vector<int> preorder;
    unordered_map<int, int> map;
    TreeNode* rescur(int root, int left, int right){
        if(left > right) return NULL;
        TreeNode* node = new TreeNode(preorder[root]);
        int i = map[preorder[root]];
        node->left = rescur(root+1, left, i-1);
        node->right = rescur(i-left+root+1, i+1,right);
        return node;
    }
};

/**
 * 题目：剑指 Offer 16. 数值的整数次方
 * 题目要求: 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
 * 
 * 链接：https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
 * 
 * 思路：快速乘+递归
 * 参考思想：https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/shu-zhi-de-zheng-shu-ci-fang-by-leetcode-yoqr/
 * 
 **/
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
private:
    double quickMul(double x, long n){
        if(n == 0) return 1.0;
        double y = quickMul(x, n/2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
};

/**
 * 题目：剑指 Offer 33. 二叉搜索树的后序遍历序列
 * 题目要求: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
 *      如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 * 
 * 链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 * 
 * 思路：递归分治
 *  二叉搜索树的后序序列的最后一个数是二叉树的根节点，其左子树的值均小于根节点，右子树均大于根节点
 *  在后序序列中，表现为从0 - m均小于最后一个节点的值，m+1 -- 最后一个节点前一个节点的值均大于最后一个节点
 * 子序列又可以利用上述方法判断
 * 
 * 参考思想：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
 * 
 **/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }
private:
    bool recur(vector<int>& postorder, int left, int right){
        if(left >= right) return true;

        int i = left;
        while(postorder[i] < postorder[right]) i++;
        int m = i;
        while(postorder[i] > postorder[right]) i++;

        return (i == right) && recur(postorder, left, m-1) && recur(postorder, m, right-1);
    }
};