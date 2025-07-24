#include<bits/stdc++.h>
using namespace std;
class heap{
public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;  // to keep the 1-based index
        size = 0;
    }
    // Function to insert a value into the heap
    void insert(int val){
        size += 1;
        int index = size;
        arr[index] = val;
        // Move the element to its correct position to maintain the max-heap property
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;  // If the parent is greater than or equal, stop
            }
        }
    }

    void deleteFromHeap(){
        if(size==0){
            return;
        }
        //put last element to first position
        arr[1]=arr[size];
        //remove last element
        size--;
        //take root node to its correct position
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;
            if(left < size && arr[i] < arr[left] && (right >= size || arr[left] > arr[right])) {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right < size && arr[i] < arr[right]) {
                swap(arr[i], arr[right]);
                i = right;
            }
            else {
                return;
            }
        }
    }
    // Function to print the elements in the heap
    void print(){
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    heap h;
    // Insert elements into the heap
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(25);
    // Print the heap
    cout << "Heap elements after insertions: ";
    h.print();  // Expected output (max heap): 30 25 10 5 20
    h.deleteFromHeap();
    cout<<"Heap after deletion: ";
    h.print();  //Expected output (max heap): 25 10 5 20
    return 0;
}