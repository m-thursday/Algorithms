#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Quick Sort";

int setPivotID(vector<ArrayValue> &array, int l, int r){
	int mid = (l+r)/2;
    int f = array[l].key, b = array[r].key, m = array[mid].key;
    
    if (f > m)
    	swap(array[l], array[mid]);
    if (f > b)
    	swap(array[l], array[r]);
    if (m > b)
    	swap(array[mid], array[r]);
    
    return mid;
}
int partition(vector<ArrayValue> &array, int l, int r){
	int pID = setPivotID(array, l, r);
	swap(array[pID],array[r]);
	ArrayValue pivot = array[r];
	int i = l - 1;
	for (int j = l; j < r; j++){
		if (array[j].key < pivot.key || 
        	(array[j].key == pivot.key && array[j].value < pivot.value)) {
        	i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[r]);
	return i+1;
}


void sort(std::vector<ArrayValue> &array, int l, int r) {
    if (l >= r)
    	return;
      
   	int pivotInd = partition(array, l, r);
    
   	sort(array, l, pivotInd-1);
   	sort(array, pivotInd+1, r);
    

}

