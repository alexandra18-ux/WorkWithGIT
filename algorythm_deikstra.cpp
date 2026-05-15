#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

map<int, list<pair<int, int>>> Gr;
int n;

void addEdge(int u, int v, int w) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Ошибка: такой вершины нет!\n";
        return;
    }

    for (auto it = Gr[u].begin(); it != Gr[u].end(); it++) {
        if (it->first == v) {
            cout << "Ребро уже существует!\n";
            return;
        }
    }

    Gr[u].push_back(make_pair(v, w));
    Gr[v].push_back(make_pair(u, w));
}

void print() {
    for (auto it = Gr.begin(); it != Gr.end(); it++) {
        cout << "Вершина " << it->first << " : ";

        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << "{" << it2->first << ", вес " << it2->second << "} ";
        }

        cout << endl;
    }
}

void printPath(int v, vector<int>& parent) {
    if (v == -1) {
        return;
    }

    printPath(parent[v], parent);
    cout << v << " ";
}

void deikstra(int start) { //я выбрала алгоритм дейкстра
    vector<int> dist(n, 100000);
    vector<int> parent(n, -1);
    vector<bool> used(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        if (v == -1 || dist[v] == 100000) {
            break;
        }

        used[v] = true;

        for (auto it = Gr[v].begin(); it != Gr[v].end(); it++) {
            int to = it->first;
            int weight = it->second;

            if (dist[v] + weight < dist[to]) {
                dist[to] = dist[v] + weight;
                parent[to] = v;
            }
        }
    }

    cout << "\nКратчайшие пути из вершины " << start << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "До вершины " << i << ": ";

        if (dist[i] == 100000) {
            cout << "пути нет\n";
        } else {
            cout << "длина = " << dist[i] << ", путь: ";
            printPath(i, parent);
            cout << endl;
        }
    }
}

int main() {
    cout << "Введите количество вершин: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Gr[i];
    }

    int m;
    cout << "Введите количество ребер: ";
    cin >> m;

    cout << "\nВведите ребра в формате: откуда куда вес\n";

    for (int i = 0; i < m; i++) {
        int u, v, w;

        cout << "Ребро " << i + 1 << ": ";
        cin >> u >> v >> w;

        addEdge(u, v, w);
    }

    cout << "\nСписок смежности графа:\n";
    print();

    int start;
    cout << "\nВведите начальную вершину: ";
    cin >> start;

    deikstra(start);
}