/**
 * 题目：剑指 Offer 56 - I. 数组中数字出现的次数
 * 题目要求: 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * 
 * 链接：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 * 
 * 思路：异或运算
 *  参考：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/jian-zhi-offer-56-i-shu-zu-zhong-shu-zi-tykom/
 * 
 **/
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = 0, m = 1, x = 0, y = 0;
        
        for(auto num : nums) n ^= num;

        while(!(n & m)) m <<= 1;
        
        for(auto num : nums){
            if(num & m) x ^= num;
            else y ^= num;
        }

        return vector<int>{x, y};
    }
};

/**
 * 题目：剑指 Offer 56 - II. 数组中数字出现的次数 II
 * 题目要求: 在一个数组 nums 中除一个数字只出现一次之外，
 *  其他数字都出现了三次。请找出那个只出现一次的数字。
 * 
 * 链接：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
 * 
 * 思路：位运算
 *  参考：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/3chong-jie-fa-ji-jian-cdai-ma-by-fengzil-fmlr/
 * 
 **/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sub = 0, res = 0;
        for(int i = 0; i < 32; i++, sub = 0){
            for(auto num : nums) sub += (num >> i) & 1;   //统计所有数的某一位出现1的次数
            if(sub % 3) res |= (1 << i);       //若该位出现1的次数不为3，则结果过中该位置1
        }
        return res;
    }
};