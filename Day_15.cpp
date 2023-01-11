/**
 * 题目：剑指 Offer 34. 二叉树中和为某一值的路径
 * 题目要求:给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。叶子节点 是指没有子节点的节点。
 * 
 * 链接：https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
 * 
 * 思路：先序遍历
 * 参考：https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/mian-shi-ti-34-er-cha-shu-zhong-he-wei-mou-yi-zh-5/
 * 
 * 数据结构定义：
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        recur(root, target);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;

    void recur(TreeNode* root, int target){
        if(root == nullptr) return;
        path.push_back(root->val);
        target -= root->val;
        if(root->left == nullptr && root->right == nullptr && target == 0) res.push_back(path);
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }
};

/**
 * 题目：剑指 Offer 36. 二叉搜索树与双向链表
 * 题目要求: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向
 * 
 * 链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 * 
 * 思路：中序遍历
 * 参考：https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/mian-shi-ti-36-er-cha-sou-suo-shu-yu-shuang-xian-5/
 * 
 * 数据结构定义：
 * // Definition for a Node.
 *  class Node {
 *  public:
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
 * */
 class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return head;
        recur(root);
        head->left = work;
        work->right = head;
        return head;
    }
private:
    Node* head = nullptr;
    Node* work = nullptr;
    void recur(Node* root){
        if(root == nullptr) return;
        recur(root->left);
        if(work != nullptr) work->right = root;
        else head = root;
        root->left = work;
        work = root;
        recur(root->right);
    }
};

/**
 * 题目：剑指 Offer 54. 二叉搜索树的第k大节点
 * 题目要求: 给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
 * 
 * 链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 * 
 * 思路：修改中序遍历的方向，按右-中-左的方向去搜索第k个节点，即为二叉搜索树的第k大节点
 *    基于递归的中序遍历算法是先递归右子树，处理当前节点，在递归左子树
 * 
 * 数据结构定义：
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 * */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        recur(root);
        return res;
    }
private:
    int res, k;
    void recur(TreeNode* root){
        if(root == nullptr || this->k == 0) return;    //超出节点之外或者已找到第k大的值时，返回
        recur(root->right);
        if(--this->k == 0) res = root->val;
        recur(root->left);
    }
};