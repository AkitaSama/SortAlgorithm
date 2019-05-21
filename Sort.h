//
// Created by 20172 on 2019/5/21.
//

#ifndef SORTALGORITHM_SORT_H
#define SORTALGORITHM_SORT_H

#define LEFT_CHILD(i) (2*(i)+1)

class Sort {
public:
    static void BubbleSort(int *arr, int length);
    static void QuickSort(int *arr, int start, int end);

    static void InsertSort(int *arr, int length);
    static void ShellSort(int *arr, int length);

    static void SelectionSort(int *arr, int length);
    static void HeapSort(int *arr, int length);

    static void MergeSort(int *arr, int start, int end);

    static void CountingSort(int *arr, int length);

private:
    static void SwapVar(int &a, int &b);
    static int Partition(int *arr, int left, int right);
    static void AdjustHeap(int *arr, int i, int length);
    static void Merge(int *arr, int left, int mid, int right);

};


#endif //SORTALGORITHM_SORT_H
