#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main(){
    int V, E;
    cout<<"Enter no of vertices and edges: ";
    cin>>V>>E;

    vector<Edge> edges(E);

    cout<<"Enter edges (u, v, w): \n";
    for(int i = 0; i<E; i++)
        cin>>edges[i].u >>edges[i].v >> edges[i].w;

    int src;
    cout<<"Enter source vertex: ";
    cin>>src;


    vector<int> dist(V);
    for(int i = 0; i< V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i = 1; i<V-1; i++){
        for(auto &e : edges){
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    bool hasNegCycle = false;
    for(auto &e : edges){
        if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]){
            hasNegCycle = true;
            break;
        }
    }

    if(hasNegCycle){
        cout<<"Graph has negative cycle\n";
    }else {
        cout<<"No negative cycle\n";
        for(int i = 0; i< V; i++)
            cout<< "Distance to vertex " << i << " = " << dist[i] << "\n";
    }
}

// Enter no of vertices and edges: 4 5
// Enter edges (u, v, w): 
// 0 1 1
// 1 2 -1
// 2 3 -1
// 3 1 -1
// 0 2 4
// Enter source vertex: 0
// Graph has negative cycle