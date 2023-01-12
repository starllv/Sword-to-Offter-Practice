/**
 * 题目：剑指 Offer 45. 把数组排成最小的数
 * 题目要求: 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 
 * 链接：https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 * 
 * 思路：自定义排序
 *  若任意两个数字x和y，组成一个数，数字的大小定义如下：（1）若xy > yx,则x > y;(2) 若xy < yx, 则 x < y.
 *  根据所定义的比较大小的规则，使用排序算法对数字列表进行从小到大排序
 * 参考思想：https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
 **/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> list;
        for(int i = 0; i < nums.size(); i++) list.push_back(to_string(nums[i]));
        quicksort(list, 0, list.size() - 1);
        string res;
        for(int i = 0; i < list.size(); i++) res += list[i];
        return res;
    }
private:
    void quicksort(vector<string>& list, int low, int high){
        if(low >= high) return;
        int i = low, j = high;
        while(i < j){
            while(i < j && (list[j] + list[low]) >= (list[low] + list[j])) j--;
            while(i < j && (list[i] + list[low]) <= (list[low] + list[i])) i++;
            swap(list[i], list[j]);
        }
        swap(list[i], list[low]);
        quicksort(list, low, i-1);
        quicksort(list,i+1,high);
    }
};

/**
 * 题目：剑指 Offer 61. 扑克牌中的顺子
 * 题目要求: 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
 *   2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14
 * 
 * 链接：https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
 * 
 * 思路：排序后判断是否为顺子
 *  扑克牌中的顺子是牌按顺序增序排列，不可出现重复的牌，除了大小王，大小王按照0处理，当其他牌的顺序不连续时，可以用大小王补充。如0,0,1,2,5是顺子，因为0,0可以补充到3,4的位置，
 *  形成1,2,0,0,5
 * 参考思想：https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/solution/mian-shi-ti-61-bu-ke-pai-zhong-de-shun-zi-ji-he-se/
 **/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int joker = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 4; i++){
            if(nums[i] == 0) joker++;
            else if(nums[i] == nums[i+1]) return false;
        }
        if(nums[4] - nums[joker] >= 5) return false;
        return true;
    }
};