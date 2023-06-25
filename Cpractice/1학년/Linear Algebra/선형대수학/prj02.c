#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//functions for convenience
double** allocateMemory(int m, int n); 
void releaseMemory(double** A, int m);
void printMatrix(double** A, int m, int n, char name[]);

//functions to implement in prj0 
double** transposeMatrix(double** A, int m, int n);
double** normalizeVector(double** v, int n);
double calculateLength(double** v, int n);
double** scaleMatrix(double** A, int m, int n, int c);
double** multiplyTwoMatrices(double** A, int m, int n, double** B, int l, int k);
double** addTwoMatrices(double** A, int m, int n, double** B, int l, int k);

int main() {
    double** A;
    double** H;
    double** Ht1, Ht2, Ht;
    double** B;
    double** C;

    int n = 2;

    A = allocateMemory(n, n);
    H = allocateMemory(n, n);
    B = allocateMemory(n, n);
    C = allocateMemory(n, n;

    A[0][0]=1;
    A[0][1]=2;
    A[1][0]=3;
    A[1][1]=4;

    H[0][0]=1;
    H[0][1]=1;
    H[1][0]=1;
    H[1][1]=-1;

    

    return 0;
}

//functions for convenience
double** allocateMemory(int m, int n) {
	double** A;
	A = (double**) malloc(sizeof(double*) * m);
	for (int i = 0; i < m; i++) {
		A[i] = (double*) malloc(sizeof(double) * n);
	}
	return A;
}


void releaseMemory(double** A, int m) {
	for (int i = 0; i < m; i++)
		free(A[i]);
	free(A);
}

void printMatrix(double** A, int m, int n, char name[]) {
	printf("\n%s = \n", name);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%lf ", A[i][j]);
		printf("\n");
	}
}

//functions to implement in prj0 
double** transposeMatrix(double **A, int m, int n) {
	double** B = allocateMemory(n, m);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			B[j][i] = A[i][j];	
	
	return B;
}	

double** normalizeVector(double** v, int m) {
	double** w;
	double len = 0.0;

	for (int i = 0; i < m; i++)
		len += v[i][0]*v[i][0];	
	len = sqrt(len);

	w = allocateMemory(m,1);
	for (int i = 0; i < m; i++)
		w[i][0] = v[i][0]/len;
	
	return w;
}

double calculateLength(double** v, int n)
{
	double sum = 0;

	for (int i=0;i<n;i++)
		sum += v[i][0]*v[i][0];
	sum = sqrt(sum);

	return sum;
}

double** scaleMatrix(double** A, int m, int n, int c)
{
	double** B;

	B = allocateMemory(m, n);

	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			B[i][j]=c*A[i][j];
	}

	return B;
}

double** multiplyTwoMatrices(double** A, int m, int n, double** B, int l, int k)
{
	double** M;
	int sum;

	M = allocateMemory(m, k);

	for (int i=0;i<m;i++)
	{
		for (int y=0;y<k;y++)
		{
			sum=0;

			for (int j=0;j<n;j++)
				sum+=A[i][j]*B[j][y];

			M[i][y]=sum;
		}
	}

	return M;
}

double** addTwoMatrices(double** A, int m, int n, double** B, int l, int k)
{
	double** M;

	if (m!=l||n!=k)
		return NULL;
	
	M = allocateMemory(m, n);

	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			M[i][j]=A[i][j]+B[i][j];
	}

	return M;
}