#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> Gr;
vector<bool> usedEdge;
vector<int> path;
vector<bool> used;
int n, m;

void addEdge(int u, int v, int id) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Ошибка: такой вершины нет!\n";
        return;
    }

    Gr[u].push_back({v, id});
    Gr[v].push_back({u, id});
}

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < Gr[v].size(); i++) {
        if (!used[Gr[v][i].first]) {
            dfs(Gr[v][i].first);
        }
    }
}

void euler(int v) {
    while (!Gr[v].empty()) {
        int to = Gr[v].back().first;
        int id = Gr[v].back().second;

        Gr[v].pop_back();

        if (usedEdge[id]) {
            continue;
        }

        usedEdge[id] = true;
        euler(to);
    }

    path.push_back(v);
}

int main() {
    cout << "Введите количество вершин: ";
    cin >> n;

    Gr.resize(n);
    used.resize(n, false);

    cout << "Введите количество ребер: ";
    cin >> m;

    usedEdge.resize(m, false);

    cout << "\nВведите ребра:\n";

    for (int i = 0; i < m; i++) {
        int u, v;

        cout << "Ребро " << i + 1 << ": ";
        cin >> u >> v;

        addEdge(u, v, i);
    }

    vector<int> odd;

    for (int i = 0; i < n; i++) {
        if (Gr[i].size() % 2 == 1) {
            odd.push_back(i);
        }
    }

    if (!(odd.size() == 0 || odd.size() == 2)) {
        cout << "\nЭйлерова пути и цикла нет\n";
        return 0;
    }

    int start = 0;

    if (odd.size() == 2) {
        start = odd[0];
    } else {
        for (int i = 0; i < n; i++) {
            if (!Gr[i].empty()) {
                start = i;
                break;
            }
        }
    }

    dfs(start);

    for (int i = 0; i < n; i++) {
        if (!Gr[i].empty() && !used[i]) {
            cout << "\nГраф несвязный, не выполнится\n";
            return 0;
        }
    }

    euler(start);
    reverse(path.begin(), path.end());

    if (path.size() != m + 1) {
        cout << "\nЭйлерова пути и цикла нет\n";
        return 0;
    }

    if (odd.size() == 0) {
        cout << "\nЭйлеров цикл:\n";
    } else {
        cout << "\nЭйлеров путь:\n";
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];

        if (i + 1 < path.size()) {
            cout << " -> ";
        }
    }

    cout << endl;
}