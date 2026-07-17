#include <iostream>

using namespace std;

//mergesort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main(){
    int n;

    cin >> n;

    int arr[n - 1];

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    mergesort(arr, 0, n - 2);

    //finding the missing number
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}