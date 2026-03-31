#include <stack>
using namespace std;

class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch);
            }
            else if(ch == ')') {

                bool isRedundant = true;

                while(!st.empty() && st.top() != '(') {
                    char top = st.top();
                    
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }

                    st.pop();
                }

                // pop the '('
                if(!st.empty())
                    st.pop();

                if(isRedundant == true) {
                    return true;
                }
            }
        }

        return false;
    }
};
