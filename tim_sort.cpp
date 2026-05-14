#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void merge(vector<int>& arr, int left, int cent, int right) {
    int l1 = cent - left + 1;
    int l2 = right - cent;

    vector<int> leftArr(l1);
    vector<int> rightArr(l2);

    for (int i = 0; i < l1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < l2; i++) {
        rightArr[i] = arr[cent + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < l1 && j < l2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    while (i < l1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < l2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void timSort(vector<int>& arr, int n) {
    int run = 32;
    for (int i = 0; i < n; i += run) { //сортировка частей
        insertionSort(arr, i, min(i + run - 1, n - 1));
    }

    for (int size = run; size < n; size *= 2) { //соединяем

        for (int left = 0; left < n; left += 2 * size) {

            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    timSort(arr, n);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}