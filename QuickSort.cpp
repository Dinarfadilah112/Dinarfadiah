#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> quickSort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    int pivot = arr[0];
    vector<int> less, greater;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] <= pivot)
            less.push_back(arr[i]);
        else
            greater.push_back(arr[i]);
    }

    vector<int> sorted;
    auto left = quickSort(less);
    auto right = quickSort(greater);
    sorted.insert(sorted.end(), left.begin(), left.end());
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), right.begin(), right.end());

    return sorted;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    auto sorted = quickSort(arr);

    for (int num : sorted) cout << num << " ";
    return 0;
}
