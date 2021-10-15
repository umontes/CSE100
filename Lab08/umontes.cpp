#include <iostream>
#include <limits.h>

using namespace std;

//.....Lab08
//.....Dynamic Programming: Matrix Chain Multiplication

//VERSION 3 (with double pointers)
//------------------------------------------------
int PrintOptimalParens(int **s, int i, int j){

    if (i == j){
        cout << "A" << i-1;
    }

    else {
        cout << "(";
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j]+1, j);
        cout << ")";
    }

}
//------------------------------------------------

//...

//------------------------------------------------
int MatrixChainOrder(int arr[], int n){

    int **m = new int*[n];
    int **s = new int*[n];

    for (int i = 0; i < n; i++){
        m[i] = new int[n];
        s[i] = new int[n];
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++){
        for (int i = 1; i < n-l+1; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j-1; k++){
                int q = m[i][k] + m[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[1][n-1] << endl;
    PrintOptimalParens(s, 1, n-1);

}
//------------------------------------------------

//...

//------------------------------------------------
int main(int argc, char **argv){

    int n; cin >> n;

    int arr[n+1];

    for (int i = 0; i <= n; i++){
        cin >> arr[i];
    }

    MatrixChainOrder(arr, n+1);
    cout << endl;

}
//------------------------------------------------




//MATRIX-CHAIN-ORDER(p)
//1      n = p.length-1
//2      let m[1...n, 1...n] and s[1...n-1, 2...n] be new tables
//3      for i = 1 to n
//4          m[i,i] = 0
//5      for l = 2 to n      l is the chain length
//6          for i = 1 to n-l+1
//7              j = i + l-1
//8              m[i,j] = infinity
//9              for k = i to j-1
//10                  q = m[i,k] + m[k+1,j] + P_(i-1)*P_k*P_j
//11                  if q < m[i,j]
//12                      m[i,j] = q
//13                      s[i,j] = k
//14      return m and s


//PRINT-OPTIMAL-PARENS(s, i, j)
//1     if i == j
//2         print "A"i
//3     else print "("
//4         PRINT-OPTIMAL-PARENS(s, i, s[i,j])
//5         PRINT-OPTIMAL-PARENS(s, s[i,j]+1, j)
//6         print ")"