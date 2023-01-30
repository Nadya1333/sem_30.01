#include <iostream>
#include <ctime>
#include <random>
#include <chrono>


void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void fillMatrix(int** arr, int n, int m) {
    std::mt19937 mt_engine(
        std::chrono::system_clock::now().
        time_since_epoch().count()
    );
    std::uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = dist(mt_engine);
        }
    }
}

int sumDiagonal(int** matrix, int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += matrix[i][i];
    }
    return ans;
}

template <typename T>
void fillArrayKB(T* arr, int s) {
    for (int i = 0; i < s; ++i) {
        std::cin >> arr[i];
    }
}

template <typename T>
void printArray(T* arr, int s) {
    for (int i = 0; i < s; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T sum(T* arr, int left, int right) {
    T ans = 0;
    for (int i = left; i < right; ++i) {
        ans += arr[i];
    }
    return ans;
}

template <typename T>
T solve(T* arr, int s, int k) {
    T minSum = 100000000;

    for (int i = 0; i < s - k + 1; ++i) {
        T currSum = sum(arr, i, i + k);
        if (currSum < minSum) {
            minSum = currSum;
        }
    }
    return minSum;
}

int equalDominoes(int** ar, int p) {
    int countEqual = 0;
    for (int i = 0; i < p; ++i) {
        for (int j = i + 1; j < p; ++j) {
            if (ar[i][0] + ar[i][1] == ar[j][0] + ar[j][1]) countEqual++;
        }
    }
    return countEqual;
}

int main() {
//task 3
    int n, m;
    std::cout << "Input matrix size NxM: " << std::endl;
    std::cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    fillMatrix(matrix, n, m);
    printMatrix(matrix, n, m);

    std::cout << sumDiagonal(matrix, n, m) << std::endl;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    //task 4
    int s, k;
    std::cout << "Input size:" << std::endl;
    std::cin >> s;
    int* arr = new int[s];
    fillArrayKB(arr, s);
    printArray(arr, s);
    std::cout << "Input k:" << std::endl;
    std::cin >> k;

    double ans = solve(arr, s, k);
    std::cout << ans / k << std::endl;

    delete[] arr;

    //task 5 (Leetcode)
    int p;
    std::cout << "Input number of dominoes:" << std::endl;
    std::cin >> p;
    int** ar = new int* [p];
    for (int i = 0; i < p; ++i) {
        ar[i] = new int[2];
        std::cout << "Input domino " << i + 1 << std::endl;
        std::cin >> ar[i][0] >> ar[i][1];
    }

    int anss = equalDominoes(ar, p);
    std::cout << anss << std::endl;

    for (int i = 0; i < p; ++i) {
        delete[] ar[i];
    }
    delete[] ar;

}

