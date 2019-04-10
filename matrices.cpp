#include <bits/stdc++.h>

using namespace std;

typedef vector <vector <int> > Matriz;

const int MX = 1000;

int mult(Matriz &m1, Matriz &m2, Matriz &answer){
	if (m1.size() == 0 or m2.size() != m1[0].size()) return 0;
	answer.assign(m1.size(), vector<int>(m2[0].size()));
	for(int i = 0; i < m1.size(); i++)
		for(int j = 0; j < m2[i].size(); j++)
			for(int k = 0; k < m2.size(); k++)
				answer[i][j] += m1[i][k] * m2[k][j];
	return 1;
}

void show(Matriz &m){
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void read(Matriz &m, int n) {
	int row = n, col = n;
	// cin >> row >> col;
	m.assign(row, vector<int>(col));
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			m[i][j] = rand() % MX;
}

int main() {
	clock_t beginnig_time = clock();
	srand(time(0));
	int n; cin >> n;
	Matriz m1;
	Matriz m2;
	Matriz answer;
	read(m1, n);
	read(m2, n);
	int state = mult(m1, m2, answer);
	/*if (state) show(answer);
	else cout << "Hubo problemas al operar con la matriz" << endl;*/
	clock_t end_time = clock();
	cout << n << ": " << fixed << setprecision(6) << (end_time - beginnig_time) * 1.0 / CLOCKS_PER_SEC << endl;
	return 0;
}

/*

condicion col de m1 = fila de m2
row x col
3 x 2 
2 x 3

tamaño nueva matriz
fila de m1 x col de m2

example
2 2
2 3
2 1
2 3
3 2 1
1 2 3

answer
9 10 11 
7 6 5 

*/