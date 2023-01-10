/**
 * 题目：剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
 * 题目要求:输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
 * 
 * 链接：https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 * 
 * 思路：双指针法
 *     一个指针指向开头，一个指针指向末尾，开头指针找到第一个偶数时，第二个指针开始移动，当找到技术时，两个位置的数交换位置，直至第一个指针比第二个大时，交换完成
 * 
 * 其实是一种基于快速排序的分块的方法
 * */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[i]%2 == 1) i++;      //nums[i]为奇数
            else{                        //nums[i]为偶数
                if(nums[j]%2 == 0) j--;  //nums[j]为奇数
                else{                    //nums[j]为偶数
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums;
    }
};
// 其他解法：有快慢指针
// https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/mian-shi-ti-21-diao-zheng-shu-zu-shun-xu-shi-qi-4/

/**
 * 题目：剑指 Offer 57. 和为s的两个数字
 * 题目要求:输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
 * 
 * 链接：https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 * 
 * 思路：遍历 + 二分查找
 *     因为数组时递增的，可以从头开始找小于target的元素nums[i]，计算得到target与nums[i]的差值diff，接下来使用二分查找法从数组中找到diff即可
 **/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i < len && nums[i] < target; i++){
            int diff = target - nums[i];
            res.push_back(nums[i]);
            
            int start = 0, end = len - 1, mid;
            while(start <= end){
                mid = (start + end) / 2;
                if(nums[mid] == diff){
                    res.push_back(nums[mid]);
                    return res;
                }else if(nums[mid] < diff) start = mid + 1;
                else end = mid - 1;
            }
            res.clear();
        }
        return res;
    }
};

// 其他解法：对撞双指针
// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/solution/mian-shi-ti-57-he-wei-s-de-liang-ge-shu-zi-shuang-/

/**
 * 题目：剑指 Offer 58 - I. 翻转单词顺序
 * 题目要求:输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
 *      例如输入字符串"I am a student. "，则输出"student. a am I"。
 * 
 * 链接：https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 * 
 * 思路：双指针遍历
 *     双指针用来寻找字符串中的子串，找到一个即加到结果中
 **/
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i = len - 1, j = len - 1;
        string res;
        bool first = true;                          //用来标志找到的是否是第一个子串，方便往结果串中添加空格
        while(i >= -1){                            //快速指针，用来寻找子串的开头，一直找到主串的开头，等于-1时说明已经到头
            if(i == -1 || s[i] == ' ' ){           //找到空格或者已经找到头
                if(i != j){                        //若快指针和慢指针不是指到同一个元素，证明已经找到一个子串
                    if(first) first = false;
                    else res += ' ';
                    res += s.substr(i+1, j - i);
                }
                j = i - 1;                        //添加完子串，将慢指针指向快指针的下一个，效果是找到一个子串时，慢指针指向子串的最后一个元素
            }
            i--;
        }
        return res;
    }
};