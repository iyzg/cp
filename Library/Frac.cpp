struct Frac {
	ll A, B;
    Frac(ll X, ll Y) {
        A = X; B = Y;
    }
    Frac() {
        A = 0; B=1;
    }
	Frac operator+(const Frac& F) {
		ll num = add(mul(A, F.B), mul(B, F.A));
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}
 
	Frac operator-(const Frac& F) {
		ll num = sub(mul(A, F.B), mul(B, F.A));
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}
 
	Frac operator*(const Frac& F) {
		ll num = mul(A, F.A);
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}
 
	Frac operator/(const Frac& F) {
		ll num = mul(A, F.B);
		ll den = mul(B, F.A);
		Frac res(num, den);
		return res;
	}
 
	Frac& operator+=(const Frac& F) { return *this = (*this) + F; }
	Frac& operator-=(const Frac& F) { return *this = (*this) - F; }
	Frac& operator*=(const Frac& F) { return *this = (*this) * F; }
	Frac& operator/=(const Frac& F) { return *this = (*this) / F; }
};
