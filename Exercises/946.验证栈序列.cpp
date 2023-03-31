/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */
// @lc code=start
class Solution {
public:    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> m_stack;
        int i=0;
        for(int num: pushed)
        {
            m_stack.push(num);
            while(!m_stack.empty() && m_stack.top()==popped[i])
            {
                m_stack.pop();
                i++;
            }
        }
        return m_stack.empty();//不为空即无此出入栈顺序
    }
};
// @lc code=end

