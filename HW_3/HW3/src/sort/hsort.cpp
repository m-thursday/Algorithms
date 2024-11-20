#include <sort.hpp>
#include <graph.hpp> 
#include <algorithm>

//extern
std::string sortAlgName = "Heap Sort";

void heapify(vector<ArrayValue> &heap, int N, int current){
	int largest = current;
	int left = 2 * current + 1;
	int right = 2 * current + 2;
	
	if((left < N) && ((heap[left].key > heap[largest].key) || 
((heap[left].key == heap[largest].key) && (heap[left].value > heap[largest].value)))){
		largest = left;
	}
	if((right < N) && ((heap[right].key > heap[largest].key) || 
((heap[right].key == heap[largest].key) && (heap[right].value > heap[largest].value)))){
		largest = right;
	}
	if(largest != current){
		swap(heap[current],heap[largest]);
		heapify(heap,N,largest);
	}
}

void sort(std::vector<ArrayValue> &array, int l, int r) {
    int n = r-l+1;
    vector<ArrayValue> heap(n);
    copy(array.begin()+l,array.begin()+r,heap.begin());
    
    for(int i =((n/2)-1);i>=0;i--){
    	heapify(heap,n,i);
    }
    for(int i =(n-1);i >= 0;i--){
    	swap(heap[0],heap[i]);
    	heapify(heap,i,0);
    }
    copy(heap.begin(),heap.end(),array.begin()+l);
}

