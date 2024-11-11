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
	double** B;
	double** C;
	double** D; //2*2 1234
	double** E; //2*1 22
	double** M; //multiply
	double** ADD;
	double** v; //vector
	double** w;	//vector
	double x; //length
	int m = 5; 	//number of rows
	int n = 10;	//number of columns

	//Test transposeMatrix
	A = allocateMemory(m,n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = (double) i*j;
	printMatrix(A,m,n,"A");

	B = transposeMatrix(A,m,n);
	printMatrix(B,n,m,"B");

	//Test normalizeVector
	v = allocateMemory(m,1);
	for (int i = 0; i < m; i++)
		v[i][0] = i;
	w = normalizeVector(v,m);
	printMatrix(v,m,1,"v");
	printMatrix(w,m,1,"v_normalized");

	x = calculateLength(v, m);
	printf("\nLength: %lf\n", x);

	C = scaleMatrix(A, m, n, 3);
	printMatrix(C, m, n, "scale3A");

	D = allocateMemory(2, 2);
	D[0][0]=1;
	D[0][1]=2;
	D[1][0]=3;
	D[1][1]=4;

	E = allocateMemory(2, 1);
	E[0][0]=2;
	E[1][0]=2;

	M = multiplyTwoMatrices(D, 2, 2, E, 2, 1);
	printMatrix(M, 2, 1, "multiply");

	ADD = addTwoMatrices(D, 2, 2, D, 2, 2);
	printMatrix(ADD, 2, 2, "ADD");

	//release all the memory allocated
	releaseMemory(A, m);
	releaseMemory(B, n);
	releaseMemory(v, m);
	releaseMemory(w, m);
	releaseMemory(C, m);
	releaseMemory(D, 2);
	releaseMemory(E, 2);
	releaseMemory(M, 2);
	releaseMemory(ADD, 2);

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