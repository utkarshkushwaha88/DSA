//Time complexity O(N)
bool knows(vector<vector<int>>&M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }
    else
        false;
}
int celebrity(vector<vector<int>>&M,int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
}
while(s.size()>1){
    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();
    if(knows(M,a,b,n)){
        s.push(b);
    }
    else{
        s.push(a);
    }
}
int ans=s.top();
//single element in stack is potential celebrity
//so verify 
bool rowCheck=false;
int zeroCount=0;
for(int i=0;i<n;i++){
    if(M[ans][i]==0){
        zeroCount++;
    }
}
//all zeroes
if(zeroCount==n){
    rowCheck=true;
}
//column check
bool colCheck=false;
int oneCount=0;
for(int i=0;i<n;i++){
    if(M[i][ans]==1){
        oneCount++;
    }
}
if(oneCount==n-1){
    colCheck=true;
}

if(rowCheck==true && colCheck==true){
    return ans;
}
else 
    {return -1;}