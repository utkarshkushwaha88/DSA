class minHeap {
private:
    int arr[100];
    int currSize;

public:
    minHeap() {
        arr[0] = -1;   // dummy element (1-based indexing)
        currSize = 0;
    }

    void push(int x) {
        currSize++;
        int index = currSize;
        arr[index] = x;

        // Heapify Up
        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void pop() {
        if(currSize == 0) return;

        arr[1] = arr[currSize];
        currSize--;

        int i = 1;

        // Heapify Down
        while(i <= currSize) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if(left <= currSize && arr[left] < arr[smallest])
                smallest = left;

            if(right <= currSize && arr[right] < arr[smallest])
                smallest = right;

            if(smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else {
                break;
            }
        }
    }

    int peek() {
        if(currSize == 0) return -1;
        return arr[1];
    }

    int size() {
        return currSize;
    }
};