#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Gr;   
int n;                   
vector<bool> used;       

void addEdge(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        cout << "Ошибка: такой вершины нет!\n";
        return;
    }

    Gr[u].push_back(v);   
}

void printGr() {
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << " : ";

        sort(Gr[i].begin(), Gr[i].end());

        for (int j = 0; j < Gr[i].size(); j++) {
            cout << Gr[i][j] << " ";
        }

        cout << endl;
    }
}

void countAdj(int target) {
    if (target < 0 || target >= n) {
        cout << "\nВершины не существует!\n";
        return;
    }

    int count = Gr[target].size();

    cout << "Количество вершин, смежных с вершиной " << target << ": " << count << endl;

}

void resetUsed() {
    fill(used.begin(), used.end(), false);
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
    printGr();

    int t;
    cout << "\nВведите номер вершины: ";
    cin >> t;

    countAdj(t);

    resetUsed();
}