#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& vec, int n) {
    for (int i = 1; i < n; i++) {
        int temp = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > temp) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = temp;
    }
}
void print(vector<int>vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
pair<int,int> threeWayPartition(vector<int>& vec, int start, int end) {
    int pivot = vec[end];
    int lt = start, gt = end;
    int cr = start;
    while (cr <= gt) {
        if (vec[cr] < pivot) {
            swap(vec[cr], vec[lt]);
            lt++;
            cr++;
        }
        else if (vec[cr] > pivot) {
            swap(vec[cr], vec[gt]);
            gt--;
        }
        else {
            cr++;
        }
    }
    return { lt, gt };
}
void threeWayQuickSort(vector<int>& vec, int start, int end) {
    if (start < end) {
        auto pi = threeWayPartition(vec, start, end);
        threeWayQuickSort(vec, start, pi.first - 1);
        threeWayQuickSort(vec, pi.second + 1, end);
    }
}

int main()
{
    int n = 10;
    vector<int>arr = { 3,2,1,5,2,3,4,4,1,1 };
    vector<int>arr1 = arr;
    insertionSort(arr1, n);
    print(arr1);

    vector<int>arr2 = arr;
    threeWayQuickSort(arr2, 0, n - 1);
    print(arr2);

    return 0;
}
