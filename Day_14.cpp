/**
 * 题目：剑指 Offer 12. 矩阵中的路径
 * 题目要求: 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 链接：https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * 
 * 思路：深度优先遍历  
 * 参考思想：https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
 **/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = 0;
        if(row > 0) col = board[0].size();
        int len = word.length();
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int row;
    int col;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k]) return false;
        if(k == word.length() - 1) return true;
        board[i][j] = ' ';
        bool ret = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                    dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return ret;
    }
};

/**
 * 题目：剑指 Offer 13. 机器人的运动范围
 * 题目要求: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 * 
 * 链接：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 * 
 * 思路：深度优先遍历或广度优先遍历  
 * 参考思想：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/mian-shi-ti-13-ji-qi-ren-de-yun-dong-fan-wei-dfs-b/
 **/
 class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(0, 0, 0, 0, visited, m, n, k);
    }
private:
    int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
        if(i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
                   dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
    }
};