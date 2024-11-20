#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

void merge(vector<ArrayValue> &array, int l, int m, int r){
	vector<ArrayValue> tmp;
	int x = l;
	int y = m+1;
	
	while((x<=m)&&(y<=r)){
		if((array[x].key < array[y].key) || 	
(array[x].key == array[y].key && array[x].value < array[y].value)){
       		tmp.push_back(array[x++]);      		
        }else{
        	tmp.push_back(array[y++]);
        }
	}
	
	while(x<=m){
		tmp.push_back(array[x++]);
	}
	
	while(y<=r){
		tmp.push_back(array[y++]);
	}
	for(int i=l;i<=r;++i){
		array[i] = tmp[i-l];
	}
}

void sort(std::vector<ArrayValue> &array, int l, int r) {
    if (l >= r)
    		return;
    	
   	int m = (l+r)/2;
    
    sort(array, l, m);
    sort(array, m+1, r);
    	
    merge(array, l, m, r);
    
}
