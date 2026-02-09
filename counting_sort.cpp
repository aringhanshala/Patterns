#include<iostream>
using namespace std;

void displayArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countingsort(int arr[], int n) {
   
    int m = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > m)
            m = arr[i];
    }
    int count[m + 1];
    for(int i = 0; i <= m; i++) {
        count[i] = 0;
    }

    // frequency count
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // sorting
    int j = 0;
    for(int i = 0; i <= m; i++) {
        while(count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;   
        }
    }
    //prefix sum
    for(int i = 1; i <= m; i++) {
        count[i] = count[i - 1];
    }
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        int index = count[arr[i]] - 1;
        index--;
        count[arr[i]]--;
        output[index] = arr[i];
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    displayArray(arr, n);

    countingsort(arr, n);

    cout << "Sorted array: ";
    displayArray(arr, n);

    return 0;
}