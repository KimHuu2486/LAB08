#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
pair<int, int> threeWayPartition(vector<int>& vec, int start, int end, vector<int>& idx) {
    int pivot = vec[idx[end]];
    int lt = start, gt = end;
    int cr = start;
    while (cr <= gt) {
        if (vec[idx[cr]] < pivot) {
            swap(idx[cr], idx[lt]);
            lt++;
            cr++;
        }
        else if (vec[idx[cr]] > pivot) {
            swap(idx[cr], idx[gt]);
            gt--;
        }
        else {
            cr++;
        }
    }
    return { lt, gt };
}
void threeWayQuickSort(vector<int>& vec, int start, int end, vector<int>& idx) {
    if (start < end) {
        auto pi = threeWayPartition(vec, start, end, idx);
        threeWayQuickSort(vec, start, pi.first - 1, idx);
        threeWayQuickSort(vec, pi.second + 1, end, idx);
    }
}

void print(vector<int>vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int>a = { 64, 12, 25, 22, 11 };

    vector<int>idxA(a.size());
    for (int i = 0; i < idxA.size(); i++) {
        idxA[i] = i;
    }
    threeWayQuickSort(a, 0, a.size() - 1, idxA);

    print(idxA);
    return 0;
}
