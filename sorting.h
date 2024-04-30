#include <vector>

using namespace std;
//объявление функций сортировки и вспомогательных функций
void quicksort(vector<int> &v, int left, int right);
int partition(vector<int> &v, int left, int right);
void bubblesort(vector<int> v, int n);
void selectionsort(vector<int> v, int n);
void insertionsort(vector<int> v, int n);
void heapsort(vector<int> &v, int n);
void heapify(vector<int> &v, int n, int i);
