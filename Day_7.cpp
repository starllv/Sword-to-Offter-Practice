// 1.树的子结构
// 题目要求：输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。
// 例如:
// 给定的树 A:
//      3
//     / \
//    4   5
//   / \
//  1   2
// 给定的树 B：
//    4 
//   /
//  1
// 返回true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
// 算法思想：采用递归的方法，判断A中是否存在B子树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A && B) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool recur(TreeNode* A, TreeNode* B) {
        if(!B) return true;
        if(!A || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};

// 2.二叉树的镜像
// 题目要求：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
// 例如输入：
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// 镜像输出：
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
// 算法思想：基于递归的方法，从头开始，交换左右子树，再对左右子树进行镜像操作
class Solution {
public:
    void reverse(TreeNode *root){
        if(root){
            TreeNode* t = root->left;
            root->left = root->right;
            root->right = t;
        }
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if(root){
            reverse(root);
            mirrorTree(root->left);
            mirrorTree(root->right);
        }

        return root;
    }
};
// 简单写法：
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root){
            TreeNode* tmp = root->left;
            root->left = mirrorTree(root->right);
            root->right = mirrorTree(tmp);
        }
        return root;
    }
};

// 3.对称的二叉树
// 题目要求：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// 算法思想：先将右子树镜像，再比较左右子树是否一样
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirror(TreeNode* root){
        if(root){
            TreeNode* tmp = root->left;
            root->left = mirror(root->right);
            root->right = mirror(tmp);
        }
        return root;
    }

    bool recur(TreeNode* A, TreeNode* B){
        if(!B && !A) return true;
        if((!A && B) || (A && !B) || A->val != B->val) return false;
        return recur(A->left,B->left) && recur(A->right,B->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        mirror(root->right);
        return recur(root->left,root->right);
    }
};
//其他解法：递归比较树的左节点的值是否和右节点一样
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root ? true : recur(root->left, root->right); //数为空则直接返回true，否则就去递归比较左右子树是否对称
    }
    bool recur(TreeNode* L, TreeNode* R) {
        if(!L && !R) return true;   //若左右子树都越过叶节点，证明左右子树对称
        if(!L || !R || L->val != R->val) return false; //若左右子树的树形不一致或节点值不一样，证明不对称，返回true
        return recur(L->left, R->right) && recur(L->right, R->left);   //当前左右节点一致时就去比较左节点的左子树与右节点的右子树，也要比较左节点的右子树与右节点的左子树
    }
};