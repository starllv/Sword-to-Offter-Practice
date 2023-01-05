/**
 * 题目：剑指 Offer 42. 连续子数组的最大和
 * 题目要求:输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
 * 链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 * 思路：动态规划 + 滚动数组
 * 状态转移方程：f(n) = max(f(n - 1) + num[i], num[i])
 * 边界条件：f(0) = num[0]
 *
 * 如果当前元素加入到元素和 > 当前元素，则将当前元素加入到前面的元素和，否则只取当前元素
 * 使用一个变量记录最大和
 * */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int max_sum = nums[0],pre = nums[0];  // max sum用来记录当前子数组的最大和，pre用来
        for(int i = 1;i < len;i++){
            pre = max(pre+nums[i], nums[i]);
            max_sum = max(max_sum, pre);
        }
        return max_sum;
    }
};

/**
 * 题目：剑指 Offer  47. 礼物的最大价值
 * 题目要求:在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
 * 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 * 
 * 链接：https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
 * 思路：动态规划 
 * 状态定义：设动态规划数组dp，dp[i,j]代表从棋盘左上角开始，到达单元格(i,j)时能拿到礼物的最大累计价值
 * 状态转移方程：
 *   1.当i=0且j=0时，为起始元素
 *   2.当i=0且j!=0时，为矩阵第一行元素，只可从左边到达
 *   3.当i!=0且j=0时，为矩阵第一列元素，只可从上边到达
 *   4.当i!=0且j!=0时，可从左边或上边到达
 *          dp(i,j) = grid(i,j)                              ,i=0,j=0
 *          dp(i,j) = grid(i,j) + dp(i,j-1)                  ,i=0,j!=0
 *          dp(i,j) = grid(i,j) + dp(i-1,j)                  ,i!=0,j=0
 *          dp(i,j) = grid(i,j) + max[dp(i-1,j),dp(i,j-1)]   ,i!=0,j!=0
 * 边界条件：dp[0][0] = grid[0][0]
 * 返回值：dp[m-1][n-1]，m、n分别是矩阵的行高和列宽
 *
 * 将原矩阵grid用作dp矩阵，可是空间复杂度从O(MN)降至O(1)
 * 
 * 时间复杂度：O(MN)
 * 空间复杂度：O(1)
 * */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row_len = grid.size();
        if(row_len == 0) return 0;
        int col_len = grid[0].size();
        for(int i = 1; i < row_len; i++) grid[i][0] += grid[i-1][0];
        for(int j = 1; j < col_len; j++) grid[0][j] += grid[0][j-1];
        for(int i = 1;i < row_len;i++){
            for(int j = 1;j < col_len;j++){
                grid[i][j] += max(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[row_len-1][col_len-1];
    }
};