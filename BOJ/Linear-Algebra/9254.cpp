#include <iostream>
#include <vector>
using namespace std;
int n;
struct Matrix {
	vector<vector<double>> v;
	int N;
	Matrix(int n) : N(n) {
		v.resize(N, vector<double>(N, 0));
	}
	~Matrix() {
		for (int i = 0; i < N; i++)
			v[i].clear();
		v.clear();
	}
	Matrix identity(int n) {
		Matrix ret = Matrix(n);
		for (int i = 0; i < n; i++)
			ret.v[i][i] = 1;
		return ret;
	}
	void swapRow(int i, int j) {
		if (i == j) return;
		for (int k = 0; k < N; k++)
			swap(v[i][k], v[j][k]);
	}
	double *operator[](int i) { return &v[i][0]; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	Matrix a(n), b(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	b = b.identity(n);
	for (int k = 0; k < n; k++) {
		int t = k - 1;
		while (t + 1 < n && !a[++t][k]);
		if (t == n - 1 && !a[t][k]) {
			cout << "no inverse" << '\n';
			return 0;
		}
		a.swapRow(k, t), b.swapRow(k, t);
		double d = a[k][k];

		for (int j = 0; j < n; j++)
			a[k][j] /= d, b[k][j] /= d;

		for (int i = 0; i<n; i++)
			if (i != k) {
				double m = a[i][k];
				for (int j = 0; j < n; j++) {
					if (j >= k) a[i][j] -= a[k][j] * m;
					b[i][j] -= b[k][j] * m;
				}
			}
	}
	cout.precision(8);
	for (int i = 0; i < n; i++, cout << '\n')
		for (int j = 0; j < n; j++)
			cout << b[i][j] << ' ';

}