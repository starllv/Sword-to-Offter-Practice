/**
 * 题目：剑指 Offer 14- I. 剪绳子
 * 题目要求: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为 k[0],k[1]...k[m-1] 。
 * 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，
 * 我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 
 * 链接：https://leetcode.cn/problems/jian-sheng-zi-lcof/
 * 
 * 思路：数学推导 + 动态规划
 * 参考：https://leetcode.cn/problems/jian-sheng-zi-lcof/solution/jian-sheng-zi-by-leetcode-solution-xku9/
 **/
// 数学推导法
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        int a  = n / 3, b = n % 3;
        if(b == 0) return pow(3, a);
        else if(b == 1) return pow(3, a-1) * 4;
        return pow(3, a) * 2;
    }
};
// 动态规划
class Solution {
public:
    int cuttingRope(int n) {
        vector <int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};

/**
 * 题目：剑指 Offer 57 - II. 和为s的连续正数序列
 * 题目要求: 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列
 * 
 * 链接：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 * 
 * 思路：数学求和公式 + 滑动窗口
 * 参考：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/jian-zhi-offer-57-ii-he-wei-s-de-lian-xu-t85z/
 **/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 2, s = 3;
        vector<vector<int>> res;
        while(i < j) {
            if(s == target) {
                vector<int> ans;
                for(int k = i; k <= j; k++)
                    ans.push_back(k);
                res.push_back(ans);
            }
            if(s >= target) {
                s -= i;
                i++;
            } else {
                j++;
                s += j;
            }
        }
        return res;
    }
};

/**
 * 题目：剑指 Offer 62. 圆圈中最后剩下的数字
 * 题目要求: 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字
 * （删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
 * 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，
 * 则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 * 
 * 链接：https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
 * 
 * 思路：动态规划
 * 参考：https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/jian-zhi-offer-62-yuan-quan-zhong-zui-ho-dcow/
 **/
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; i++) {
            x = (x + m) % i;
        }
        return x;
    }
};