class kQueues {
    int k;
    int n;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;
    

  public:
    kQueues(int n, int k) {
        this->n=n;
        this->k=k;
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        next=new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        arr=new int[n];
        freeSpot=0;
    }

void enqueue(int x, int i) {
    if(freeSpot == -1) return;

    int index = freeSpot;
    freeSpot = next[index];

    if(front[i] == -1) {
        front[i] = index;
    } else {
        next[rear[i]] = index;
    }

    next[index] = -1;
    rear[i] = index;
    arr[index] = x;
}

int dequeue(int i) {
    if(front[i] == -1) return -1;

    int index = front[i];
    front[i] = next[index];

    if(front[i] == -1) {
        rear[i] = -1;
    }

    next[index] = freeSpot;
    freeSpot = index;

    return arr[index];
}
bool isEmpty(int i) {
    return front[i] == -1;
}

    bool isFull() {
        if(freeSpot==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
