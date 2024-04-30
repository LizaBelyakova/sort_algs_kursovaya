#include "sorting.h"
#include <vector>
using namespace std;

int partition(vector<int> &v, int left, int right)
{
    int pivot = v[left];
    int count = 0;
    for (int i = left + 1; i <= right; i++) {
        if (v[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = left + count;
    swap(v[pivotIndex], v[left]);
    int i = left, j = right;

    while (i < pivotIndex && j > pivotIndex) {

        while (v[i] <= pivot) {
            i++;
        }

        while (v[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(v[i++], v[j--]);
        }
    }

    return pivotIndex;
}
void quicksort(vector<int> &v, int left, int right){
    if (left >= right)
        return;
    int p = partition(v, left, right);
    quicksort(v, left, p - 1);
    quicksort(v, p + 1, right);
}
void bubblesort(vector<int> v, int n){
    for(int i = 0; i<n;i++){
        for(int j = 0; j < n; j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
void selectionsort(vector<int> v, int n){
    for (int i = n; i >= 0; i--) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[max]) {
                max = j;
            }
        }
        swap(v[max],v[i]);
    }
}
void insertionsort(vector<int> v, int n){
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}
void heapify(vector<int> &v, int n, int i){
    // Find largest among root, left child and right child
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && v[l] > v[largest])
        largest = l;

    if (r < n && v[r] > v[largest])
        largest = r;
    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}
void heapsort(vector<int> &v, int n){
    for(int i = n/2-1; i>=0; i--)
        heapify(v, n,i);

    for (int i = n - 1; i >= 0; i--)
    {
        // перемещаем текущий корень в конец.
        swap(v[0], v[i]);
        // вызываем процедуру heapify уже на уменьшенной куче(просеиваем её).
        heapify(v, i, 0);
    }
}


