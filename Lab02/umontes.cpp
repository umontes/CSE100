#include <iostream>

using namespace std;

//.....Lab02
//.....Merge Sort

int merge (int* A, int p, int m, int r){
    int i, j, k;
    int n1 = m - p+1;
    int n2 = r - m;
    int* L;
    int* R;

    L = new int [n1];
    R = new int [n2];

    for (i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = A[m + j + 1];
    }

    i = 0;
    j = 0;

    for (k = p; (i < n1) && (j < n2); k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else if (L[i] > R[j]){
            A[k] = R[j];
            j++;
        }
    }

/* Possiblly useful
    while ((i < n1) && (j < n2)) {
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    */

// V1 to put the rest of what is in left and right temp arrays
    while (i < n1){
        A[k++] = L[i++];
        //k++;
        //i++;
    }
    while (j < n2){
        A[k++] = R[j++];
        //k++;
        //i++;
    }

/* V2 to put the rest of what is in left and right temp arrays
    for (i = i; i < n1; i++){
        A[k] = L[i];
        k++;
    }

    for (j = j; j < n2; j++){
        A[k] = R[j];
        k++;
    }
    */

}

int mergeSort (int* arr, int p, int r){

    if (p < r){
        int m = (p + r)/2;

        mergeSort(arr, p, m);
        mergeSort(arr, m+1, r);
        merge(arr, p, m, r);
    }

}

int main(int argc, char **argv){

    int* Sequence;
    int arraySize = 0;

    cin >> arraySize; //amount of elements that are going to be in the array
    Sequence = new int[arraySize];

    for (int i = 0; i < arraySize; i++){ //puts all the elements in an array
        cin >> Sequence[i];
    }

    mergeSort(Sequence, 0, arraySize-1);

    for (int i = 0; i < arraySize; i++){
        cout << Sequence[i] << ";";
    }

    delete[] Sequence;
}