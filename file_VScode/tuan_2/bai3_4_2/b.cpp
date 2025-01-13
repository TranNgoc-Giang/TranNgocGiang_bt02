#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm merge để hợp nhất hai đoạn con
void merge(vector<int>& arr, int left, int mid, int right) {
    // Tạo hai mảng con từ mảng chính
    vector<int> left_part(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> right_part(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    // Trộn hai mảng con
    while (i < left_part.size() && j < right_part.size()) {
        if (left_part[i] <= right_part[j]) {
            arr[k++] = left_part[i++];
        } else {
            arr[k++] = right_part[j++];
        }
    }

    // Sao chép các phần tử còn lại từ mảng trái (nếu có)
    while (i < left_part.size()) {
        arr[k++] = left_part[i++];
    }

    // Sao chép các phần tử còn lại từ mảng phải (nếu có)
    while (j < right_part.size()) {
        arr[k++] = right_part[j++];
    }
}

// Hàm Bottom-Up Merge Sort
void bottomUpMergeSort(vector<int>& arr) {
    int n = arr.size();

    // Bắt đầu với kích thước đoạn con là 1 và tăng dần gấp đôi
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

// Hàm main để chạy thử
int main() {
    vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15, 2, 8, 10, 9};
    cout << "Mảng ban đầu: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    bottomUpMergeSort(arr);

    cout << "Mảng sau khi sắp xếp: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
