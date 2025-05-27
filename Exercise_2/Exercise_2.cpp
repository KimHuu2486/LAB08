#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
pair<int, int> threeWayPartition(vector<int>& vec, int start, int end, vector<int>&idx) {
    int pivot = vec[end];
    int lt = start, gt = end;
    int cr = start;
    while (cr <= gt) {
        if (vec[cr] < pivot) {
            swap(vec[cr], vec[lt]);
            swap(idx[cr], idx[lt]);
            lt++;
            cr++;
        }
        else if (vec[cr] > pivot) {
            swap(vec[cr], vec[gt]);
            swap(idx[cr], idx[gt]);
            gt--;
        }
        else {
            cr++;
        }
    }
    return { lt, gt };
}
void threeWayQuickSort(vector<int>& vec, int start, int end, vector<int>&idx) {
    if (start < end) {
        auto pi = threeWayPartition(vec, start, end, idx);
        threeWayQuickSort(vec, start, pi.first - 1, idx);
        threeWayQuickSort(vec, pi.second + 1, end, idx);
    }
}

int binarySearch(vector<int>vec, int val) {
    int start = 0, end = vec.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid == val) {
            return mid;
        }
        else if (mid > val) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

pair<int, int> solve(vector<int>a, vector<int>idxA, vector<int>oriA, vector<int>b, vector<int>idxB, vector<int>oriB, int x) {
    pair<int, int>ans = { -1, -1 }; 
    int res = INT_MAX;
    for (int j = 0; j < a.size() && j < b.size(); j++) {
        int val = x - a[j];
        int i = binarySearch(b, val);
        if (i != -1 && i < a.size()) {
            int temp = oriA[idxB[i]] * oriB[idxA[j]];
            if (res > temp) {
                ans.first = idxB[i];
                ans.second = idxA[j];
                res = temp;
            }
        }
    }
    return ans;
}

void print(vector<int>vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int>a = { 0,3,1,6,2,5,4 };
    vector<int>oriA = a;
    vector<int>b = { 1,0,3,6,4,2,5 };
    vector<int>oriB = b;
    int x = 10;

    vector<int>idxA(a.size());
    for (int i = 0; i < idxA.size(); i++) {
        idxA[i] = i;
    }
    vector<int>idxB(b.size());
    for (int i = 0; i < idxB.size(); i++) {
        idxB[i] = i;
    }

    threeWayQuickSort(a, 0, a.size() - 1, idxA);
    threeWayQuickSort(b, 0, b.size() - 1, idxB);

    pair<int, int>ans = solve(a, idxA, oriA, b, idxB, oriB, x);
    if (ans.first != -1 && ans.second != -1) {
        cout << ans.first << " " << ans.second << endl;
    }
    else {
        cout << -1 << " " << -1 << endl;
    }
    return 0;
}
