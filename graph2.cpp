#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Gr;  
int n;                    

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

int main() {
    cout << "Введите количество вершин: ";
    cin >> n;

    Gr.resize(n);

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

    cout << "\nИсходный граф:\n";
    printGr();

    int A, B;
    cout << "\nВведите вершины A и B для добавления нового ребра A -> B: ";
    cin >> A >> B;

    addEdge(A, B);

    cout << "\nГраф после добавления ребра:\n";
    printGr();
}