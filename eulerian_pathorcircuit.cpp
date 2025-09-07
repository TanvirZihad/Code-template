#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Euleriandirected {
    int V,M;
    vector<vector<int>> adj;
    vector<int> in_deg, out_deg;
    int cnt=0;

public:
    Euleriandirected(int V,int M) {
        this->V = V;
        this->M=M;
        adj.resize(V);
        in_deg.resize(V, 0);
        out_deg.resize(V, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        out_deg[u]++;
        in_deg[v]++;
    }

    int getEulerType() {
        int start_nodes = 0, end_nodes = 0;
        for (int i = 0; i < V; ++i) {
            if (out_deg[i] - in_deg[i] == 1) start_nodes++;
            else if (in_deg[i] - out_deg[i] == 1) end_nodes++;
            else if (in_deg[i] != out_deg[i]) return 0;
        }

        if (start_nodes == 0 && end_nodes == 0) return 2; // Eulerian Circuit
        if (start_nodes == 1 && end_nodes == 1) return 1; // Eulerian Path
        return 0;
    }

    void findEulerPathOrCircuit() {
        int type = getEulerType();
        if (type == 0) {
            cout << "No\n";
            return;
        }

        int start = 0;
        if (type == 1) {
            for (int i = 0; i < V; ++i) {
                if (out_deg[i] - in_deg[i] == 1) {
                    start = i;
                    break;
                }
            }
        } else {
            for (int i = 0; i < V; ++i) {
                if (!adj[i].empty()) {
                    start = i;
                    break;
                }
            }
        }

        vector<int> path;
        hierholzer(start, path);

        reverse(path.begin(), path.end());
      if(path.size()!=M+1){
        cout<<"Graph not connected\n";
        return;
      }
        cout<<"Yes\n";
        for (int v : path)
            cout << v << " ";
          cout << endl;
    }

    void hierholzer(int v, vector<int>& path) {
        while (!adj[v].empty()) {
            int u = adj[v].back();
            adj[v].pop_back();
            hierholzer(u, path);
        }
        path.push_back(v);
    }
};





struct Edge {
    int to;
    int id;
};
class EulerianUndirected {
    int V, E;
    vector<vector<Edge>> adj;
    vector<bool> used;
    vector<int> deg;

public:
    EulerianUndirected(int n, int m) {
        V = n;
        E = m;
        adj.resize(n);
        used.resize(m, false);
        deg.resize(n, 0);
    }

    void addEdge(int u, int v, int id) {
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
        deg[u]++;
        deg[v]++;
    }

    int getEulerType() {
        int odd = 0;
        for (int i = 0; i < V; ++i)
            if (deg[i] % 2 != 0) odd++;

        if (odd == 0) return 2;     // Eulerian Circuit
        if (odd == 2) return 1;     // Eulerian Path
        return 0;                   // No Eulerian Trail
    }

    void findEuler() {
        int type = getEulerType();
        if (type == 0) {
            cout << "No\n";
            return;
        }

        int start = 0;
        if (type == 1) {
            for (int i = 0; i < V; ++i)
                if (deg[i] % 2 != 0) {
                    start = i;
                    break;
                }
        } else {
            for (int i = 0; i < V; ++i)
                if (!adj[i].empty()) {
                    start = i;
                    break;
                }
        }

        vector<int> path, edge_path;
        dfs(start, path, edge_path);

        if (path.size() != E + 1) {
            cout << "No\n";
            return;
        }
        reverse(path.begin(),path.end());
        cout << "Yes\n";
        for (int v : path) cout << v << " ";
        cout << "\n";
        for (int e : edge_path) cout << e << " ";
        cout << "\n";
    }

    void dfs(int v, vector<int>& path, vector<int>& edge_path) {
        for (auto e:adj[v]) {
            
            if (used[e.id]) continue;
            used[e.id] = true;
            dfs(e.to, path, edge_path);
            edge_path.push_back(e.id);
        }
        path.push_back(v);
    }
};

