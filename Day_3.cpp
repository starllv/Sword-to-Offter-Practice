// 1.替换空格
// 题目要求：请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' '){
                res += "%20";
            }else{
                res += s[i];
            }
        }

        return res;
    }
};

// 2.左旋转字符串
// 题目要求：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"

// 我的做法
// 使用了C++ string类的函数，先找到前n个字符组成的子串，将其拼接到原字符串之后，再去除字符串中的前n个字符
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s += s.substr(0,n);
        return s.erase(0,n);
    }
};

// 其他的解法1
class Solution {
public: 
    string reverseLeftWords(string s, int n) {
        string res;
        for(int i = n; i < n + s.size(); i++)
            res.append(s.charAt(i % s.length()));
        return res;
    }
}
// 其他解法2，使用了两次翻转
class Solution {
public:
    int reverse_string(string& s, int start, int end) {
        for (int i = start; i <= (start + end) / 2; i++) {
            char temp = s[i];
            s[i] = s[start+end-i];
            s[start+end-i] = temp;
        }
        return 0;
    }

    string reverseLeftWords(string s, int n) {
        int length = s.length();

        reverse_string(s, 0, length-1);
        reverse_string(s, 0, length-n-1);
        reverse_string(s, length-n, length-1);
        
        return s;
    }
};