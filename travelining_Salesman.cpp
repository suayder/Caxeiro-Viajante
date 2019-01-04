#include <algorithm>
#include <iostream>
#include <math.h>
#include <string.h>
#define MAX 11

using namespace std;

int i, j, TC,  n, x[MAX], y[MAX], dist[MAX][MAX], memo[MAX][1 << MAX]; 
double a[MAX][MAX];

int calc_travelling(int pos, int bitmask) { // bitmask armazena as coordenadas já visitadas
	if (bitmask == (1 << (n + 1)) - 1)
		return dist[pos][0];
	if (memo[pos][bitmask] != -1)
		return memo[pos][bitmask];

	int ans = 2000000000;
	for (int nxt = 0; nxt <= n; nxt++) 
		if (nxt != pos && !(bitmask & (1 << nxt))) //Se a coordenada  não foi visitada ainda
			ans = min(ans, dist[pos][nxt] + calc_travelling(nxt, bitmask | (1 << nxt)));
	return memo[pos][bitmask] = ans;
}

int main() {
  	scanf("%d", &TC); //Total de cidades
	int temp = TC;
	int k = 0;
	 while (TC--) {
		scanf("%d %d %d",  &n, &x[k], &y[k]);
		 k++;
		for (i = 0; i <= n; i++) {// build distance table
			for (j = 0; j <= n; j++){
				dist[i][j] = sqrt(pow((x[i] - x[j]),2) + pow((y[i] - y[j]),2)); // Distância euclidiana
				a[i][j]  = sqrt(pow((x[i] - x[j]),2) + pow((y[i] - y[j]),2));
			}
	 	}
	 }
	 for (i = 0; i <= n; i++) {// build distance table
		puts("");
		for (j = 0; j <= n; j++){
			printf("%f ", a[i][j]);
		}
	}
	memset(memo, -1, sizeof (memo));
	printf("\n\nO tamanho do menor caminho é: %d\n", calc_travelling(0, 1)); 

  return 0;
}