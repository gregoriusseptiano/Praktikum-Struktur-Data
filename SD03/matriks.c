/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124200026 / Gregorius Septiano Ariadi*/
/* Tanggal   : 18-09-2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"  

/* type Matriks = < cell: array[1…10] of array[1…10] of integer, 
				    nbaris: integer, 
					nkolom: integer > */
/* asumsi: indeks 0 tidak digunakan */
typedef	struct { int cell[11][11];
                 int nbaris;
				 int nkolom; } Matriks;

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    int i; 
    int j;
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    return (getNBaris(M) == 0 && getNKolom(M) == 0);
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return (getNBaris(M) == 10 && getNKolom(M) == 10);
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    if (!isFullMatriks(*M)){
        (*M).cell[row][col] = X;
        if (row > getNBaris(*M)) (*M).nbaris = row;
        if (col > getNKolom(*M)) (*M).nkolom = col;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X) {
     //Kamus Lokal
    int i, j;
    //Algoritma
    boolean found = false;
    for (i = 1; i <= getNBaris(*M) && !found; i++) {
        for (j = 1; j <= getNKolom(*M) && !found; j++) {
            if ((*M).cell[i][j] == X) {
                (*M).cell[i][j] = -999; 
                found = true;
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    //Kamus Lokal
    int i, j;
    //Algoritma
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            (*M).cell[i][j] = rand() % 100; //saya batasi 0..99 saja
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    int i; 
    int j;
    (*M).nbaris = n;
    (*M).nkolom = n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                (*M).cell[i][j] = 1;
            else
                (*M).cell[i][j] = 0;
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    int i;
    int j;
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    int i;
    int j;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            printf("%4d", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M) {
    int i;
    int j;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] != -999)
                printf("%4d", M.cell[i][j]);
            else
                printf("   -");
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    Matriks R;
    initMatriks(&R);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        R.nbaris = getNBaris(M1);
        R.nkolom = getNKolom(M1);
        int i;
        int j;
        for (i = 1; i <= R.nbaris; i++) {
            for (j = 1; j <= R.nkolom; j++) {
                R.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
    } else {
        printf("Ukuran matriks tidak sama\n");
    }   
    return R;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    Matriks R;
    initMatriks(&R);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        R.nbaris = getNBaris(M1);
        R.nkolom = getNKolom(M1);
        int i;
        int j;
        for (i = 1; i <= R.nbaris; i++) {
            for (j = 1; j <= R.nkolom; j++) {
                R.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
    } else {
        printf("Ukuran matriks tidak sama\n");
    }
    return R;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    Matriks R;
    initMatriks(&R);
    if (getNKolom(M1) == getNBaris(M2)) {
        R.nbaris = getNBaris(M1);
        R.nkolom = getNKolom(M2);
        int i;
        int j;
        int k;
        for (i = 1; i <= R.nbaris; i++) {
            for (j = 1; j <= R.nkolom; j++) {
                R.cell[i][j] = 0;
                for (k = 1; k <= M1.nkolom; k++) {
                    R.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                }
            }
        }
    } else {
        printf("ERROORRRR\n");
        R.nbaris = 0;
        R.nkolom = 0;
    }
    return R;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M, int x) {
    Matriks R;
    initMatriks(&R);
    R.nbaris = getNBaris(M);
    R.nkolom = getNKolom(M);
    int i;
    int j;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            R.cell[i][j] = M.cell[i][j] * x;
        }
    }
    return R;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    Matriks R;
    initMatriks(&R);
    R.nbaris = (*M).nkolom;
    R.nkolom = (*M).nbaris;

    int i, j;
    for (i = 1; i <= (*M).nbaris; i++) {
        for (j = 1; j <= (*M).nkolom; j++) {
            R.cell[j][i] = (*M).cell[i][j];
        }
    }
    *M = R; 
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    Matriks R;
    initMatriks(&R);
    R.nbaris = getNKolom(M);
    R.nkolom = getNBaris(M);
    int i;
    int j;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            R.cell[j][i] = M.cell[i][j];
        }
    }
    return R;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n) {
    Matriks R;
    initMatriks(&R);
    R.nbaris = getNBaris(M) + 2*n;
    R.nkolom = getNKolom(M) + 2*n;

    int i;
    int j;
    for (i = 1; i <= R.nbaris; i++) {
        for (j = 1; j <= R.nkolom; j++) {
            R.cell[i][j] = 0;
        }
    }

    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            R.cell[i+n][j+n] = M.cell[i][j];
        }
    }
    return R;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size) {
    Matriks R;
    initMatriks(&R);
    R.nbaris = getNBaris(M) / size;
    R.nkolom = getNKolom(M) / size;

    if (getNBaris(M) % size != 0 || getNKolom(M) % size != 0){
        printf("ERROR\n");
        R.nbaris = 0;
        R.nkolom = 0;
        return R;
    }

    int i, j, p, q;
    for (i = 1; i <= R.nbaris; i++) {
        for (j = 1; j <= R.nkolom; j++) {
            int startRow = (i - 1) * size + 1;
            int startCol = (j - 1) * size + 1;
            int max = M.cell[startRow][startCol];
            for (p = 0; p < size; p++) {
                for (q = 0; q < size; q++) {
                    if (M.cell[startRow + p][startCol + q] > max) {
                        max = M.cell[startRow + p][startCol + q];
                    }
                }
            }
            R.cell[i][j] = max;
        }
    }
    return R;
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size) {
    Matriks R;
    initMatriks(&R);
    R.nbaris = getNBaris(M) / size;
    R.nkolom = getNKolom(M) / size;

    if (getNBaris(M) % size != 0 || getNKolom(M) % size != 0){
        printf("ERROR\n");
        R.nbaris = 0;
        R.nkolom = 0;
        return R;
    }

    int i, j, p, q;
    for (i = 1; i <= R.nbaris; i++) {
        for (j = 1; j <= R.nkolom; j++) {
            int startRow = (i - 1) * size + 1;
            int startCol = (j - 1) * size + 1;
            int sum = 0;
            for (p = 0; p < size; p++) {
                for (q = 0; q < size; q++) {
                    sum += M.cell[startRow + p][startCol + q];
                }
            }
            R.cell[i][j] = sum / (size * size);
        }
    }
    return R;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K) {
    Matriks R;
    initMatriks(&R);

    if (getNBaris(M) < getNBaris(K) || getNKolom(M) < getNKolom(K)) {
        printf("ERROR: ukuran kernel lebih besar dari matriks\n");
        R.nbaris = 0;
        R.nkolom = 0;
        return R;
    }

    R.nbaris = getNBaris(M) - getNBaris(K) + 1;
    R.nkolom = getNKolom(M) - getNKolom(K) + 1;

    int i, j, p, q;
    for (i = 1; i <= R.nbaris; i++) {
        for (j = 1; j <= R.nkolom; j++) {
            int sum = 0;
            for (p = 1; p <= getNBaris(K); p++) {
                for (q = 1; q <= getNKolom(K); q++) {
                    sum += M.cell[i + p - 1][j + q - 1] * K.cell[p][q];
                }
            }
            R.cell[i][j] = sum;
        }
    }

    return R;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    *row = -999;
    *col = -999;
    boolean ketemu = false;
    for(int i = 1; i <= getNBaris(M) && !ketemu; i++){
        for(int j = 1; j <= getNKolom(M) && !ketemu; j++){
            if(M.cell[i][j] == X){
                *row = i;
                *col = j;
                ketemu = true;
            }
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
	int count = 0;
    for(int i = 1; i <= getNBaris(M); i++){
        for(int j = 1; j <= getNKolom(M); j++){
            if(M.cell[i][j] == X) {
				count++;
            }
        }
    }
	return count;
}