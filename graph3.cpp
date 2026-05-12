#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Gr;   
int n;                   
vector<bool> used;        

void resetUsed() {
    fill(used.begin(), used.end(), false);
}

void addEdge(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Ошибка: такой вершины нет!\n";
        return;
    }

    for (int i = 0; i < Gr[u].size(); i++) {
        if (Gr[u][i] == v) {
            cout << "Ребро уже существует!\n";
            return;
        }
    }

    Gr[u].push_back(v);   
}

void dfs(int x) {
    used[x] = true;

    for (int i = 0; i < Gr[x].size(); i++) {
        if (!used[Gr[x][i]]) {
            dfs(Gr[x][i]);
        }
    }
}

void printUnreachable(int start) {
    resetUsed();
    dfs(start);

    cout << "\nВершины, недостижимые из вершины " << start << ": ";

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << " : ";

        sort(Gr[i].begin(), Gr[i].end());

        for (int j = 0; j < Gr[i].size(); j++) {
            cout << Gr[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    cout << "Введите количество вершин: ";
    cin >> n;

    Gr.resize(n);
    used.resize(n, false);

    int m;
    cout << "Введите количество ребер: ";
    cin >> m;

    cout << "\nВведите ребра в формате: откуда куда\n";

    for (int i = 0; i < m; i++) {
        int u, v;

        cout << "Ребро " << i + 1 << ": ";
        cin >> u >> v;

        addEdge(u, v);
    }

    cout << "\nСписок смежности графа:\n";
    print();

    int start;
    cout << "\nВведите вершину, из которой нужно проверить достижимость: ";
    cin >> start;

    printUnreachable(start);
}