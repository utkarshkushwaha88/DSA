# include <iostream>
# include <math.h>
# include <vector>
#include <stack>
using namespace std;
class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;
    public:
        //initialize default constructor Because C++ does NOT create default constructor automatically if:You already defined a parameterized constructor.
        twoStacks() {
            size = 100; // default size
            top1 = -1;
            top2 = size;
            arr = new int[size];
}
        TwoStack(int s){
            this->size=s;
            top1=-1;
            top2=s;
            arr=new int[s];
        }
        //push in stack1
        void push1(int num){
            if(top2-top1>1){
                top1++;
                arr[top1]=num;
            }
            else{
                cout<<"Stack overflow"<<endl;
            }
        }
        //push in stack 2
        void push2(int num){
            if(top2-top1>1){
                top2--;
                arr[top2]=num;
            }
            else{
                cout<<"Stack overflow"<<endl;
            }
        }
        //pop from stack1 and return  popped element
        int pop1(){
            if(top1>=0){
                int ans=arr[top1];
                top1--;
                return ans;
            }
            else{
                return -1;
            }
        }
        //pop from stack2 and return  popped element
        int pop2(){
            if(top1<size){
                int ans=arr[top2];
                top2++;
                return ans;
            }
            else{
                return -1;
            }
        }
};
int main() {
return 0;
}