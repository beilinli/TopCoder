#define FOR(i, a, b) for (int i = a; i < b; i++)

const int MAXN = 50;

double comp[MAXN + 2];
double pow1000[10 * MAXN + 2];

class RandomGraph {
public:
	int p;

	double noComponent(int n) {
		if (n < 4 || p == 0) return 1.0;
		if (comp[n] >= 0) return comp[n];
	
		double &res = comp[n];
		res = 0.0;
		
		/* component of 1 */
		res += pow1000[n - 1] * noComponent(n - 1);
		
		/* component of size 2 */
		res += 1.0 * (n - 1) * pow1000[2 * n - 4] * p / 1000.0 * noComponent(n - 2);
		
		/* component of size 3 */
		double isComp = 3.0 * p * p * (1000.0 - p)/(1000.0 * 1000.0 * 1000.0) + 1.0 * p * p * p/(1000.0 * 1000.0 * 1000.0);
		res += (n - 1) * (n - 2)/2.0 * pow1000[3 * n - 9] * isComp * noComponent(n - 3);
		
		return comp[n];
	}

	double probability(int n, int p) {
		this -> p = p;
		pow1000[0] = 1.0;
		FOR (i, 1, 10 * MAXN + 2) pow1000[i] = pow1000[i - 1] * (1000 - p)/1000.0;
		FOR (i, 0, MAXN + 2) comp[i] = -1.0;
		
		return 1.0 - noComponent(n);
	}
};
