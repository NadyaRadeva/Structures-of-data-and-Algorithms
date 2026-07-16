#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long* arr = new long long[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
        
        if ((i + 1) % 2 == 0) {
            cout << ((double)(arr[i/2]) + static_cast<double>(arr[i/2 + 1])) / 2.0 << endl;
        } else {
            cout << (double)(arr[i/2]) << endl;
        }
    }
    
    delete[] arr;
    return 0;
}
