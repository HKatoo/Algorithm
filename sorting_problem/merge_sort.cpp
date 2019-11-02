#include <fstream>
#include <iostream>

using namespace std;

// O(nlogn)
void merge(int a[], int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;
    int l[n + 1], r[m + 1];
    for (int i = 0; i < n; i++) {
        l[i] = a[left + i];
    }
    for (int i = 0; i < m; i++) {
        r[i] = a[mid + i + 1];
    }
    l[n] = 1e9;
    r[m] = 1e9;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
    }
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    ifstream in("test.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "before: ";
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;

    mergeSort(a, 0, n - 1);

    cout << "after: ";
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}
