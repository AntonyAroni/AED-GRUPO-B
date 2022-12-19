#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;
class Graph
{
private:
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
    void BSFUtil(int v, bool visited[]);
    int minDistance(const int dist[], const bool sptSet[]) const;
    void Dijkstra(int src, int dist[]);
    void dot(ostream &file);
public:
    explicit Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void BSF(int v);
    void Djikstra(int v);
    void dot(const string& filename);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::dot(ostream &file)
{
    for(int i=0; i<V; i++)
    {
        file<<"node_"<<i<<" [label = \"<m> "<< i <<"\"];\n";
        for(auto j:adj[i])
        {
            file<<"node_"<<i<<":l -> node_"<<j<<":m;\n";
        }
    }
}
void Graph::dot(const string& filename){
    ofstream mydot;
    mydot.open(filename, ios::out);
    mydot << "digraph g {\n";
    mydot<< "node [shape = record];\n";
    dot(mydot);
    mydot << "}\n";
    mydot.close();
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}


void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    cout<<endl;
    cout<<"DFS con el vertice "<<v<<": ";
    for(int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}


void Graph::BSFUtil(int v, bool *visited) {
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);

    list<int>::iterator i;

    while(!queue.empty())
    {
        v = queue.front();
        cout << v << " ";
        queue.pop_front();

        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::BSF(int v) {
    bool *visited = new bool[V];
    cout<<endl;
    cout<<"BSF con el vertice "<<v<<": ";
    for(int i = 0; i < V; i++)
        visited[i] = false;

    BSFUtil(v, visited);
}


int Graph::minDistance(const int *dist, const bool *sptSet) const {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Graph::Dijkstra(int src, int *dist) {
    bool *sptSet = new bool[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!sptSet[*i] && dist[u] != INT_MAX && dist[u] + 1 < dist[*i])
                dist[*i] = dist[u] + 1;
    }
}

void Graph::Djikstra(int v) {
    int *dist = new int[V];
    Dijkstra(v, dist);
    cout<<endl;
    cout<<"Djikstra con el vertice "<<v<<":";
    for (int i = 0; i < V; i++)
        cout <<" "<<dist[i];

}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.dot("graph.dot");
    g.DFS(2);
    g.BSF(2);
    g.Djikstra(2);

    return 0;
}

