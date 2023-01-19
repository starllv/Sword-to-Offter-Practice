/**
 * 题目：剑指 Offer 29. 顺时针打印矩阵
 * 题目要求: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * 
 * 链接：https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=ybl7t0i
 * 
 * 思路：设定边界，按顺序“从左到右，从上到下，从右到左，从下到上”循环打印
 * 参考：https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/
 **/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        if(matrix.size() == 0) return vector<int>({});
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1, x = 0;
        vector<int> res = vector<int>((r+1)*(b+1));
        while(true) {
            for(int i = l; i <= r; i++) res[x++] = matrix[t][i]; // left to right.
            if(++t > b) break;
            for(int i = t; i <= b; i++) res[x++] = matrix[i][r]; // top to bottom.
            if(l > --r) break;
            for(int i = r; i >= l; i--) res[x++] = matrix[b][i]; // right to left.
            if(t > --b) break;
            for(int i = b; i >= t; i--) res[x++] = matrix[i][l]; // bottom to top.
            if(++l > r) break;
        }
        return res;
    }
};
/**
 * 题目：剑指 Offer 31. 栈的压入、弹出序列
 * 题目要求: 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
 * 例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
 * 但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
 * 
 * 链接：https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=ybl7t0i
 * 
 * 思路：建立一个栈进行入栈和出栈模拟
 * 参考：https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/mian-shi-ti-31-zhan-de-ya-ru-dan-chu-xu-lie-mo-n-2/
 **/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int i = 0;
        for(int num : pushed){
            stack.push(num);
            while(!stack.empty() && stack.top() == popped[i]){
                stack.pop();
                i++;
            }
        }
        return stack.empty();
    }
};