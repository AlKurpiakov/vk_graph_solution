#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& graph, int startVert, vector<int>& distances){ 
    queue<int> queue;
    queue.push(startVert);
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        for (int neighbor : graph[current]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                queue.push(neighbor);
            }
        }
    }
}


int main(){
    
    ifstream filestream("graph.txt");
    if (!filestream){
        cerr << "Failed to open file" << endl;
        return 1;
    }
    
    size_t numVerts, numEdges;
    filestream >> numVerts >> numEdges;

    vector<vector<int>> graph(numVerts);

    for (size_t i = 0; i < numEdges; i++){
        int u,v;
        filestream >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);        
    }

    int startVert;
    filestream >> startVert;

    filestream.close();

    vector<int> distances(numVerts, -1);
    distances[startVert] = 0;

    BFS(graph, startVert, distances);


    for(int i = 0; i < distances.size(); i++)
        cout << distances[i] << endl;
    

    return 0;

}