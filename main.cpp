#include <bits/stdc++.h>

using namespace std;

struct zona
{
  int aparitii, valoare;
};

int main ()
{
  zona a[100];
  int mat[100][100];
  bool folosit[100][100];
  int M, N, i, j;
  cin >> M >> N;
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++)
      cin >> mat[i][j];
  int k = 0;
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++)
      {
	if (mat[i][j] != 0 && folosit[i][j] == false)
	  {
	    int ci, cj;
	    ci = i;
	    cj = j;
	    while (mat[ci][cj] == mat[i][j])
	      ci++;
	    ci--;
	    while (mat[ci][cj] == mat[i][j])
	      cj++;
	    cj--;
	    bool gasit = false;
	    for (int x = 0; x < k; x++)
	      {
		if (a[x].valoare == mat[i][j])
		  {
		    a[x].aparitii = a[x].aparitii + 1;
		    gasit = true;
		    break;
		  }
	      }
	    if (gasit == false)
	      {
		a[k++].valoare = mat[i][j];
		a[k - 1].aparitii = 1;
	      }
	    for (int x = i; x <= ci; x++)
	      for (int y = j; y <= cj; y++)
		folosit[x][y] = true;

	  }
      }
  int apmax = INT_MIN, nrmax;
  for (i = 0; i < k; i++)
    if (a[i].aparitii > apmax)
      {
	nrmax = a[i].valoare;
	apmax = a[i].aparitii;
      }
  cout << nrmax << " " << apmax;
}
