#include <iostream>
#include <limits.h>

using namespace std;

//.....Lab07
//.....Dynamic Programming: Rod Cutting

//-----------------------------------------
int PrintCutRodSol(int prices[], int length, int r[], int s[]){

    while (length > 0){
        cout << s[length] << " ";
        length = length - s[length];
    }
}
//-----------------------------------------

//...

//-----------------------------------------
int ExtBotUpCutRod(int prices[], int length, int r[], int s[]){

    int rev;

    r[0] = 0;

    for (int j = 1; j <= length; j++){
        rev = INT_MIN;
        for (int i = 1; i <= j; i++){
            if (rev < prices[i-1] + r[j-i]){
                rev = prices[i-1] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = rev;
    }
// for exam (lines 36-45)
    // int val = length;
    // int k = 0;

    // while (length > 0){
    //     length = length- s[length];
    //     k++;
    // }
    // k = k-1;

    // cout << "with cut charge -> " << r[val] - k*k << endl;
// for exam

    PrintCutRodSol(prices, length, r, s);

}
//-----------------------------------------

//...

//-----------------------------------------
int BotUpCutRod(int prices[], int length, int r[], int s[]){

    int rev;

    r[0] = 0;

    for (int j = 1; j <= length; j++){
        rev = INT_MIN;
        for (int i = 0; i < j; i++){
            rev = max(rev, prices[i] + r[j-i-1]);
        }
        r[j] = rev;
    }

    return r[length];

}
//-----------------------------------------

//...

//-----------------------------------------
int max(int a, int b){

    if (a == b){
        return a;
    }
    else if (a > b){
        return a;
    }
    else {
        return b;
    }
    
}
//-----------------------------------------

//...

//-----------------------------------------
int main (int argc, char **argv){

    int length;
    cin >> length;

    int prices[length];
    int r[length+1];
    int s[length+1];

    for (int i = 0; i < length; i++){
        cin >> prices[i];
    }

    cout << BotUpCutRod(prices, length, r, s) << endl;
    ExtBotUpCutRod(prices, length, r, s);
    cout << "-1" << endl;
    
} 
//-----------------------------------------