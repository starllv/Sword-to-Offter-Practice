/**
 * 题目：剑指 Offer 15. 二进制中1的个数
 * 题目要求: 编写一个函数，输入是一个无符号整数（以二进制串的形式），
 *  返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
 * 
 * 链接：https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
 * 
 * 思路：位运算+移位
 *  当二进制数不为零时，判断最低位是否为1，然后右移一位，直至数为零
 * 
 **/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            if(n & 1) res++;
            n = n >> 1;
        }
        return res;
    }
};

/**
 * 题目：剑指 Offer 65. 不用加减乘除做加法
 * 题目要求: 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
 * 
 * 链接：https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
 * 
 * 思路：位运算
 *  
 * 参考思想：https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
 * 
 **/
class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            int c = (a & b & 0x7fffffff) << 1;  //leetecode编译器无法对负数进行左移，需要将最高位符号位设为零
            a ^= b;
            b = c;
        }
        return a;
    }
};