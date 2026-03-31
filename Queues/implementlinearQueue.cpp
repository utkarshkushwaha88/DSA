class myQueue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    myQueue(int n) {
        size = n;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        return (qfront == rear);
    }

    bool isFull() {
        return (rear == size && qfront == 0);
    }

    void enqueue(int x) {
        if(isFull()) {
            return;
        }

        // If rear reached end but front moved forward,
        // shift elements to reuse space (important!)
        if(rear == size && qfront > 0) {
            int j = 0;
            for(int i = qfront; i < rear; i++) {
                arr[j++] = arr[i];
            }
            rear = rear - qfront;
            qfront = 0;
        }

        arr[rear++] = x;
    }

    int dequeue() {
        if(isEmpty()) return -1;

        int ans = arr[qfront++];
        
        if(qfront == rear) {
            qfront = 0;
            rear = 0;
        }

        return ans;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[qfront];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear - 1];
    }
};


// Implement of linear queue by pointing front always at 0 and after deletion shift whole array to previous index; here remove will take time of O(n)

class Queue{
    int* arr;
    int size;
    int rear;
    Public:
        Queue(int x){
            this->size=x;
            arr=new int[size];
            rear=-1;
        }
        bool isEmpty(){
            return rear==-1;
        }
        bool isFull(){
            return rear==size-1;
        }
        void add(int data){
            if(isFull()){
                cout<<"overflow"<<endl;
                return;
            }
            arr[++rear]=data;
        }
        int remove(){
            if(isEmpty()){
                cout<<"empty queue"<<endl;
                return -1;
            }
            int front=arr[0];
            for(int i=0;i<rear;i++){
                arr[i]=arr[i+1];
            }
            rear--;
            return front;
        }
        int peek(){
            if(isEmpty()){
                cout<<"empty queue"<<endl;
                return -1;
            }
            return arr[0];

        }
        
};

