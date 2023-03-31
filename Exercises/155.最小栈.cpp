/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    stack<int> m_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(__INT_MAX__);
    }
    
    void push(int val) {
        m_stack.push(val);
        min_stack.push(::min(min_stack.top(),val));//::写法（使用全局变量，避免与局部变量冲突）
    }
    
    void pop() {
        m_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

