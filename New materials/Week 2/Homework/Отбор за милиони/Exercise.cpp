#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[(left + right) / 2];

    int i = left;
    int j = right;

    while (true) {

        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);

        i++;
        j--;
    }
}

void quickSort(int arr[], int left, int right) {

    if (left >= right)
        return;

    int p = partition(arr, left, right);

    quickSort(arr, left, p);
    quickSort(arr, p + 1, right);
}

int main() {

    int N;
    cin >> N;

    string s;
    cin >> s;

    int* players = new int[N];

    for (int i = 0; i < N; i++) {

        if (s[i] >= '0' && s[i] <= '9')
            players[i] = s[i] - '0' + 1;

        else if (s[i] >= 'a' && s[i] <= 'z')
            players[i] = s[i] - 'a' + 11;

        else
            players[i] = s[i] - 'A' + 37;
    }

    quickSort(players, 0, N - 1);

    for (int i = 0; i < N; i++) {

        if (players[i] <= 10)
            cout << char(players[i] - 1 + '0');

        else if (players[i] <= 36)
            cout << char(players[i] - 11 + 'a');

        else
            cout << char(players[i] - 37 + 'A');
    }

    delete[] players;

    return 0;
}
