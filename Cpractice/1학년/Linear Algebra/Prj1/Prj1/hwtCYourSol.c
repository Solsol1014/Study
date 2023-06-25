#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "MATRIX_METHODS.h"


//��Ʈ�� ����� �ѹ�������
typedef struct tagBITMAPHEADER {
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	RGBQUAD hRGB[256]; //�� �ڵ忡���� �ʿ���� (8bit���� �ʿ�)
}BITMAPHEADER;

//��Ʈ���� �о�ͼ� ȭ�������� �����͸� ����
BYTE* loadBitmapFile(int bytesPerPixel, BITMAPHEADER* bitmapHeader, int* imgWidth, int* imgHeight, char* filename);

//��Ʈ�� ���� ����
void writeBitmapFile(int bytesPerPixel, BITMAPHEADER outputHeader, BYTE* output, int imgSize, char* filename);

int main() {
	/*******************************************************************/
	/*************************** Read image  ***************************/
	/*******************************************************************/
	BITMAPHEADER originalHeader;	//��Ʈ���� ����κ��� ���Ͽ��� �о� ������ ����ü
	BITMAPHEADER outputHeader;		//������ ���� ����κ��� ������ ����ü
	int imgSize, imgWidth, imgHeight;					//�̹����� ũ�⸦ ������ ����
	int bytesPerPixel = 3;			//number of bytes per pixel (1 byte for R,G,B respectively)

	BYTE* image = loadBitmapFile(bytesPerPixel, &originalHeader, &imgWidth, &imgHeight, "image_lena_24bit.bmp"); //��Ʈ�������� �о� ȭ�������� ���� (�ҷ����̴� �̹����� .c�� ���� ������ ����)
	if (image == NULL) return 0;

	imgSize = imgWidth * imgHeight; // total number of pixels
	BYTE* output = (BYTE*)malloc(bytesPerPixel * sizeof(BYTE) * imgSize);				//������� ������ ������ ���� �� �޸� �Ҵ�
	outputHeader = originalHeader;										//��������� ������������ �Ҵ�





	/*******************************************************************/
	/************************ Perform HWT/IHWT *************************/
	/*******************************************************************/
	//�̹��� ��� A ���� (RGB���� �����Ƿ� �ȼ��� �� �ϳ����� �о imgWidth x imgHeight ��� ����)
	int** A; //original image matrix
	A = (int**)malloc(sizeof(int*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		A[i] = (int*)malloc(sizeof(int) * imgWidth);
	}

	for (int i = 0; i < imgHeight; i++)
		for (int j = 0; j < imgWidth; j++)
			A[i][j] = image[(i * imgWidth + j) * bytesPerPixel];

	//Haar matrix H ���� (orthonormal column�� ������ ����)
	int n = imgHeight; //�̹����� ���簢��(Height==Width)�̶�� ����; n = 2^t,t=0,1,2,...
	//...
	double** Hn = constructHaarMatrixRecursive(n);
	
	double** H;
	H = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		H[i] = (double*)malloc(sizeof(double) * imgWidth);
	}
	H = normalizeVector(Hn, n);
	printf("1");
	//printMatrix(H, n, n, "H");

	double** Ht;
	Ht = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		Ht[i] = (double*)malloc(sizeof(double) * imgWidth);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			Ht[j][i] = H[i][j];
	}

	printf("1");

	//printMatrix(Ht, n, n, "Ht");

	//HWT ����: ��İ� B = H'*A*H
	//...
	double** B;
	B = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		B[i] = (double*)malloc(sizeof(double) * imgWidth);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				B[i][j] = Ht[i][k] * A[k][j];
			}
		}
	}

	//printMatrix(B, n, n, "B");
	for (int i = 0; i < imgHeight; i++)
		free(A[i]);
	free(A);

	double** HWT;
	HWT = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		HWT[i] = (double*)malloc(sizeof(double) * imgWidth);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				HWT[i][j] = B[i][k] * H[k][j];
			}
		}
	}
	//printMatrix(HWT, n, n, "HWT");
	for (int i = 0; i < imgHeight; i++)
		free(B[i]);
	free(B);

	//��� B �ڸ���: B�� upper left corner(subsquare matrix)�� �߶� Bhat�� ����
	//Bhat�� B�� ����� ������ B���� �߶� ������ �κ� �ܿ��� ��� 0���� ä����
	//...
	int k = 128;

	//scanf("%d", &k);

	double** HWThat;
	HWThat = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		HWThat[i] = (double*)malloc(sizeof(double) * imgWidth);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n && j < n)
				HWThat[i][j] = HWT[i][j];
			else
				HWThat[i][j] = 0;
		}
	}

	//printMatrix(HWThat, n, n, "HWThat");
	//IHWT ����: Ahat = H*Bhat*H'
	//...

	double** C;
	C = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		C[i] = (double*)malloc(sizeof(double) * imgWidth);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				C[i][j] = H[i][k] * HWThat[k][j];
			}
		}
	}
	
	double** Ahat;
	Ahat = (double**)malloc(sizeof(double*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		Ahat[i] = (double*)malloc(sizeof(double) * imgWidth);
	}

	printf("1");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				Ahat[i][j] = C[i][k] * Ht[k][j];
			}
		}
	}
	printMatrix(Ahat, n, n, "Ahat");



	/*******************************************************************/
	/******************* Write reconstructed image  ********************/
	/*******************************************************************/
	//Ahat�� �̿��ؼ� ���� image�� ���� ������ �ǵ��� ���� (��, Ahat = [a b;c d]�� [a a a b b b c c c d d d]�� ������ ��)
	BYTE* Are = (BYTE*)malloc(bytesPerPixel * sizeof(BYTE) * imgSize);
	//...
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Are[(i * n + j) * 3] = Ahat[i][j];
			Are[(i * n + j) * 3 + 1] = Ahat[i][j];
			Are[(i * n + j) * 3 + 2] = Ahat[i][j];
		}
	}

	writeBitmapFile(bytesPerPixel, outputHeader, Are, imgSize, "output1.bmp");


	free(image);
	free(output);
	free(Are);
	releaseMemory(H, n);
	for (int i = 0; i < imgHeight; i++)
		free(C[i]);
	free(C);
	for (int i = 0; i < imgHeight; i++)
		free(HWT[i]);
	free(HWT);
	for (int i = 0; i < imgHeight; i++)
		free(HWThat[i]);
	free(HWThat);
	for (int i = 0; i < imgHeight; i++)
		free(Ht[i]);
	free(Ht);

	return 0;
}

