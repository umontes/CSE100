#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//.....Lab11
//.....Minimum Spanning Tree -- ch23

//---------------------------------------------------------------------
int Min(vector<int> Q, int V, int keys[]){

    int min = INT_MAX;
    int min_index;

   vector<int>::iterator i;
   for (i = Q.begin(); i < Q.end(); i++){
       if (min > keys[*i]){
           min = keys[*i];
           min_index = *i;
       }
   }
   return min_index;
   
}
//---------------------------------------------------------------------


//---------------------------------------------------------------------
int main(){

    int V,E;
    cin >>V>>E;

    int** W = new int*[V];
    for (int i = 0; i < V; i++){
        W[i] = new int[V];
    }

    vector<int>* G = new vector<int>[V];
    for (int i = 0; i < E; i++){
        int u,v,w;
        cin >>u>>v>>w;
        W[u][v] = w;
        W[v][u] = w;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> Q;
    int* parents = new int[V];
    int* keys = new int[V];
    int* mst = new int[V];
    for (int i = 0; i < V; i++){
        keys[i] = INT_MAX;
        parents[i] = NULL;
        Q.push_back(i);    //Insert(Q,u)
    }
    keys[0] = 0;    //Decrease-key(Q,r,0)

    while (Q.empty() == false){

        int u = Min(Q, V, keys);

        vector<int>::iterator i;
        int count = 0;
        for(i = Q.begin(); i < Q.end(); i++){   //extract element at index u from the Q 
            if (*i == u){
                Q.erase(Q.begin() + count);
            }
            count ++;
        }

        vector<int>::iterator v;
        for (v : G[u]){ // for all v in G[u]
            for (int k = 0; k < Q.size(); k++){
                if (Q.at(k) == v && W[u][v] < keys[v]){
                    parents[v] = u;
                    keys[v] = W[u][v];  //Decrease-key(Q,v,W[u][v])
                }
            }
        }
    }

    for (int i = 1; i < V; i++){    // print the parents except the root(it does not have a parent)
        cout << parents[i] << endl;
    }

    return 0;

}
//---------------------------------------------------------------------