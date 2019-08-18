#include <iostream>
using namespace std;

void Qsort(int arr[], int low, int high){
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        while (arr[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        while (arr[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}

int main()
{
	int N, arr[100000];
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	Qsort(arr, 0, N - 1);
	
	for(int i = 0; i < N; i++)
		cout << arr[i] << ' ';	
}
