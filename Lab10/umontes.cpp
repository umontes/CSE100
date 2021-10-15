#include <iostream>
#include <stack>
#include <vector> 
using namespace std;

//.....Lab10
//.....Strongly Connected Components (SCC) -- ch22

//------------------------------------------------------------------------------------------
int DFS2(vector<int>* GT, int v, int V, bool* visited, int* sccID){

    visited[v] = true;  //vertex has now been visited
    sccID[v] = V;

    vector<int>::iterator i;
    for (i : GT[v]){
        if (visited[i] == false){
            DFS2(GT, i, V, visited, sccID);
        }
    }

}
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
int DFS(int v, bool* visited, stack<int> &stack, vector<int>* G){

    visited[v] = true;  //vertex has now been visited

    vector<int>::iterator i;
    for (i : G[v]){
        if (visited[i] == false){
            DFS(i, visited, stack, G);
        }
    }
    stack.push(v);

}
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
int main(){

    int V, E;
    cin >> V >> E;

    vector<int>* G = new vector<int>[V];
    vector<int>* GT = new vector<int>[V];
    for (int i = 0; i < E; i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);  //graph
        GT[v].push_back(u); //transpose of graph
    }
    
    bool* visited = new bool[V];
    stack<int> stack;
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            DFS(i, visited, stack, G);     //fill the stack
        }
    }

    for (int i = 0; i < V; i++){    //change all elements back to false for the DFS2
        visited[i] = false;
    }

    int* sccID = new int[V];    //going to safe the values of the SCCID in this array
    for (int i = 0; i < V; i++){

        int v = stack.top();
        stack.pop();

        if (visited[v] == false){
            DFS2(GT, v, v, visited, sccID);
            int min = v;
            for (int i = 0; i < V; i++){
                if (sccID[i] == v){
                    if (min > i){
                        min = i;
                    }
                }
            }

            for (int i = 0; i < V; i++){
                if (sccID[i] == v){
                    sccID[i] = min;
                }
            }

        }

    }

    for (int i = 0; i < V; i++){    //print the SCCID for each vertex
        cout << sccID[i] << endl;
    }

    delete[] sccID;
    delete[] visited;

    return 0;

}
//------------------------------------------------------------------------------------------