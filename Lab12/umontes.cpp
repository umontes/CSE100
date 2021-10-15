#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//.....Lab12
//.....The Bellman-Ford Algorithm -- ch24

int main(){

    int V, E;   //no. of vertices and edges
    cin >> V >> E;    

    int** W = new int*[V];      //the wieghts
    for (int i = 0; i < V; i++){
        W[i] = new int[V];
    }

    vector<int>*G = new vector<int>[V];
    for (int i = 0; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back(v);
        W[u][v] = w;        //the weights of each edge
    }

    int* dist = new int[V];
    for (int i = 0; i < V; i++){    //Initialize-Single-Source. Bellman-Ford starts here
        dist[i] = 214748364;
    }
    dist[0] = 0;

    vector<int>::iterator v;
    for (int i = 0; i < V; i++){
        for (int u = 0; u < V; u++){
            for (v : G[u]){
                if (dist[v] > dist[u] + W[u][v]){   //Relax(u,v,W)
                    dist[v] = dist[u] + W[u][v];
                }
            }
        }
    }

    for (int u = 0; u < V; u++){   
        for (v : G[u]){
            if (dist[v] > dist[u] + W[u][v]){   //check for negative weight cycles
                cout << "FALSE" << endl;
                return 0;
            }
        }
    }

    cout << "TRUE" << endl;
    for (int i = 0; i < V; i++){    
        if (dist[i] == 214748364){    //check for a vertex that cannot be reached
            cout << "INFINITY" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;

}

// Bellman-Ford(G,w,s)  //<-
//     Initialize-Single-Source(G,s)    
//     for i=1 to |G.V|-1
//         for each edge(u,v) in G.E
//             Relax(u,v,w)
//     for each edge (u,v) in G.E
//         if v.d > u.d + w(u,v)
//             return FALSE
//     return TRUE

// Initialize-Single-Source(G,s)    //<-
//     for each vertex v in G.V
//         v.d = INFINITY
//         v.pi = NULL
//     s.d = 0

// Relax(u,v,w)     //<-  
//     if v.d > u.d + w(u,v)
//         v.d = u.d + w(u,v)
//         v.pi = u