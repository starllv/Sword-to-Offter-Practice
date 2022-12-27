// 1. 用两个栈实现队列
// 题目要求：用两个栈实现一个队列。队列的声明如下，请实现它的两个
// 函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数
// 和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

class CQueue {
public:
    stack<int> s1 , s2;                           //定义两个栈，入队时数据都入栈s1，出栈时需要s2的辅助
    CQueue() {}
    
    void appendTail(int value) {
        if(s1.empty()){                  //s1为空时，可能是第一次输入数据，也可能是出队时将数据都移动到了s2，若是第二种情况需要将数据移动到s1中
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()&&s2.empty()) return -1;      //两个栈都为空时，则整个队列为空

        if(s2.empty()){                       //s2为空时，数据都在s1中，且栈底元素为队首元素，需要移动到s2中，则s2栈顶为队首元素
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int res = s2.top();
        s2.pop();

        return res;
    }
};

// 2.包含min函数的栈
// 题目要求：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
// 调用 min、push 及 pop 的时间复杂度都是 O(1)。

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    //入栈时，先将当前最小值入栈，再将要入栈的元素入栈
    void push(int x) {
        if(_stack.empty()){
            _min = x;
        }else{
            if(_min > x) _min = x;
        } 
        
        _stack.push(_min);
        _stack.push(x);
    }
    //出栈时需要出两次，即栈顶元素及包含其在内的当前最小值。之后需要更新最小值，而当前的最小值在当前栈顶元素的下面
    void pop() {
        int temp;

        if(_stack.empty()) return;
        _stack.pop();
        if(_stack.empty()) return;
        _stack.pop();

        if(_stack.empty()) return;
        temp = _stack.top();
        _stack.pop();
        _min = _stack.top();
        _stack.push(temp);

    }
    
    int top() {
        return _stack.top();
    }
    
    int min() {
        return _min;
    }
private:
    stack<int> _stack;
    int _min;
};