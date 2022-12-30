// 1.数组中的重复数字
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字
// #include <vector>
// #include <iostream>

// using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        int n[len];

        for(int i = 0; i < len; i++) n[i] = 0;     //数组必须初始化为0

        for(int num : nums)
            if(++n[num] > 1) return num;         //若该数加1后大于1，则其重复出现

        return -1;
    }
};
// 测试程序
// int main(){
//     Solution s;
//     vector<int> nums;
//     int num[7] = {2, 3, 1, 0, 2, 5, 3};

//     for (int i = 0; i < 7;i++) nums.push_back(num[i]);

//     int res = s.findRepeatNumber(nums);

//     cout << res << endl;
// }

// 2.在排序数组中查找数字
// 题目要求：统计一个数字在排序数组中出现的次数。

// 我的解法：
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int res = 0;

        if(nums.size() == 0) return 0;      //若数组中没有数字，返回0

        while(i < nums.size() && nums[i] < target) i++;     //找到第一个符合要求的值，获这遍历到了数组的结尾都没有找到
        while(i < nums.size() && nums[i] == target) { res++; i++; }  //往后找等于该值的元素个数

        return res;
    }
};
// 其他人的解法：
// 基于二分查找法找到，第一个目标值的前一个索引和最后一个目标值的后一个索引，最后目标值的个数即：右索引值-左索引值-1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 搜索右边界 right
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] <= target) i = m + 1;
            else j = m - 1;
        }
        int right = i;
        // 若数组中无 target ，则提前返回
        if(j >= 0 && nums[j] != target) return 0;
        // 搜索左边界 right
        i = 0; j = nums.length - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] < target) i = m + 1;
            else j = m - 1;
        }
        int left = j;
        return right - left - 1;
    }
}

// 3. 0 ~ n-1中缺失的数字
// 题目要求：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
//我的解法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int i;

        for(i = 0; i < len; i++){
            if(nums[i] != i) return i;
        }
        if(len == i)
            return i;

        return -1;
    }
};
//其他人的解法：基于二分查找法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] == m) i = m + 1;
            else j = m - 1;
        }
        return i;
    }
}
