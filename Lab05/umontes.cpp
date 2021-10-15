#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//.....Lab05
//.....Radixsort

//------------------------------------------
//COUNTING SORT
int CountingSort(vector<int> matrix[], int size, int digit, int col){

    vector<int> outvect[size];
    int temp[10] = {0};     //array initialized with zeroes
    int c;

    for (int i = 0; i < size; i++){
        vector<int> x = matrix[i];
        c = x[digit];
        temp[c] = temp[c] + 1;
    }

    for (int i = 1; i < col; i++){
        temp[i] = temp[i] + temp[i - 1];
    }

//.....
/*
//check what's in temp at this point
    cout << "temp: ";
    for (int i = 0; i < col; i++){
        cout << temp[i];
    }
    cout << endl;
*/
//.....

    for (int i = size - 1; i >= 0; i--){
        outvect[temp[matrix[i][digit]] - 1] = matrix[i];
        temp[matrix[i][digit]] = temp[matrix[i][digit]] - 1;
    }
//.....
/*
//another check on temp
    cout << "temp: ";
    for (int i = 0; i < col; i++){
        cout << temp[i];
    }
    cout << endl;
*/
//.....

//.....
/*
//checking outvect
    cout << "outvect: " << endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < outvect[i].size(); j++){
            cout << outvect[i][j] << " ";
        }
        cout << endl;
    }
*/
//.....

    for (int i = 0; i < size; i++){
        matrix[i] = outvect[i];
    }

}

//------------------------------------------
//RADIX SORT
int RadixSort(vector<int> matrix[], int col, int size){

    for (int i = col - 1; i >= 0; i--){
        CountingSort(matrix, size, i, col);
    }

}

//------------------------------------------
//MAIN FUNCTION
int main(int argc, char **argv){

    int size;

    cin >> size; //amount of elements that are going to be in the array

    int val, col = 10;
    vector<int> matrix[size];
    for (int i = 0; i < size; i++){
        for ( int j = 0; j < col; j++){
            cin >> val;
            matrix[i].push_back(val);
        }
    } 

    RadixSort(matrix, col, size);

    //sort(matrix.begin(), matrix.end());      //sorts the dang thing

    for (int i = 0; i < size; i++){
        for (int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << ";";
        }
        cout << endl;
    }

}