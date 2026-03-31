class queue{
    int* arr;
    int size;
    int front=-1;
    int rear=-1;
    queue(int x){
        this->size=x;
        arr=new int[size];
    }
    bool isEmpty(){
        return rear==-1 && front==-1;
    }
    bool isFull(){
        return (rear+1)%size==front;
    }
    void add(int data){
        if(isFull()){
            cout<<"overflow"<<endl;
            return;
        }
        //if it's the 1st element
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=data;

        int remove(){
            if(isEmpty()){
                cout<<"empty queue"<<endl;
                return -1;
            }
            int res=arr[front];

            //if only 1 element is present
            if(front==rear){
                front==rear=-1;
            }
            else{
                front=(front+1)%size;
            }
            return res;
        }
        int peek(){
            if(isEmpty()){
                cout<<"empty queue"<<endl;
                return -1;
            }
            return arr[front];
        }


    }
};