# include <iostream>
# include <math.h>
# include <vector>
using namespace std;
void solve(stack<int>&s,int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    //recursive call
    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>&myStack,x){
    solve(myStack,x);
    return myStack;
}
int main() {
return 0;
}