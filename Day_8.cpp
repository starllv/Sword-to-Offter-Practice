// 1.斐波那契数列
// 题目要求：写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
// 算法思想：由于斐波那契数列存在递推关系，因此可以使用动态规划算法求解，时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, sum;
        for(int i = 0; i < n; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};
// 2.青蛙跳台阶问题
// 题目要求：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
// 算法思想：根据分析，青蛙跳台阶的跳法nw和台阶阶数n的关系是：
// n=0 nw=1；n=1 nw=1； n=2 nw=2；n=3 nw=3；n=4 nw=5...n=n nw=nw(n-1)+nw(n-2)
// n>=2时，nw(n) = nw(n-1) + nw(n-2).因为序列符合递推关系，所以可以使用递归算法，而递归算法会有重复计算，时间复杂度是O(n**2)
// 所以这里使用动态规划思想，时间复杂度为O(n)，只使用三个变量保存值，空间复杂度是O(1)
class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 2, sum;
        for(int i = 1;i < n;i++){
            sum  = (a + b) % 1000000007;
            a = b;
            b = sum;
        }

        return a;
    }
};

// 3.股票的最大利润
// 题目要求：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

// 示例 1:

// 输入: [7,1,5,3,6,4]
// 输出: 5
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

// 示例 2:

// 输入: [7,6,4,3,1]
// 输出: 0
// 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

// 暴力解法：遍历数组，一次计算出某一元素与之后元素的差值，更新最大利润值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, len = prices.size();

        for(int i = 0;i < len;i++){
            for(int j = i;j < len;j++){
                int tmp = prices[j] - prices[i];
                if(tmp > max_profit) max_profit = tmp;
            }
        }

        return max_profit;
    }
};

// 动态规划：每次访问到prices[i]时，更新以当前元素为结尾的最低价格，之后计算当前元素与最低价的差值，比较该差值与当前最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;  //若列表元素个数只有1个或者没有元素，不存在价格的差值，直接返回

        int max_profit = 0, min_cost = prices[0]; //max_profit记录当前最大利润，置为0；min_cost为当前最小价格，设置为第一个元素，方便之后循环更新

        for(int i = 1;i < len;i++){  //循环从第二个元素开始，循环更新当前最小价格当最大利润
            if(min_cost > prices[i]) min_cost = prices[i];  //更新最小价格
            int tmp = prices[i] - min_cost;    //计算当前元素所计算出的利润，必须用当前元素减去前面的最低价格
            if(max_profit < tmp) max_profit = tmp;  //若当前利润小于计算出的利润，则更新
        }

        return max_profit;
    }
};