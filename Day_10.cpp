/**
 * 题目：剑指 Offer 46. 把数字翻译成字符串
 * 题目要求:给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 *
 * 链接：https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 * 思路：动态规划 + 滚动数组
 * 状态定义：设动态规划列表dp，dp[i]代表以x(i)结尾的数字的翻译数量
 * 状态转移方程：若x(i)和x(i-1)组成的两位数字可以翻译，则dp[i]=dp[i-1]+dp[i-2];否则dp[i]=dp[i-1],x(i)x(i-1)组成的两位数区间是[10，25]时，该两位数可被翻译
 * 边界条件：dp[0]=dp[1]=1,即无数字或第一位数字的翻译方法数量都是1
 * 返回值：dp[n],n为数字的位数
 *
 * 使用数字求余和求整法从右到左遍历计算，根据该动态规划的对称性，从右到左的计算是正确的
 * 时间复杂度：O(N)
 * 空间复杂度:O(1)
 * */
class Solution {
public:
    int translateNum(int num) {
        if(num < 0) return 0;
        int d_pp = 1, d_p = 1, pre = num % 10;
        while(num){
            num /= 10;
            int cur = num % 10;
            int tmp = cur * 10 + pre;
            int d_t = d_p;
            if(tmp >= 10 && tmp <= 25) d_t += d_pp;
            
            d_pp = d_p;
            d_p = d_t;
            pre = cur;
        }
        return d_p;
    }
};

/**
 * 题目：剑指 Offer 48. 最长不含重复字符的子字符串
 * 题目要求:请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 *
 * 链接：https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 * 思路：动态规划 + 哈希表
 * 状态定义：设动态规划列表dp，dp[j]代表以字符s[j]为结尾的最长不重复子字符串的长度
 * 状态转移方程：固定右边界j，设字符s[j]左边距离最近的相同字符为s[i],即是s[i]=s[j]
 *           1.当i<0,即s[j]左边无相同字符，则dp[j]=dp[j-1]+1
 *           2.当dp[j-1]<j-i，说明字符s[i]在子字符串dp[j-1]区间之外，则dp[j]=dp[j-1]+1
 *           3.当dp[j-1]>=j-i,说明字符s[i]在子字符串dp[j-1]区间之内，则dp[j]的左边界由s[i]决定，即dp[j]=j-i
 * 边界条件：dp[0]=0
 * 返回值：max(dp),n为数字的位数
 *
 * 使用变量保存当前的dp[j]，并用一个变量保存当前最大值并在每轮更新，可以节省空间。
 * 使用哈希表保存字符与其最后一次出现的索引位置的键值对，遍历字符串时，可通过字符s[j]直接读取到s[j]在之前的zi字符串中出现的最后位置
 * 时间复杂度：O(N)
 * 空间复杂度:O(1)
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char,int> map;
        int max_dis = 0, cur_dis = 0;
        for(int j = 0;j < len;j++){
            if(map.find(s[j]) != map.end()){
                int i = map[s[j]];
                if(cur_dis >= j - i) cur_dis = j - i;
                else cur_dis++;
            }else{
                cur_dis++;
            }
            map[s[j]] = j;
            max_dis = max(max_dis, cur_dis);
        }
        return max_dis;
    }
};