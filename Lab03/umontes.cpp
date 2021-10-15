#include <iostream>
#include <limits.h>

using namespace std;

//.....Lab03
//.....Solving Max Subarray Problem Via Divide-and-Conquer

int FindMaxCrossingSubarray(int *arr, int low, int mid, int high){
    int sum = 0;
    int max_left, max_right;
    int left_sum, right_sum;

    left_sum = INT_MIN;
    for (int i = mid; i >= low; i--){
        sum = sum + arr[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    right_sum = INT_MIN;
    sum = 0;
    for (int j = mid+1; j <= high; j++){
        sum = sum + arr[j];
        if (sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return (max_left, max_right, (left_sum + right_sum));
}

int FindMaxSubarray (int *arr, int low, int high){
    int mid;
    int left_low, left_high, left_sum;
    int right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum; 

    if (low == high) {
        return (low, high, arr[low]);
    }
    
    else {
        mid = (low + high) / 2;
        (left_low, left_high, left_sum) = FindMaxSubarray(arr, low, mid);
        (right_low, right_high, right_sum) = FindMaxSubarray(arr, mid+1, high);
        (cross_low, cross_high, cross_sum) = FindMaxCrossingSubarray(arr, low, mid, high);

        if ((left_sum >= right_sum) && (left_sum >= cross_sum)){
            return (left_low, left_high, left_sum);
        }
        else if ((right_sum >= left_sum) && (right_sum >= cross_sum)){
            return (right_low, right_high, right_sum);
        }
        else if ((cross_sum >= left_sum) && (cross_sum >= right_sum)) {
            return (cross_low, cross_high, cross_sum);
        }
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

    cout << FindMaxSubarray(Sequence, 0, arraySize-1);

    delete[] Sequence;
}