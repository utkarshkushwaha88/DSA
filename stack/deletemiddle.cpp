//delete middle
void solve(stack<int>&inputStack,int count,int size){
    //base case 
    if(count==size/2){
        inputstack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    //Recursive call
    solve(inputStack,count+1,size);
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack,N){
    int count=0;
    solve(inputStack,count,N);
}