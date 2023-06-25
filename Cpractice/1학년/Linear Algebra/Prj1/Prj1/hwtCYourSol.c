#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "MATRIX_METHODS.h"


//비트맵 헤더를 한묶음으로
typedef struct tagBITMAPHEADER {
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	RGBQUAD hRGB[256]; //이 코드에서는 필요없음 (8bit에만 필요)
}BITMAPHEADER;

//비트맵을 읽어와서 화소정보의 포인터를 리턴
BYTE* loadBitmapFile(int bytesPerPixel, BITMAPHEADER* bitmapHeader, int* imgWidth, int* imgHeight, char* filename);

//비트맵 파일 쓰기
void writeBitmapFile(int bytesPerPixel, BITMAPHEADER outputHeader, BYTE* output, int imgSize, char* filename);

int main() {
	/*******************************************************************/
	/*************************** Read image  ***************************/
	/*******************************************************************/
	BITMAPHEADER originalHeader;	//비트맵의 헤더부분을 파일에서 읽어 저장할 구조체
	BITMAPHEADER outputHeader;		//변형을 가한 헤더부분을 저장할 구조체
	int imgSize, imgWidth, imgHeight;					//이미지의 크기를 저장할 변수
	int bytesPerPixel = 3;			//number of bytes per pixel (1 byte for R,G,B respectively)

	BYTE* image = loadBitmapFile(bytesPerPixel, &originalHeader, &imgWidth, &imgHeight, "image_lena_24bit.bmp"); //비트맵파일을 읽어 화소정보를 저장 (불러들이는 이미지는 .c와 같은 폴더에 저장)
	if (image == NULL) return 0;

	imgSize = imgWidth * imgHeight; // total number of pixels
	BYTE* output = (BYTE*)malloc(bytesPerPixel * sizeof(BYTE) * imgSize);				//결과값을 저장할 포인터 선언 및 메모리 할당
	outputHeader = originalHeader;										//헤더정보를 출력헤더정보에 할당





	/*******************************************************************/
	/************************ Perform HWT/IHWT *************************/
	/*******************************************************************/
	//이미지 행렬 A 구성 (RGB값이 있으므로 픽셀당 값 하나씩만 읽어서 imgWidth x imgHeight 행렬 구성)
	int** A; //original image matrix
	A = (int**)malloc(sizeof(int*) * imgHeight);
	for (int i = 0; i < imgHeight; i++) {
		A[i] = (int*)malloc(sizeof(int) * imgWidth);
	}

	for (int i = 0; i < imgHeight; i++)
		for (int j = 0; j < imgWidth; j++)
			A[i][j] = image[(i * imgWidth + j) * bytesPerPixel];

	//Haar matrix H 구성 (orthonormal column을 갖도록 구성)
	int n = imgHeight; //이미지가 정사각형(Height==Width)이라고 가정; n = 2^t,t=0,1,2,...
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

	//HWT 수행: 행렬곱 B = H'*A*H
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

	//행렬 B 자르기: B의 upper left corner(subsquare matrix)를 잘라 Bhat에 저장
	//Bhat은 B와 사이즈가 같으며 B에서 잘라서 저장한 부분 외에는 모두 0으로 채워짐
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
	//IHWT 수행: Ahat = H*Bhat*H'
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
	//Ahat을 이용해서 위의 image와 같은 형식이 되도록 구성 (즉, Ahat = [a b;c d]면 [a a a b b b c c c d d d]를 만들어야 함)
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
	FILE* fp = fopen(filename, "rb");	//파일을 이진읽기모드로 열기
	if (fp == NULL)
	{
		printf("파일로딩에 실패했습니다.\n");	//fopen에 실패하면 NULL값을 리턴
		return NULL;
	}
	else
	{
		fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//비트맵파일헤더 읽기
		fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//비트맵인포헤더 읽기
		//fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//색상팔렛트 읽기 (24bitmap 에서는 존재하지 않음)

		*imgWidth = bitmapHeader->bi.biWidth;
		*imgHeight = bitmapHeader->bi.biHeight;
		int imgSizeTemp = (*imgWidth) * (*imgHeight);	// 이미지 사이즈를 상위 변수에 할당

		printf("Size of image: Width %d   Height %d\n", bitmapHeader->bi.biWidth, bitmapHeader->bi.biHeight);
		BYTE* image = (BYTE*)malloc(bytesPerPixel * sizeof(BYTE) * imgSizeTemp);	//이미지크기만큼 메모리할당

		fread(image, bytesPerPixel * sizeof(BYTE), imgSizeTemp, fp);//이미지 크기만큼 파일에서 읽어오기

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
