#include <iostream>
#include "SortTestHelper.h"

using namespace std;
template <typename T>

void bubbleSort(T arr[], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
}

template <typename T>
void shellSort_v1(T arr[],int n)
{
    int gap = n/2;
    for(gap; gap>0;gap=gap/2)
        for(int i=gap;i<n;i++)
        {  int j=i;
            while(j-gap>=0 && arr[j]<arr[j-gap])
            {
                swap(arr[j],arr[j-gap]);
                j-=gap;
            }
}}


template <typename T>
void insertionSort_v1(T arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        T e = arr[i];
        int j;
        for(j=i;j>0 && arr[j-1]>e;j--)
            arr[j]  = arr[j-1];
        arr[j] = e;


    }
}


template <typename T>
void insertionSort(T arr[],int n){

    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            else
                break;
        }
    }


}

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

int main() {

    // 测试排序算法辅助函数
    int N = 1000;
    int *arr = SortTestHelper::generateRandomArray(N,0,1000);
    int *arr4 = SortTestHelper::generateNearlyOrderedArray(1000,10);
    int *arr2 = SortTestHelper::copyIntArray(arr,1000);
    int *arr3 = SortTestHelper::copyIntArray(arr,1000);
    int *arr5 = SortTestHelper::copyIntArray(arr,1000);
    int *arr6 = SortTestHelper::copyIntArray(arr,1000);
//    selectionSort(arr,N);
//    SortTestHelper::printArray(arr,N);

    SortTestHelper::testSort("Selection Sort: ",selectionSort,arr,N);
    SortTestHelper::testSort("insert Sort: ",insertionSort,arr2,N);
    SortTestHelper::testSort("insert Sort v1: ",insertionSort_v1,arr3,N);
    SortTestHelper::testSort("insert Sort v1: ",insertionSort_v1,arr4,N);
    SortTestHelper::testSort("bubble Sort: ",bubbleSort, arr5,N);
    SortTestHelper::testSort("shell Sort Sort: ",shellSort_v1, arr6,N);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    return 0;


}