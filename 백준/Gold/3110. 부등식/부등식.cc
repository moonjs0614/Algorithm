#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll ans = 0;
	ll A1, A2, B, C, D, E1, E2; cin >> B >> C >> D >> A1 >> A2 >> E1 >> E2;
	if (A1 * E2 < A2 * E1) {
		ll iterL = (A1 * C) / A2, iterR = (E1 * C) / E2;
		if ((E1 * C) % E2) iterR++;
		for (ll x = iterL; x < iterR; x++) {
			ll L1 = (A1 * B) / A2, R1 = (x * B) / C;
			if ((x * B) % C) R1++;
			ll L2 = x * D / C, R2 = E1 * D / E2;
			if ((E1 * D) % E2) R2++;
			ans += max(0LL, (R1 - L1 - 1)) * max(0LL, (R2 - L2 - 1));
		}

		cout << ans;
	}
	else cout << 0;
}