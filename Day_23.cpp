/**
 * 题目：剑指 Offer 39. 数组中出现次数超过一半的数字
 * 题目要求: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 *  你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 链接：https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 * 
 * 思路：使用哈希表统计各个数字出现的次数，然后输出出现次数超过数组长度一半的数字
 * 
 **/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int res;
        for(auto num : nums) map[num]++;
        for(auto num : nums){
            if(map[num] > nums.size()/2){
                res = num;
                break;
            }
        }
        return res;
    }
};
//其他解法：摩尔投票法
// 参考：https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/solution/mian-shi-ti-39-shu-zu-zhong-chu-xian-ci-shu-chao-3/

/**
 * 题目：剑指 Offer 66. 构建乘积数组
 * 题目要求: 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
 *  其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
 *  即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
 * 
 * 链接：https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=ybl7t0i
 * 
 * 思路：表格分区
 *  链接：https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/
 * 
 **/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len == 0) return {};
        vector<int> b(len, 1);
        b[0] = 1;
        int tmp = 1;
        for(int i = 1; i < len; i++) {
            b[i] = b[i - 1] * a[i - 1];
        }
        for(int i = len - 2; i >= 0; i--) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }
        return b;
    }
};
