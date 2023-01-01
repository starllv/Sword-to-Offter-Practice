// 1.从上到下打印二叉树I
// 题目要求：从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
// 我的解法：基于层序遍历算法，需要辅助队列
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;

        if(!root) return res;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            res.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            q.pop();
        }

        return res;
    }
};

// 2.从上到下打印二叉树II
// 题目要求：从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
// 算法思想：按层序遍历的思想，设置每个节点所在的层，输出时，同一层的节点放到同一列表中
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        struct Data{
            TreeNode* p;
            int level;
        };
        vector<vector<int>> res;
        queue<struct Data> q;

        if(!root) return res;

        struct Data data;
        data.p = root;
        data.level = 0;
        q.push(data);

        int level = 0;
        vector<int> v_p;

        while(!q.empty()){
            data = q.front();
            q.pop();

            if(data.level == level+1){
                level++;
                res.push_back(v_p);
                v_p.clear();
            }
            v_p.push_back(data.p->val);

            if(data.p->left){
                struct Data temp;
                temp.p = data.p->left;
                temp.level = data.level + 1;
                q.push(temp);
            } 
            if(data.p->right){
                struct Data temp;
                temp.p = data.p->right;
                temp.level = data.level + 1;
                q.push(temp);
            }
        }
        res.push_back(v_p);

        return res;
    }
};

// 其他解法
class Solution {
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        if(root) queue.push(root);
        while(!queue.empty()) {
            vector<int> tmp;
            for(int i = queue.size(); i > 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                tmp.push_back(node->val);
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

// 3.从上到下打印二叉树III
// 题目要求：请实现一个函数按照之字形顺序打印二叉树，
// 即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
// 第三行再按照从左到右的顺序打印，其他行以此类推
// 算法思想：依据第二题的思想形成每一层的列表，最后加入到结果列表中时，判断当前层，
// 若是奇数层则将顺序逆序
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> queue;

        if(root) queue.push(root);
        int level = 0;

        while(!queue.empty()){
            vector<int> tmp;
            int len = queue.size();
            int i = len;

            while(i--){
                TreeNode* node;
                node = queue.front();
                queue.pop();
                tmp.push_back(node->val);

                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }

            if(level%2 == 1){
                for(int i = 0; i < len/2; i++){
                    int t = tmp[i];
                    tmp[i] = tmp[len-i-1];
                    tmp[len-i-1] = t;
                }
            }
            level++;
            res.push_back(tmp);
        }

        return res;
    }
};
// 其他解法：根据当前层时奇数还是偶数，直接将数放到所属位置
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root) q.push(root);
        bool rev = false;

        while(!q.empty()){
            int node_num = q.size();
            vector<int> cur_level(node_num);
            for(int i=0;i<node_num;++i){
                auto cur = q.front(); q.pop();
                if(cur->left!=nullptr) q.push(cur->left);
                if(cur->right!=nullptr) q.push(cur->right);

                cur_level[rev?node_num-1-i:i] = cur->val;//根据rev标志位确定是顺序还是逆序放置
            }
            rev = !rev;
            ans.push_back(cur_level);
        }
        return ans;
    }
};