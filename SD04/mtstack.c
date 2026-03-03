/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124120026 / Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 25 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.c"

int main() 
{	/* kamus main */
	Tstack A;
    char X;
    int N;
    char kata[20];
	
	/* algoritma */
	printf("=== PROGRAM DRIVER STACK KARAKTER ===\n\n");

    /* 1. createStack */
    printf("1. Membuat stack kosong...\n");
    createStack(&A);
    printStack(A);
    printf("Top = %d\n\n", top(A));

    /* 2. isEmptyStack & isFullStack */
    printf("2. Mengecek apakah stack kosong/penuh...\n");
    if(isEmptyStack(A)) {
        printf("Stack masih kosong.\n");
    }
    if(!isFullStack(A)) {
        printf("Stack belum penuh.\n");
    }
    printf("\n");

    /* 3. push */
    printf("3. Push 3 elemen ke stack: A, B, C\n");
    push(&A, 'A');
    push(&A, 'B');
    push(&A, 'C');
    viewStack(A);
    printf("Top sekarang: %d\n", top(A));
    printf("Infotop: %c\n\n", infotop(A));

    /* 4. pop */
    printf("4. Pop elemen dari stack...\n");
    pop(&A, &X);
    printf("Elemen yang di-pop: %c\n", X);
    viewStack(A);
    printf("Top sekarang: %d\n\n", top(A));

    /* 5. pushN */
    printf("5. PushN elemen dari keyboard...\n");
    printf("Masukkan berapa banyak data yang ingin dimasukkan: ");
    scanf("%d", &N);
    pushN(&A, N);
    viewStack(A);
    printf("Top sekarang: %d\n\n", top(A));

    /* 6. printStack */
    printf("6. Print kondisi wadah stack...\n");
    printStack(A);
    printf("\n");

    /* 7. isPalindrom */
    printf("7. Mengecek kata palindrom...\n");
    printf("Masukkan sebuah kata (max 20): ");
    scanf("%s", kata);
    if(isPalindrom(kata)) {
        printf("'%s' adalah palindrom.\n", kata);
    } else {
        printf("'%s' bukan palindrom.\n", kata);
    }
    printf("\n");

    printf("=== SELESAI UJI STACK ===\n");
    return 0;
}