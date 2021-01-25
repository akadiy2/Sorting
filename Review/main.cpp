//
//  main.cpp
//  Review
//
//  Created by Abhiram Kadiyala on 1/22/21.
//

#include <iostream>
using namespace std; // this line is to indicate that the namespace library is being imported so that we can use std (instead of having to use std::cout - similar to including the imports in java ( ex: List<Integer> list = new java.util.ArrayList<Integer>(); )
/*
 This is the main method of a C++ program
 */

const int ARRAY_SIZE = 20;

void bubblesort(int arr[]);
void quicksort(int arr[], int low, int high);
void insertionsort(int arr[]);
void mergesort(int arr[]);
void mergesort(int arr[], int l, int h);
void merge(int arr[], int l, int m, int h);
int max(int arr[]);
int min(int arr[]);
void swap(int *i, int *j);
int partition(int arr[], int l, int h);

int main(int argc, const char * argv[]) {
    int a, b, c;
    
    a = 10;
    b = 20;
    c = 30;
    
    //int * pointer;
    
    
    //    pointer = &a;
    //
    //    cout<<a<<endl;
    //
    //    cout<<b<<endl;
    //
    //    *pointer = 15;
    //
    //    pointer = &b;
    //
    //    *pointer = 90;
    //
    //    cout<<a<<endl;
    //
    //    cout<<b<<endl;
    
    int arr[ARRAY_SIZE];
    
    int *ptr;
    
    /*ptr = arr;
     *ptr = 10;
     
     ptr = &arr[1];
     *ptr = 43;
     
     ptr = &arr[2];
     *ptr = 12;
     ptr = &arr[3];
     *ptr = 250;
     ptr = &arr[4];
     *ptr = 21;
     ptr = arr + 4;
     *ptr = 65;*/
    
    cout << endl;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        *ptr = rand() % 100 + 1;
    }
    
    cout<<"Array" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    bubblesort(arr);
    cout<<"Array After Bubblesort:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        *ptr = rand() % 100 + 1;
    }
    
    cout<<"Array before quicksort" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    quicksort(arr, 0, ARRAY_SIZE - 1);
    cout<<"Array After quicksort:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        *ptr = rand() % 100 + 1;
    }
    
    
    cout<<"Array before insertionsort" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    insertionsort(arr);
    cout<<"Array After insertionsort:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        *ptr = rand() % 100 + 1;
    }
    
    
    cout<<"Array before MergeSort" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    mergesort(arr);
    cout<<"Array After MergeSort:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        cout << *ptr << " ";
    }
    
    cout << endl;
    
    cout<<"The min element in this array is : " << min(arr) << endl;
    
    // insert code here...
    return 0;
}

void bubblesort(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

void insertionsort(int arr[]) {
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}

int partition(int arr[], int l, int h) {
    // set the pivot at the right most element
    int * pivot = arr + h;
    
    // set the left pointer to before the array starts
    int i = l - 1; // NEGATIVE INFINITY
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= *pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[h]);
    return i + 1;
    
}

void swap(int *a, int *b) {
    int *temp = b;
    *b = *a;
    *a = *temp;
}

int max(int arr[]) {
    int * ptr = arr;
    int max = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr = arr + i;
        if (*ptr > max) {
            max = *ptr;
        }
    }
    
    return max;
}

// for each number in the array if the number is less than the min than set the pointer to the number return the min
int min(int arr[]) {
    int min = 700;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int * ptr = arr + i;
        if (*ptr < min) {
            min = *ptr;
        }
    }
    
    return min;
}

void mergesort(int arr[]) {
    mergesort(arr, 0, ARRAY_SIZE - 1);
}


void mergesort(int arr[], int l, int h) {
    if (l < h) {
        int middle = (l + h) / 2;
        mergesort(arr, l, middle);
        mergesort(arr, middle + 1, h);
        merge(arr, l, middle, h);
    }
}

void merge(int arr[], int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;
    int left[n1];
    int right[n2];
    
    
    for (int i = 0; i < n1; i++) {
        left[i] = arr[i];
    }
    
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }
    
    int i = 0, j = 0, k = 1;
    
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        
        k++;
    }
    
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}


