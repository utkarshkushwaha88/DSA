# include <iostream>
# include <math.h>
# include <vector>
# include <stack> 
# include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(10);
    q.push(23);
    q.push(53);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl; 
return 0;
}