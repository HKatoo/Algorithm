#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) cout << (x) << endl
typedef long long ll;

int pivot(int a[], int l, int r) {
    int i = l + 1;
    while (i <= r && a[l] == a[i]) i++;
    if (i > r) return -1;
    if (a[l] >= a[i]) return l;
    return i;
}

int partition(int a[], int l, int r, int pivot) {
    int i = l, j = r;
    while (i < j) {
        while (i <= r && a[i] < pivot) i++;
        while (j >= l && a[j] >= pivot) j--;
        if (i > j) break;
        // swap(a[i], a[j]);
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    return i;
}

void quickSort(int a[], int l, int r) {
    if (l >= r) return;
    int p = pivot(a, l, r);
    if (p != -1) {
        int m = partition(a, l, r, a[p]);
        quickSort(a, l, m - 1);
        quickSort(a, m, r);
    }
}

int main() {
    ifstream in("test.txt");
    cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "before: ";
    for (auto i : a) cout << i << " ";
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "after: ";
    for (auto i : a) cout << i << " ";
    cout << endl;
}
