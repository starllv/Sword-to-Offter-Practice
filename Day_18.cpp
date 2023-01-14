/**
 * 题目：剑指 Offer 55 - I. 二叉树的深度
 * 题目要求: 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 * 
 * 链接：https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/
 * 
 * 思路：基于深度优先算法，递归遍历根节点左右子树，若节点为空，直接返回0，若节点不为空，高度加一，最后返回左右子树最大的高度
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
// 深度优先算法的后序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;   //若节点为空，已超出叶节点，返回，高度不增
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); //若节点不为空，树的高度加一，再加上左右子树的最大高度
    }
};
// 广度优先算法的层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            res++;
            for (int i = queue.size() - 1; i >= 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                if(node->left != NULL) queue.push(node->left);
                if(node->right != NULL) queue.push(node->right);
            }
        }
        return res;
    }
};

/**
 * 题目：剑指 Offer 55 - II. 平衡二叉树
 * 题目要求: 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 * 
 * 链接：https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/
 * 
 * 思路：基于深度优先算法和广度优先算法
 *    判断是不是平衡二叉树需要计算每个节点的左右子树的深度差，因此需要使用广度优先算法遍历树种每个节点，
 *   使用深度优先算法计算节点左右子树的深度，然后计算深度的差值，若差值的绝对值大于1，则返回false
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            int diff = dfs_depth(node->left) - dfs_depth(node->right);
            if(diff > 1 || diff < -1) return false;
            if(node->left != NULL) queue.push(node->left);
            if(node->right != NULL) queue.push(node->right);
        }
        return true;
    }

private:
    int dfs_depth(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(dfs_depth(root->left), dfs_depth(root->right));
    }
};
//全递归写法
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(dfs_depth(root->left) - dfs_depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int dfs_depth(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(dfs_depth(root->left), dfs_depth(root->right));
    }
};
// 其他解法：参考链接：https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/solution/mian-shi-ti-55-ii-ping-heng-er-cha-shu-cong-di-zhi/
