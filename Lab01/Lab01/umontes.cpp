#include <iostream>

using namespace std;

//.....Lab01
//.....Insertion Sort

int main(int argc,char **argv){

    int* Sequence;
    int arraySize = 0;
    int key = 0;
    int j = 0;

    cin >> arraySize;
    Sequence = new int[arraySize];

    for (int i = 0; i < arraySize; i++){
        cin >> Sequence[i];
    }

/////
    for (int i = 1; i < arraySize; i++){
        key = Sequence[i];
        j = i - 1;
        while (j >= 0 && Sequence[j] > key){
            Sequence[j+1] = Sequence[j];
            j = j - 1;
        }
        Sequence[j+1] = key;

        for (int k = 0; k <= i; k++){
            cout << Sequence[k] << ";";
        }
        cout << endl;
    }

    delete[] Sequence;
}