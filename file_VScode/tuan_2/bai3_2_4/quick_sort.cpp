#include <iostream>

#include <vector>

using namespace std;


// Hàm Partition: Đưa pivot về vị trí đúng và sắp xếp các phần tử

int partitionFunc(vector<int>& arr, int low, int high) {

    int pivot = arr[high]; // Chọn pivot là phần tử cuối

    int i = low - 1;       // Chỉ số nhỏ hơn pivot


    for(int j = low; j < high; j++) {

        if(arr[j] <= pivot) {

            i++;

            // Hoán đổi arr[i] và arr[j]

            int temp = arr[i];

            arr[i] = arr[j];

            arr[j] = temp;

        }

    }

    // Hoán đổi pivot với arr[i+1] để đưa pivot vào vị trí đúng

    int temp = arr[i+1];

    arr[i+1] = arr[high];

    arr[high] = temp;


    return i+1; // Vị trí của pivot

}


// Hàm Quick Sort

void quickSort(vector<int>& arr, int low, int high) {

    if(low < high) {

        // Tìm vị trí pivot

        int p = partitionFunc(arr, low, high);

        // Gọi đệ quy Quick Sort cho hai phần bên trái và bên phải của pivot

        quickSort(arr, low, p - 1);

        quickSort(arr, p + 1, high);

    }

}


int main(){

    vector<int> arr = {5, 2, 9, 1, 5, 6};

    quickSort(arr, 0, arr.size()-1);

    cout << "Kết quả Quick Sort: ";

    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;

}