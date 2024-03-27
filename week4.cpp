#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
int limit;

void heapify(int* arr, int k, int n) {
	int left = 2 * k;
	int right = 2 * k + 1;
	int smaller;
	if (right <= n) {
		if (arr[left] < arr[right]) {
			smaller = left;
		}
		else smaller = right;
	}
	else if (left <= n) smaller = left;
	else return;

	if (arr[smaller] < arr[k]) {
		int tmp = arr[smaller];
		arr[smaller] = arr[k];
		arr[k] = tmp;
		cnt++;
		if (cnt == limit) {
			cout << min(arr[smaller], arr[k]) << " " << max(arr[smaller], arr[k]) << endl;
			for (int i = 1; i <= n; i++) {
				cout << arr[i] << " ";
			}
			delete[] arr;
			exit(0);
		}
		heapify(arr, smaller, n);
	}
}

void build_min_heap(int* arr, int n) {
	for (int i = n / 2; i >= 1; i--) {
		heapify(arr, i, n);
	}
}

void heap_sort(int* arr, int n) {
	build_min_heap(arr, n);
	for (int i = n; i >= 2; i--) {
		int tmp = arr[i];
		arr[i] = arr[1];
		arr[1] = tmp;
		cnt++;
		if (cnt == limit) {
			cout << min(arr[i], arr[1]) << " " << max(arr[i], arr[1]) << endl;
			for (int j = 1; j <= n; j++) {
				cout << arr[j] << " ";
			}
			delete[] arr;
			exit(0);
		}
		heapify(arr, 1, i - 1);
	}
}


int main() {
	int n;
	cin >> n >> limit;

	int* arr = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	heap_sort(arr, n);
	delete[] arr;
	cout << -1;
}
