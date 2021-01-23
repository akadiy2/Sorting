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
int max(int arr[]);
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



