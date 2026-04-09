class Solution {
  // Time: O(n) where n is the number of tokens in the input vector
  // Space: O(n) in the worst case when all tokens are operands and we push them onto the stack
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        int res;
        for(string s: tokens){
            if(s!="+" && s!="-" && s!="*" && s!="/") operand.push(stoi(s));
            
            else{
                int right=operand.top();
                operand.pop();
                int left=operand.top();
                operand.pop();
                if(s=="+") res= left+right;
                else if(s=="-") res= left-right;
                else if(s=="*") res= left*right;
                else if(s=="/") res= left/right;
                operand.push(res);
            }
        }
        return operand.top();
    }
};