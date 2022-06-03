#include <iostream>
#include <windows.h>
#include <math.h>
#include <clocale>
using namespace std;
const int n = 25;
int vivod_matrici(int a, int array[n][n]) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[n][n], arr2[n][n];
    int arr1[n];
    int M, sum = 0, c = 0, max = INT_MIN;
    cout << "Введите размерность матрицы: ";
    cin >> M;
    srand(time(0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = rand() % 15;
        }
    }
    cout << "Ваша матрица: " << "\n";
    vivod_matrici(M, arr);
    for (int i = M - 2; i > 0; i--) {
        sum = 0;
        for (int j = 0; j < M - 1; j++) {
            sum += arr[i - j][j];
        }
        arr1[c] = sum;
        c += 1;
    }
    for (int i = 0; i < M; i++) { // Переворачиваем матрицу на 180* :)
        for (int j = 0; j < M; j++) {
            arr2[i][j] = arr[M - i - 1][M - j - 1];
        }
    }
    sum = 0;
    for (int i = M - 2; i > 0; i--) {
        sum = 0;
        for (int j = 0; j < M - 1; j++) {
            sum += arr2[i - j][j];
        }
        arr1[c] = sum;
        c += 1;
    }
    for (int i = 0; i < c; i++) {
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }
    cout << "\n" << "Максимум, среди сумм диагоналей: " << max;
}