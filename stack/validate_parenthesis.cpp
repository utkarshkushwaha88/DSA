# include <iostream>
# include <math.h>
# include <vector>
# include <stack>
using namespace std;
bool matches(char top,char ch){
    if((ch==')' && top=='(')||(ch=='}'&& top=='{')||(ch==']'&& top=='[')){
        return true;
    }
    else{
        return false;
    }
}
bool isValidateParenthesis(string expression){
    stack<char> s;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        //if opening brackets then push
        if(ch=='{'||ch=='['||ch=='('){
            s.push(ch);
        }
        else{
            //for closing bracket
            if(!s.empty()){
                char top=s.top();
                if(matches(top,ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else {
        return false;
    }
}
int main() {
    
return 0;
}