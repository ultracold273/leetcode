/**
 * LeetCode Q150 - Evaluate Reverse Polish Notation
 *  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 *  Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 *  Some examples:
 *
 *    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public: 
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        for(int i = 0;i < (int)tokens.size();i++) {
            if (tokens[i] == "+") {
                int operand = st.top(); st.pop();
                int operato = st.top(); st.pop();
                st.push(operato + operand);
            } else if (tokens[i] == "-") {
                int operand = st.top(); st.pop();
                int operato = st.top(); st.pop();
                st.push(operato - operand);
            } else if (tokens[i] == "*") {
                int operand = st.top(); st.pop();
                int operato = st.top(); st.pop();
                st.push(operato * operand);
            } else if (tokens[i] == "/") {
                int operand = st.top(); st.pop();
                int operato = st.top(); st.pop();
                st.push(operato / operand);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
