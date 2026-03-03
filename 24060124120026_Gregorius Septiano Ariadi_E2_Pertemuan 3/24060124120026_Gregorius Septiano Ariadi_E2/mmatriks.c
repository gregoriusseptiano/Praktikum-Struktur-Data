/* Program   : mmatriks.c */
/* Deskripsi : Driver ADT matriks integer (uji semua fungsi otomatis) */
/* NIM/Nama  : 24060124200026 / Gregorius Septiano Ariadi */
/* Tanggal   : 18-09-2025 */
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

int main() {
    /* Kamus */
    Matriks M1, M2, M3, MHasil, Kernel, MInput;
    int r, c;

    /* Algoritma */
    srand(12345); 

    printf("===== PROGRAM UJI COBA ADT MATRIKS =====\n");

    /* Inisialisasi */
    initMatriks(&M1);
    initMatriks(&M2);
    initMatriks(&M3);
    initMatriks(&MHasil);
    initMatriks(&Kernel);
    initMatriks(&MInput);

    printf("\n>>> Kondisi awal M1 <<<\n");
    printMatriks(M1);
    printf("isEmptyMatriks(M1) = %d\n", isEmptyMatriks(M1));
    printf("isFullMatriks(M1)  = %d\n", isFullMatriks(M1));

    /* Isi M1 pakai addX */
    printf("\n>>> Mengisi M1 secara otomatis dengan addX (2x2) <<<\n");
    addX(&M1, 7, 1, 1);
    addX(&M1, 3, 1, 2);
    addX(&M1, 8, 2, 1);
    addX(&M1, 6, 2, 2);
    viewMatriks(M1);
    printf("Jumlah baris M1 = %d\n", getNBaris(M1));
    printf("Jumlah kolom M1 = %d\n", getNKolom(M1));

    /* Hapus elemen: delX menghapus BERDASARKAN NILAI, bukan koordinat */
    printf("\n>>> Menghapus nilai 6 dari M1 (gunakan delX(&M1, 6)) <<<\n");
    delX(&M1, 6); /* bukan delX(&M1,2,2) */
    viewMatriks(M1);

    /* Isi random */
    printf("\n>>> Mengisi M2 dengan angka random (3x3) <<<\n");
    isiMatriksRandom(&M2, 3, 3);
    viewMatriks(M2);

    /* Isi identitas: gunakan ukuran 3 agar kompatibel dengan M2 untuk perkalian */
    printf("\n>>> Membuat matriks identitas M3 (3x3) <<<\n");
    isiMatriksIdentitas(&M3, 3);
    viewMatriks(M3);

    /* Operasi aritmatika */
    printf("\n>>> Penjumlahan M2 + M2 <<<\n");
    MHasil = addMatriks(M2, M2);
    viewMatriks(MHasil);

    printf("\n>>> Pengurangan M2 - M2 <<<\n");
    MHasil = subMatriks(M2, M2);
    viewMatriks(MHasil);

    printf("\n>>> Perkalian M2 x M3 (3x3 x 3x3) <<<\n");
    MHasil = kaliMatriks(M2, M3);
    viewMatriks(MHasil);

    printf("\n>>> Perkalian skalar M2 x 5 <<<\n");
    MHasil = kaliSkalarMatriks(M2, 5);
    viewMatriks(MHasil);

    /* Transpose */
    printf("\n>>> Transpose M2 (in-place) <<<\n");
    transposeMatriks(&M2);
    viewMatriks(M2);

    printf("\n>>> GetTranspose dari M3 (hasil baru) <<<\n");
    MHasil = getTransposeMatriks(M3);
    viewMatriks(MHasil);

    /* Padding */
    printf("\n>>> Menambahkan padding n=1 pada M2 <<<\n");
    MHasil = addPadding(M2, 1);
    viewMatriks(MHasil);

    /* Pooling (pastikan ukuran habis dibagi) */
    printf("\n>>> MaxPooling 1 (size=1) pada M3 (sebagai contoh aman) <<<\n");
    MHasil = maxPooling(M3, 1);
    viewMatriks(MHasil);

    printf("\n>>> AvgPooling 1 (size=1) pada M3 (sebagai contoh aman) <<<\n");
    MHasil = avgPooling(M3, 1);
    viewMatriks(MHasil);

    /* Konvolusi */
    printf("\n>>> Convolution M3 (3x3) dengan kernel identitas 2x2 <<<\n");
    isiMatriksIdentitas(&Kernel, 2);
    viewMatriks(Kernel);
    MHasil = conv(M3, Kernel);
    viewMatriks(MHasil);

    /* Pencarian */
    printf("\n>>> Search nilai 1 di M3 <<<\n");
    searchX(M3, 1, &r, &c);
    if (r == -999) 
        printf("Nilai 1 tidak ditemukan di M3\n");
    else            
        printf("Nilai 1 ditemukan di (%d, %d)\n", r, c);

    printf("\n>>> Hitung banyaknya angka 1 di M3 <<<\n");
    printf("Jumlah = %d\n", countX(M3, 1));

    /* Uji populateMatriks */
    printf("\n>>> Isi matriks secara manual dengan populateMatriks (contoh 2x2) <<<\n");
    populateMatriks(&MInput, 2, 2);
    printf("Hasil input manual MInput:\n");
    viewMatriks(MInput);

    printf("\n===== SELESAI UJI COBA =====\n");
    return 0;
}
