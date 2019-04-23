#include <iostream>
#include "SortTestHelper.h"

using namespace std;




template <typename T>
void __merge(T arr[], int l,int mid,int r)
{
    T aux[r-l+1];
    for(int i=l;i<=r;i++)
        aux[i-l] = arr[i];
    int i=l,j=mid+1;
    for(int k = l;k<=r;k++) {

        if (i>mid)
        {
            arr[k] = aux[j-l];
            j++;
        }
        else if (j>r)
        {
            arr[k] =aux[i-l];
            i++;
        }
        else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        }
        else {
            arr[k] = aux[j - l];
            j++;
        }
    }

}
template <typename T>
void __mergeSort(T arr[], int l,int r)
{
    if(l>=r){
        return ;
    }
//    if(r-l<=15)
//    {
//        insertionSort_v2(arr,l,r);
//
//        return;
//    }

    int mid = (l+r)/2;
    __mergeSort(arr, l,mid);
    __mergeSort(arr,mid+1,r);
    if(arr[mid] > arr[mid+1])

        __merge(arr, l, mid, r);


}

template <typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr,0,n-1);
}

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
void mergeSort_v1(T arr[], int n)
{
  for(int sz=1;sz<=n;sz+=sz)

    for(int i=0;i+sz<n;i+=sz+sz)

        __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));



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
void insertionSort_v2(T arr[], int l,int r)
{
    for(int i=1;i<=r;i++)
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

template <typename T>
int  __partition(T arr[],int  l ,int r)
{
   // T v = arr[l];
    swap(arr[l] , arr[rand()%(r-l+1) + l]);
    T v = arr[l];

    int j=l;

    for(int i=l+1;i<=r;i++)
    {
        if(arr[i] < v)
        {
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if(l >= r)
        return ;
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr,p+1, r);

}

template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}

template <typename T>
void __quick_three_ways(T arr[], int l, int r)
{
    if(l>=r)
        return ;
    swap(arr[l] , arr[rand()%(r-l+1) + l]);
    T v = arr[l];
    int lt = l;
    int gt = r+1;
    int i = l+1;
    while(i<gt)
    {
        if(arr[i] < v)
        {
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        }
        else if(arr[i] >v)
        {
            swap(arr[gt-1],arr[i]);
            gt--;
        }
        else
            i++;


    }
    swap(arr[l] , arr[lt]);
    __quick_three_ways(arr, l , lt-1);
    __quick_three_ways(arr, gt, r);

}
template <typename T>
void quick_three_ways(T arr[], int n)
{
    srand(time(NULL));
    __quick_three_ways(arr,0,n-1);
}



int main() {

    // 测试排序算法辅助函数
    int N = 1000;
  // int *arr = SortTestHelper::generateRandomArray(N,0,1000);
    int *arr4 = SortTestHelper::generateNearlyOrderedArray(1000,10);
   int *arr2 = SortTestHelper::copyIntArray(arr4,1000);
//    int *arr3 = SortTestHelper::copyIntArray(arr,1000);
//    int *arr5 = SortTestHelper::copyIntArray(arr,1000);
//    int *arr6 = SortTestHelper::copyIntArray(arr,1000);
//    selectionSort(arr,N);
//    SortTestHelper::printArray(arr,N);

//    SortTestHelper::testSort("Selection Sort: ",selectionSort,arr,N);
//    SortTestHelper::testSort("insert Sort: ",insertionSort,arr2,N);
//    SortTestHelper::testSort("insert Sort v1: ",insertionSort_v1,arr3,N);
//    SortTestHelper::testSort("insert Sort v1: ",insertionSort_v1,arr4,N);
    SortTestHelper::testSort("mergeSort: ",quick_three_ways,arr4,N);
    SortTestHelper::testSort("quickSort: ",quickSort,arr2,N);
//    SortTestHelper::testSort("bubble Sort: ",bubbleSort, arr5,N);
//    SortTestHelper::testSort("shell Sort Sort: ",shellSort_v1, arr6,N);
//
   // delete[] arr;
    delete[] arr2;
   // delete[] arr3;
    delete[] arr4;
   // delete[] arr5;
   // delete[] arr6;

    return 0;


}