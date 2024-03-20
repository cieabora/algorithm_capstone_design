#include <iostream>
#include <algorithm>
using namespace std;

int a[10][10] = { 0 };
int b[10][10] = { 0 };

int n;

int search() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 + i; j++) {
			if (a[i][j] != b[i][j])cnt++;
		}
	}
	return cnt;
}

void rotate() {
	int blank[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 + i; j++) {
			blank[i][j] = a[i][j];
		}
	}

	for (int t = 0; t < (n - 1) / 3 + 1; t++) {
		for (int i = 2 * t; i < n - t; i++) {
			a[i][i - t] = blank[abs(n + t - 1 - i)][t];
		}
		for (int i = t; i < n - t * 2; i++) {
			a[n - t - 1][i] = blank[n - t - 1 - i + t][abs(n - 1 - t - i)];
		}
		for (int i = t * 2; i < n - t; i++) {
			a[i][t] = blank[n - 1 - t][i - t];
		}
	}

}

void flip() {
	int blank[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 + i; j++) {
			blank[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 + i; j++) {
			a[i][j] = blank[i][abs(i - j)];
		}
	}
}

int main() {
	cin >> n;
	int x, y, z, r, w, d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> b[i][j];
		}
	}

	x = search();
	rotate();
	y = search();
	rotate();
	z = search();
	rotate();
	flip();
	r = search();
	rotate();
	w = search();
	rotate();
	d = search();
	cout << min({ x, y, z, r, w, d });
}
