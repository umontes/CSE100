#include <iostream>
#include <cmath>

using namespace std;

//.....Lab04-1
//.....Heap-Sort

int MaxHeapify(int *arr, int i, int arraySize){

    int L, R;
    int largest;
    largest = i;

    L = 2*i+1;
    R = 2*i+2;

    if ((L <= arraySize) && (arr[L] > arr[largest])){
        largest = L;
    }

    else{
        largest = i;
    }

    if ((R <= arraySize) && (arr[R] > arr[largest])){
        largest = R;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, arraySize);
    }

}

//------------

int BuildMaxHeap(int *arr, int arraySize){
    
    for (int i = (arraySize/2); i >= 0; i--){
        MaxHeapify(arr, i, arraySize);
    }
} 

//---------

int Heapsort(int *arr, int arraySize){

    BuildMaxHeap(arr, arraySize);

    for (int i = arraySize; i > 0; i--){
        swap(arr[0], arr[i]);
        arraySize = arraySize - 1;
        MaxHeapify(arr, 0, arraySize);
    }
}

//---------

int main(int argc, char **argv){

    int* Sequence;
    int arraySize = 0;

    cin >> arraySize; //amount of elements that are going to be in the array
    Sequence = new int[arraySize];

    for (int i = 0; i < arraySize; i++){ //puts all the elements in an array
        cin >> Sequence[i];
    }

/////////////////////////////////////////////

    // BuildMaxHeap(Sequence, arraySize-1);    //used to test something for HW02

    // for (int i = 0; i < arraySize; i++){
    //     cout << Sequence[i] << ";";
    // }

/////////////////////////////////////////////

    Heapsort(Sequence, arraySize-1);

    for (int i = 0; i < arraySize; i++){
        cout << Sequence[i] << ";";
    }

    delete[] Sequence;
}

// Heapsort --> BuildMaxHeap & MaxHeapify
// BuildMaxHeap --> MaxHeapify
// MaxHeapify --> MaxHeapify w/ largest