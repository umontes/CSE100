#include <iostream>

using namespace std;

//HW02, problem 6
// You're given n integers a1,a2,...,an. You're asked to test if the n integers consist of more 
// than k distinct integers; so k is a part of the input where 1 <= k  <= n. In other words, you 
// want to test if |{a1,a2,...,an}| > k or not. Given a linear time algorithm (in expectation).

int Algo(int arr[], int n, int k){

    int temp[n];
    for (int i = 0; i < n; i++){    //sets all elements of temp to 1. Min num of times a number in the array can show up.
        temp[i] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 1; j < n; j++){
            if (arr[i] == arr[j] && j > i){
                temp[i] = temp[i]+1;
            }
        }
    }

    int distinct = 0;
    for (int i = 0; i < n; i++){    //finds the amount of distinct integers in the array
        if (temp[i] == 1){
            distinct ++;
        }
    }

    // for (int i = 0; i < n; i++){     //prints the amount of times each number appeared in the array
    //     cout << temp[i] << " "<< endl;
    // }

    if (distinct > k){
        //cout << "There are > " << k << " distinct integers" << endl;
        cout << "YES -> " << distinct << " distinct integers" << endl;
    }
    else {
        //cout << "There are < " << k << " distinct integers" << endl;
        cout << "NO -> " << distinct << " distinct integers" << endl;
    }
    
}

int main(){

    cout << "size of arr: ";
    int n;
    cin >> n;
    cout << endl;

    cout << "elements of arr:" << endl;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter integer k: ";
    cin >> k;
    cout << endl;

    cout << "Does the array have more than " << k << " distinct integers?" << endl;

    Algo(arr, n, k);

}