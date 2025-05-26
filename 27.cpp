//Обчислити елементи вектора як суми елементів парних рядків матриці

#include <iostream>
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

void create_vector(double matr[M][N], double vekt[N]) 
   
    for (int j = 0; j < N; j++){
        vekt[j] = 0;}

    for (int i = 1; i < M; i += 2) {
        for (int j = 0; j < N; j++) {
            vekt[j] += matr[i][j];
        }
    }

    for (int j = 0; j < N; j++) {
        cout << vekt[j] << "\t";
    }
}

int main() {
    double A[M][N], B[N];
    const char name1[] = "F1.txt";

    create_matrix(A, name1);
    create_vector(A, B);

    return 0;
}
