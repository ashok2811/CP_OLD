#include<bits/stdc++.h>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long R, G, B;
	cin >> R >> G >> B;
	vector<long long> red(R), green(G), blue(B);
	for (long long i = 0; i < R; i++) {
		cin >> red[i];
	}
	for (long long i = 0; i < G; i++) {
		cin >> green[i];
	}

	for (long long i = 0; i < B; i++) {
		cin >> blue[i];
	}

	long long r = R - 1, g = G - 1, b = B - 1;
	long long area = 0;
	sort(red.begin(), red.end());
	sort(green.begin(), green.end());
	sort(blue.begin(), blue.end());

	while ((r >= 0 && b >= 0) || (r >= 0 && g >= 0) || (g >= 0 && b >= 0)) {
		long long r1, b1, g1;
		r1 = red[r];
		g1 = green[g];
		b1 = blue[b];

		long long minval = min(r1, min(g1, b1));
		if (minval == r1) {
			b--, g--;
			area += (long long)(g1 * b1);
		}
		else if (minval == g1) {
			r--, b--;
			area += (long long)(r1 * b1);
		}
		else {
			r--, g--;
			area += (long long)(r1 * g1);
		}
	}

	cout << area << '\n';

	return 0;
}