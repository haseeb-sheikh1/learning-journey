#include <iostream>
using namespace std;
//                                                    LINEAR SEARCH
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;    // element found
    }
    return -1;           // element not found
}

int main() {
    int arr[] = {12, 45, 23, 51, 19};
    int n = 5;
    int key = 23;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}