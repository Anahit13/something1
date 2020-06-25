#include <algorithm>
#include <cassert>
#include <iostream>
#include<iomanip>

#include "Merge.h"

void generateGraph(int*, int);

void PrintMat(int[20][20], int);

bool graph_checker(int*, int, int);

bool check_for_graph(int* p, int n)
{
    std::sort(p, p + n, std::greater<int>());
    return graph_checker(p, n, 0);
}

int main()
{
    int n;
    int o[10];
    do {
        std::cout << "Input a positive integer for array size: ";
        std::cin >> n;
    } while (n < 2);

    int* p = new int[n];

    int s = 0;
    do {
        std::cout << "Input " << n << " numbers with even sum:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            while (p[i] <= 0 || p[i] >= n)
            {
                std::cout << "Input number within the range [1; " << n - 1 << "]: ";
                std::cin >> p[i];
            } 
            s += p[i];
        }
    } while (s % 2 != 0);

    for (int i = 0; i < n; ++i)
        o[i] = p[i];

    std::cout << "\nThe numbers";
    if (!check_for_graph(p, n)) {
        std::cout << " do not";
    }
    std::cout << " make up a valid graph." << std::endl;
    generateGraph(o, n);
 
    delete[] p;

    return 0;
}

bool graph_checker(int* p, int n, int start)
{
    assert(p);
    assert(start < n - 1);
    assert(p[start] < n);

    if (p[start] > n - start - 1) {
        return false;
    }

    assert(start < n);

    bool is_zero = true;
    for (int i = 0; i < p[start]; ++i) {
        const int index = start + i + 1;
        --p[index];
        if (p[index] < 0) {
            return false;
        }
        if (p[index] != 0) {
            is_zero = false;
        }

    }
    if (is_zero) {
        int i = start + p[start];
        for (; i < n; ++i) {
            if (p[i] != 0) {
                break;
            }
        }
        if (i == n) {
            return true;
        }
    }

    merge(p, start + 1, start + p[start], n - 1);

    return graph_checker(p, n, start + 1);
}

// A function to print the adjacency matrix.
void PrintMat(int mat[][20], int n)
{
    int i, j;

    std::cout << "\n\n" << std::setw(3) << "       ";
    for (i = 0; i < n; i++)
        std::cout << std::setw(3) << "(" << i + 1 << ")";
    std::cout << "\n\n";

    // Print 1 if the corresponding vertexes are connected otherwise 0.
    for (i = 0; i < n; i++)
    {
        std::cout << std::setw(4) << "(" << i + 1 << ")";
        for (j = 0; j < n; j++)
        {
            std::cout << std::setw(5) << mat[i][j];
        }
        std::cout << "\n\n";
    }
}

void generateGraph(int* p, int n)
{
    int  AdjMat[20][20] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j <n; j++)
        {
            // For each pair of vertex decrement the degree of both vertex.
            if (p[i] > 0 && p[j] > 0)
            {
                std::cout << p[i] << " " << p[j] << std::endl;
                p[i]--;
                p[j]--;
                AdjMat[i][j] = 1;
                AdjMat[j][i] = 1;
            }
        }
        
    }
    PrintMat(AdjMat, n);
}

