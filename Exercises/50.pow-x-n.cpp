/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long b = n;
        double res = 1.0;
        while(b){
            if(b<0){
                x=1/x;
                b=-b;
            }
            //按位与判断
            if( b&1 == 1){
                res=res*x;
            }
            x=x*x;
            b>>=1; //右移即删除最后一位
        }
        return res;
    }
};
// @lc code=end

