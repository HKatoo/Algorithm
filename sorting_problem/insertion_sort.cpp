#include <fstream>
#include <iostream>

using namespace std;

// O(n^2)
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

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    cout << "after: ";
    for (auto i : a) cout << i << " ";
    cout << endl;
}
