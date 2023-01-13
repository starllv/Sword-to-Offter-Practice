/**
 * 题目：剑指 Offer 40. 最小的k个数
 * 题目要求: 输入整数数组 arr ，找出其中最小的 k 个数。
 *   例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 * 
 * 链接：https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/
 * 
 * 思路：(1)基于排序算法，将数组从小到大排序，输出前k个数字；
 *      (2)基于快速排序算法，在排序过程中找到前k个最小的数 参考思想：https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/solution/jian-zhi-offer-40-zui-xiao-de-k-ge-shu-j-9yze/
 *      (3)基于大根堆，用大根堆维护数组前k个最小值，遍历完数组后，输出堆中元素。参考思想：https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/solution/zui-xiao-de-kge-shu-by-leetcode-solution/
 **/
// 基于排序算法
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        for(int i = 0; i < k;i++) res.push_back(arr[i]);
        return res;
    }
};
// 基于快排算法
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size()) return arr;
        return quickSort(arr, k, 0, arr.size() - 1);
    }
private:
    vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        if (i > k) return quickSort(arr, k, l, i - 1);
        if (i < k) return quickSort(arr, k, i + 1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};
// 堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};

/**
 * 题目：剑指 Offer 41. 数据流中的中位数
 * 题目要求: 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 *      如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 *      例如，[2,3,4] 的中位数是 3   [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 *  设计一个支持以下两种操作的数据结构：
 *      void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 *      double findMedian() - 返回目前所有元素的中位数。
 * 
 * 链接：https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
 * 
 * 思路：使用堆
 *      设置两个堆，一个大根堆，一个小根堆，大根堆放数据流中最小的一半元素，小根堆中放最大的一般元素
 *      中位数可根据两个堆的堆顶元素计算得到
 *  参考思想：https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/solution/mian-shi-ti-41-shu-ju-liu-zhong-de-zhong-wei-shu-y/
 **/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(minheap.size() == maxheap.size()){
            maxheap.push(num);
            int tmp = maxheap.top();
            maxheap.pop();
            minheap.push(tmp);
        }else{
            minheap.push(num);
            int tmp = minheap.top();
            minheap.pop();
            maxheap.push(tmp);
        }
    }
    
    double findMedian() {   
        if(maxheap.size() == minheap.size()) return (maxheap.top() + minheap.top())/2.0;
        return minheap.top();
    }
private:
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int,vector<int>,less<int>> maxheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */