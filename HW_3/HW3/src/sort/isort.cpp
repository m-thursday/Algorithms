#include <sort.hpp>
#include <graph.hpp> 
#include <algorithm>

//extern
std::string sortAlgName = "Intertwined Sort";

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

void sort1(std::vector<ArrayValue> &array, int l, int r) {
    int n =r-l+1;
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

void sort(std::vector<ArrayValue> &array, int l, int r) {
	if (l >= r)
		return;
		
    int left = l;
    int right = r;
    int size = r - l + 1;
    
    vector<ArrayValue> tmp(size);
    sort1(array,l,r);
    
    for(int i = l;i <= r;i++){
    	if(i % 2 == 0){
    		tmp[i] = array[left++];
    	}else{
    		tmp[i] = array[right--];
    	}
    }
    
    copy(tmp.begin(), tmp.begin() + size, array.begin() + l);	
}

