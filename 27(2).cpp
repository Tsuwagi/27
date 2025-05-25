// Визначити номер стовпця, в якому розташована щонайдовша серія однакових елементів

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int M = 6, N = 5;

void create_matrix(double matr[M][N], const char* name) {
    FILE* f = fopen(name, "rt");
    if (f == NULL) {
        cout << "Cannot open file\n";
        return;
    }

    char s[100], *t;
    int i = 0, j;
    while (fgets(s, 100, f) && i < M) {
        j = 0;
        t = strtok(s, " \t\n");
        while (t != NULL && j < N) {
            matr[i][j] = atof(t);
            t = strtok(NULL, " \t\n");
            j++;
        }
        i++;
    }
    fclose(f);
}

void number_col(double matr[M][N], const char* name) {
    int mlen = 0;
    int col = 0;

    for (int j = 0; j < N; j++) {
        int len = 1;
        for (int i = 1; i < M; i++) {
            if (matr[i][j] == matr[i - 1][j])
                len++;
            else
                len = 1;
            if (len > mlen)
                mlen = len, 
                col = j;
        }
    }

    cout << "\nНайдовша серія однакових елементів у стовпці: " << col << "\n";
}

int main() {
    double A[M][N];
    const char name1[] = "F1.txt";

    create_matrix(A, name1);
    number_col(A, name1);
    return 0;
}
