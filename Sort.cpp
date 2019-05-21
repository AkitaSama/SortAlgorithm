//
// Created by 20172 on 2019/5/21.
//

#include "Sort.h"

void Sort::BubbleSort(int *arr, int length)
{
    int i, j;
    int currentBorder = 0, sortBorder = length - 1;
    for (i = 0; i < length-1; ++i) {
        bool isSorted = true;
        for (j = 0; j < sortBorder; ++j) {
            if (arr[j]>arr[j+1]) {
                SwapVar(arr[j], arr[j+1]);
                isSorted = false;
                currentBorder = j;
            }
        }
        sortBorder = currentBorder;
        if(isSorted) {
            break;
        }
    }
}

void Sort::QuickSort(int *arr, int start, int end)
{
    if (start >= end) {
        return;
    }
    int pivot = Partition(arr, start, end);
    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

int Sort::Partition(int *arr, int left, int right)
{
    int pivot = arr[left];
    while (left < right){
        while (left <right && arr[right] >= pivot) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void Sort::SwapVar(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Sort::InsertSort(int *arr, int length)
{
    int i, j;
    for (i = 0; i < length; ++i) {
        int current = arr[i];
        for (j = i; j > 0 && arr[j-1] > current; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = current;
    }
}

void Sort::ShellSort(int *arr, int length)
{
    int i, j;
    int increment;
    for (increment = length/2; increment > 0; increment /= 2) {
        for (i = increment; i < length; ++i) {
            int current = arr[i];
            for (j = i; j > increment && arr[j-increment] >current; j -= increment) {
                arr[j] = arr[j - increment];
            }
            arr[j] = current;
        }
    }
}

void Sort::SelectionSort(int *arr, int length)
{
    int i, j;
    for (i = 0; i < length - 1; ++i) {
        int minIndex = i;
        for (j = i + 1; j < length; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        SwapVar(arr[i], arr[minIndex]);
    }
}

void Sort::HeapSort(int *arr, int length)
{

    for (int i = length / 2; i >= 0; --i) {
        AdjustHeap(arr, i, length);
    }
    for (int j = length - 1; j >0; --j) {
        SwapVar(arr[0], arr[j]);
        AdjustHeap(arr, 0, j);
    }
}

void Sort::AdjustHeap(int *arr, int i, int length)
{
    int Child;
    int current;
    for (current = arr[i]; LEFT_CHILD(i) < length; i = Child) {
        Child = LEFT_CHILD(i);
        if (Child != length - 1 && arr[Child+1] > arr[Child]) {
            Child++;
        }
        if (current < arr[Child]) {
            arr[i] = arr[Child];
        } else {
            break;
        }
    }
    arr[i] = current;
}

void Sort::MergeSort(int *arr, int start, int end)
{
    if (start < end) {
        int mid = start + (end - start)/2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
    }
}

void Sort::Merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L_Tmp[n1], R_Tmp[n2];
    for (i = 0; i < n1; ++i) {
        L_Tmp[i] = arr[left+i];
    }
    for (j = 0; j < n2; ++j) {
        R_Tmp[j] = arr[mid+1+j];
    }
    i=0;j=0;k=left;
    while (i < n1 && j < n2) {
        if (L_Tmp[i] <= R_Tmp[j]) {
            arr[k] = L_Tmp[i];
            i++;
        } else {
            arr[k] = R_Tmp[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L_Tmp[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R_Tmp[j];
        j++;
        k++;
    }
}

void Sort::CountingSort(int *arr, int length)
{
    int min = arr[0], max = arr[0];
    for (int i = 0; i < length; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int count[max-min+1];
    for (int i = 0; i < max-min+1; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < length; ++i) {
        count[arr[i]-min]++;
    }
    for (int i = 0, j = 0; i < max-min+1; ++i) {
        while (count[i] != 0) {
            arr[j++] = min + i;
            count[i]--;
        }
    }
}