#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int STUDENT_NAME_LEN_MIN = 1;
const int STUDENT_NAME_LEN_MAX = 10;
const int STUDENT_SCORE_MIN = 1;
const int STUDENT_SCORE_MAX = pow(10, 5);
const int NUMBER_OF_STUDENTS_MIN = 1;
const int NUMBER_OF_STUDENTS_MAX = pow(10, 5);

char** createNamesArray(int n) {
    char** names = new char* [n];
    for (int i = 0; i < n; ++i) {
        names[i] = new char[STUDENT_NAME_LEN_MAX + 1];
    }
    return names;
}

size_t myStrlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

int myStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

struct Compare {
    char** names;
    int* scores;
    bool operator()(int a, int b) const {
        if (scores[a] != scores[b]) {
            return scores[a] > scores[b];
        }
        return myStrcmp(names[a], names[b]) < 0;
    }
};

int main() {
    int n;
    cin >> n;
    if (!cin || n < NUMBER_OF_STUDENTS_MIN || n > NUMBER_OF_STUDENTS_MAX) {
        cerr << "Invalid number of students" << endl;
        return 1;
    }

    char** names = createNamesArray(n);

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        if (!cin || myStrlen(names[i]) < STUDENT_NAME_LEN_MIN || myStrlen(names[i]) > STUDENT_NAME_LEN_MAX) {
            cerr << "Invalid name!" << endl;
            for (int j = 0; j <= i; ++j) {
                delete[] names[j];
            }
            delete[] names;
            return 1;
        }
    }

    int* scores = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
        if (!cin || scores[i] < STUDENT_SCORE_MIN || scores[i] > STUDENT_SCORE_MAX) {
            cerr << "Invalid score!" << endl;
            for (int j = 0; j < n; ++j) {
                delete[] names[j];
            }
            delete[] names;
            delete[] scores;
            return 1;
        }
    }

    int* indices = new int[n];
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    sort(indices, indices + n, Compare{ names, scores });

    for (int i = 0; i < n; ++i) {
        cout << names[indices[i]] << " " << scores[indices[i]] << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] names[i];
    }
    delete[] names;
    delete[] scores;
    delete[] indices;

    return 0;
}
