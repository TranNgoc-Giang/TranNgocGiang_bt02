#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm median_of_three: Tìm giá trị trung vị của ba giá trị (đầu, giữa, cuối)
int median_of_three(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    return mid;
}

// Hàm partition tiêu chuẩn
int partitionFunc(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot là phần tử cuối cùng
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Nếu phần tử nhỏ hơn pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1;
}

// Hàm partition với median-of-three
int partition_median(vector<int>& arr, int low, int high) {
    int median = median_of_three(arr, low, high);
    swap(arr[median], arr[high]); // Đưa pivot (median) về cuối
    return partitionFunc(arr, low, high); // Thực hiện phân hoạch
}

// Hàm Quick Sort với median-of-three
void quick_sort_median(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition_median(arr, low, high); // Phân hoạch
        quick_sort_median(arr, low, p - 1); // Đệ quy sắp xếp bên trái
        quick_sort_median(arr, p + 1, high); // Đệ quy sắp xếp bên phải
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

    quick_sort_median(arr, 0, arr.size() - 1);

    cout << "Mảng sau khi sắp xếp: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
