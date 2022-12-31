// 1.二维数组中的查找
// 题目要求：在一个 n*m 的二维数组中，每一行都按照从左到右“非递减”的顺序排序，每一列都按照从上到下“非递减”的顺序排序。
// 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
// 我的解法
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();

        for(int i = 0; i < len; i++){
            int length = matrix[i].size();

            if(length == 0) continue;
            if(matrix[i][0] > target) break;

            int low = 0, high = length - 1;

            while(low <= high){
                int mid = (low + high) / 2;

                if(matrix[i][mid] > target) high = mid - 1;
                else if(matrix[i][mid] < target) low = mid + 1;
                else return true;
            }
        }

        return false;
    }
};

// 其他解法：找一个标志数，如左下角的元素，该元素是本行最小的元素，本列最大的元素，若目标小于该标志数，则可以不再在该列中寻找，
// 若目标大于该标志数，则可以再再该列中寻找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};

// 2.旋转数组的最小数字
// 题目要求：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 给你一个可能存在重复元素值的数组numbers，它原来是一个升序排列的数组，
// 并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]]。
// 我的解法：基于冒泡排序，一次遍历将最小元素提到数组首位
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len  = numbers.size();
        
        for(int i = len - 1;i > 0; i--){
            if(numbers[i] < numbers[i-1]){
                int temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp; 
            }
        }
        
        return numbers[0];
    }
};
// 其他解法：基于二分法
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];
    }
};

// 3.第一个只出现一次的字符
// 题目要求：在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
class Solution {
public:
    char firstUniqChar(string s) {
        int num[26];
        
        if(s.size() != 0){
            for(int i = 0; i < 26; i++) num[i] = 0;

            for(auto c : s){
                num[c-'a']++;
            }

            for(auto c : s){
                if(num[c-'a'] == 1) return c;
            }
        }

        return ' ';
    }
};
// 其他解法：使用哈希表
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> dic;    //定义一个字母为键与bool为值的哈希表
        for(char c : s)
            dic[c] = dic.find(c) == dic.end();  //find返回所找键对应值的迭代器，若没有找到，返回end。此处语句的作用是，若字母重复，则改键对应的值变为false，即重复的键的值是false
        for(char c : s)
            if(dic[c]) return c;   //找到第一个不重复的字符
        return ' ';
    }
};