/**
 * 题目：剑指 Offer 59 - I. 滑动窗口的最大值
 * 题目要求: 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 * 
 * 题目链接：https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
 * 
 * 思路：使用单调队列
 *  用一个单调队列保持窗口大小的数组元素，且元素按照从大到小的顺序排列，队列第一个元素即为当前窗口的最大值
 * 参考：https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-i-hua-dong-chuang-kou-de-zui-da-1-6/
 **/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        if(len == 0) return res;
        deque<int> queue;
        int low = 1 - k, high = 0;

        while(high < len){
            if(low > 0 && queue.front() == nums[low - 1]) queue.pop_front();
            while(!queue.empty() && queue.back() < nums[high]) queue.pop_back();
            queue.push_back(nums[high]);
            if(low >= 0)
                res.push_back(queue.front());
            low++, high++;
        }
        return res;
    }
};

/**
 * 题目：剑指 Offer 59 - II. 队列的最大值
 * 题目要求: 请定义一个队列并实现函数 max_value 得到队列里的最大值，
 *  要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 *  若队列为空，pop_front 和 max_value 需要返回 -1
 * 
 * 题目链接：https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/
 * 
 * 思路：使用单调队列
 *  需要使用两个队列，一个保存数据，一个用来维护当前最大值
 * 参考：https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/solution/ru-he-jie-jue-o1-fu-za-du-de-api-she-ji-ti-by-z1m/
 **/
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        return max_deque.empty() ? -1 : max_deque.front();
    }
    
    void push_back(int value) {
        deque.push_back(value);
        while(!max_deque.empty() && max_deque.back() < value) max_deque.pop_back();
        max_deque.push_back(value);
    }
    
    int pop_front() {
        if(deque.empty()) return -1;

        int tmp = deque.front();
        deque.pop_front();
        if(tmp == max_deque.front()) max_deque.pop_front();
        return tmp;
    }
private:
    std::deque<int> deque;
    std::deque<int> max_deque;
};