#include <iostream>
using namespace std;

void merge (int * arr, int * aux, int min, int mid, int max){
    for(int i = 0 ; i <= max ; i++)
    {
        aux[i] = arr[i]; //copy the array
    }
    
    int i = min;
    int j = mid+1;
    for(int k = min ; k <= max ; k++)
    { 
        if (i>=j) arr[k] = aux[j++];
        else if (j>max) arr[k] = aux[i++];
        else if(aux[i]<aux[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }
    
}
void mergesort(int * arr, int * aux, int min, int max){
    
    if (min>=max) return;
    int mid = min + (max - min)/2;
    mergesort(arr,aux,min,mid);
    mergesort(arr,aux,mid+1,max);
    merge(arr,aux,min,mid,max);
}

int main()
{
    
    // Test
    int * arr = new int[10];
    int * aux = new int[10];

    for(int i = 0; i< 10 ;i++){
        arr[i] = 10 - i;
        aux[i] = 10 - i;
    }

    mergesort(arr,aux,0,9);
    
    for(int i = 0; i< 10 ;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