BYTE* loadBitmapFile(int bytesPerPixel, BITMAPHEADER* bitmapHeader, int* imgWidth, int* imgHeight, char* filename)
{
	FILE* fp = fopen(filename, "rb");	//������ �����б���� ����
	if (fp == NULL)
	{
		printf("���Ϸε��� �����߽��ϴ�.\n");	//fopen�� �����ϸ� NULL���� ����
		return NULL;
	}
	else
	{
		fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//��Ʈ��������� �б�
		fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//��Ʈ��������� �б�
		//fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//�����ȷ�Ʈ �б� (24bitmap ������ �������� ����)

		*imgWidth = bitmapHeader->bi.biWidth;
		*imgHeight = bitmapHeader->bi.biHeight;
		int imgSizeTemp = (*imgWidth) * (*imgHeight);	// �̹��� ����� ���� ������ �Ҵ�

		printf("Size of image: Width %d   Height %d\n", bitmapHeader->bi.biWidth, bitmapHeader->bi.biHeight);
		BYTE* image = (BYTE*)malloc(bytesPerPixel * sizeof(BYTE) * imgSizeTemp);	//�̹���ũ�⸸ŭ �޸��Ҵ�

		fread(image, bytesPerPixel * sizeof(BYTE), imgSizeTemp, fp);//�̹��� ũ�⸸ŭ ���Ͽ��� �о����

		fclose(fp);
		return image;
	}
}



void writeBitmapFile(int bytesPerPixel, BITMAPHEADER outputHeader, BYTE* output, int imgSize, char* filename)
{
	FILE* fp = fopen(filename, "wb");

	fwrite(&outputHeader.bf, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&outputHeader.bi, sizeof(BITMAPINFOHEADER), 1, fp);
	//fwrite(&outputHeader.hRGB, sizeof(RGBQUAD), 256, fp); //not needed for 24bitmap
	fwrite(output, bytesPerPixel * sizeof(BYTE), imgSize, fp);
	fclose(fp);
}
