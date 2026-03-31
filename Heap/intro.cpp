#include <bits/stdc++.h>
using namespace std;
class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0]=-1;
            size=0; 
        }
        

        void insert(int val){
            size=size+1;
            int index=size;
            arr[index]=val;
            while(index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void deleteFromHeap(){
            if(size==0){
                cout<<"Nothing to delete"<<endl;
                return ;
            }
            arr[1]=arr[size];
            size--;
            int i=1;
            while(i<size){
                int leftIndex=2*i;
                int rightIndex=2*i +1;
                if(leftIndex<size &&  arr[i]<arr[leftIndex]){
                    swap(arr[leftIndex],arr[i]);
                    i=leftIndex;
                }
                else if(rightIndex<size && arr[i]<arr[rightIndex]){
                    swap(arr[rightIndex],arr[i]);
                    i=rightIndex;
                }
                else{
                    return;
                }
            }
        }
        
};
 void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;//for 0based indexing
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest])
            largest = left;

        if(right < n && arr[right] > arr[largest])
            largest = right;

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }


int main() {
    heap h;
    h.insert(50);
    h.insert(20);
    h.insert(30);
    h.insert(10);
    h.insert(15);
    h.insert(25);
    h.insert(29);
    h.print();
    h.deleteFromHeap();
    h.print();

    //heapify
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing array now "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;


return 0;
}