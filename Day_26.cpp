/**
 * 题目：剑指 Offer 20. 表示数值的字符串
 * 题目要求: 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 数值（按顺序）可以分成以下几个部分：
 *      若干空格
 *      一个 小数 或者 整数
 *      （可选）一个 'e' 或 'E' ，后面跟着一个 整数
 *      若干空格
 * 小数（按顺序）可以分成以下几个部分：
 *      （可选）一个符号字符（'+' 或 '-'）
 *      下述格式之一：
 *          至少一位数字，后面跟着一个点 '.'
 *          至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
 *          一个点 '.' ，后面跟着至少一位数字
 * 整数（按顺序）可以分成以下几个部分：
 *      （可选）一个符号字符（'+' 或 '-'）
 *      至少一位数字
 * 部分数值列举如下：
 *      ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
 * 部分非数值列举如下：
 *      ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 * 
 * 题目链接：https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=ybl7t0i
 * 
 * 思路：有限状态机  常规字符判断
 * 参考：https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/mian-shi-ti-20-biao-shi-shu-zhi-de-zi-fu-chuan-y-2/
 **/
class Solution {
private:
    // 整数的格式可以用[+|-]B表示, 其中B为无符号整数
    bool scanInteger(const string s, int& index){

        if(s[index] == '+' || s[index] == '-')
            ++index;

        return scanUnsignedInteger(s, index);
    }
    
    bool scanUnsignedInteger(const string s, int& index){

        int befor = index;
        while(index != s.size() && s[index] >= '0' && s[index] <= '9')
            index ++;

        return index > befor;
    }
public:
    // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
    bool isNumber(string s) {

        if(s.size() == 0)
            return false;
        int index = 0;

        //字符串开始有空格，可以返回true
        while(s[index] == ' ')
            ++index;

        bool numeric = scanInteger(s, index);

        // 如果出现'.'，接下来是数字的小数部分
        if(s[index] == '.'){

            ++index;

            // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
            numeric = scanUnsignedInteger(s, index) || numeric;
        }

        // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
        if(s[index] == 'e' || s[index] == 'E'){

            ++index;

            // 下面一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
            numeric = numeric && scanInteger(s ,index);
        }

        //字符串结尾有空格，可以返回true
        while(s[index] == ' ')
            ++index;
        cout << s.size() << " " << index;   //调试用

        return numeric && index == s.size();
    }
};

/**
 * 题目：剑指 Offer 67. 把字符串转换成整数
 * 题目要求: 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
 *  首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
 *  当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
 * 作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
 * 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
 * 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，
 * 则你的函数不需要进行转换。
 * 在任何情况下，若函数不能进行有效的转换时，请返回 0。
 * 说明：
 *  假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
 * 如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
 * 
 * 题目链接：https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
 * 
 * 思路：扫描字符串，若是‘ ’，往后循环，若是出数字外的其他字符，则无法进行转换，返回0
 * 参考：https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/
 **/
class Solution {
public:
    int strToInt(string str) {
        int len = str.length();
        if(len == 0) return 0;
        int index = 0;
        bool minus = false;
        while(str[index] == ' ')
            if(++index == len) return 0;
        if(str[index] == '+' || str[index] == '-'){   
            if(str[index] == '-') minus = true;
            index++;
        }else if(str[index] > '9' || str[index] < '0') return 0;
        long long res = 0;
        for(;index < len && str[index] <= '9' && str[index] >= '0'; index++){
            res = res * 10 + (str[index] - '0');
            if(res > INT_MAX) break;    //若结果已大于最大的int值，直接返回
        }
        if(minus){
            res *= (-1);
            if(res < INT_MIN) res = INT_MIN;
        }else{
            if(res > INT_MAX) res = INT_MAX;
        }
        return (int)res;
    }
};