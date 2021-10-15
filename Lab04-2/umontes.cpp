#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//.....Lab04-2
//.....Randomized Quicksort

int Partition(int *arr, int left, int right){

    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++){
        if (arr[j] <= pivot){
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i + 1;
}

//-----------

int Random(int left, int right){

    srand(time(NULL));
    int random = left + rand() % (right - left);
    return random;

}

//------------

int R_Partitiion(int *arr, int left, int right){

    int random = Random(left, right);
    swap(arr[right], arr[random]);
    return Partition(arr, left, right);
}

//-----------

int R_Quicksort(int *arr, int left, int right){

    if (left < right){
        int middle = R_Partitiion(arr, left, right);
        R_Quicksort(arr, left, middle-1);
        R_Quicksort(arr, middle+1, right);
    }
}

//-----------

int main(int argc, char **argv){

    int* Sequence;
    int arraySize = 0;
    int left, right;

    cin >> arraySize; //amount of elements that are going to be in the array
    Sequence = new int[arraySize];

    for (int i = 0; i < arraySize; i++){ //puts all the elements in an array
        cin >> Sequence[i];
    }

    R_Quicksort(Sequence, 0, arraySize-1);

    for (int i = 0; i < arraySize; i++){
        cout << Sequence[i] << ";";
    }

    delete[] Sequence;
}