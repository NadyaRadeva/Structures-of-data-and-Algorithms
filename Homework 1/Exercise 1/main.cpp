#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;

const int MIN_VALUE_OF_N = 1;
const int MAX_VALUE_OF_N = 20000000;
const int VALUE = 62;

char intToChar(int n) {
    if (n >= 1 && n <= 10) {
        return '0' + (n - 1);
    }

    if (n >= 11 && n <= 36) {
        return 'a' + (n - 11);
    }

    if (n >= 37 && n <= 62) {
        return 'A' + (n - 37);
    }

    return '\0';
}

void countingSort(int arr[], int n) {
    int* count = new int[VALUE + 1]();
    int* output = new int[n];

    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= VALUE; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void sortPlayers(int arr[], int n) {
    countingSort(arr, n);
}

int main() {
    int n;
    cin >> n;

    if (!cin || n < MIN_VALUE_OF_N || n > MAX_VALUE_OF_N) {
        cerr << "Invalid input!" << std::endl;
        return 1;
    }

    int* players = new int[n];
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;

        if (ch >= '0' && ch <= '9') {
            players[i] = ch - '0' + 1;
        }
        else if (ch >= 'a' && ch <= 'z') {
            players[i] = ch - 'a' + 11;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            players[i] = ch - 'A' + 37; 
        }
        else {
            cerr << "Invalid character!" << std::endl;
            delete[] players;
            return 1;
        }
    }

    sortPlayers(players, n);

    for (int i = 0; i < n; ++i) {
        cout << intToChar(players[i]);
    }
    cout << '\n';

    delete[] players;
    return 0;
}
