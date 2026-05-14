#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Gr;
vector<int> color;
vector<int> order;
int n, m;
bool hasCycle = false;

void addEdge(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Ошибка: такой вершины нет!\n";
        return;
    }

    Gr[u].push_back(v);
}

void dfs(int v) {
    color[v] = 1;

    for (int i = 0; i < Gr[v].size(); i++) {
        int to = Gr[v][i];

        if (color[to] == 0) {
            dfs(to);
        } else if (color[to] == 1) {
            hasCycle = true;
        }
    }

    color[v] = 2;
    order.push_back(v);
}

int main() {
    cout << "Введите количество вершин: ";
    cin >> n;

    Gr.resize(n);
    color.resize(n, 0);

    cout << "Введите количество ребер: ";
    cin >> m;

    cout << "\nВведите ребра:\n";

    for (int i = 0; i < m; i++) {
        int u, v;

        cout << "Ребро " << i + 1 << ": ";
        cin >> u >> v;

        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    if (hasCycle) {
        cout << "\nНе выполнится - есть цикл\n";
        return 0;
    }

    reverse(order.begin(), order.end());
    
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }

    cout << endl;
}