/* Program   : mbrowser.c */
/* Deskripsi : simulasi tombol Backward & Forward browser menggunakan ADT Stack */
/* NIM/Nama  : 24060124120026 / Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 25 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.c"

int main() {
    /* Kamus */
    Tstack history, forward;
    int kode;
    char url, X;

    /* Algoritma */
    createStack(&history);
    createStack(&forward);

    printf("=== SIMULASI BROWSER DENGAN STACK ===\n");
    printf("Kode:\n");
    printf("1: Kunjungi halaman baru\n");
    printf("2: Backward\n");
    printf("3: Forward\n");
    printf("4: Exit\n");

    do {
        printf("\nMasukkan kode: ");
        scanf("%d", &kode);

        if(kode == 1) {
            printf("Masukkan halaman (1 karakter): ");
            scanf(" %c", &url);
            push(&history, url);
            createStack(&forward);
            printf("\n>> Halaman baru dikunjungi: %c\n", url);

        } else if(kode == 2) {
            if(!isEmptyStack(history)) {
                pop(&history, &X);
                push(&forward, X);

                if(!isEmptyStack(history)) {
                    printf("\n>> Backward ke halaman: %c\n", infotop(history));
                } else {
                    printf("\n>> Tidak ada halaman sebelumnya!\n");
                }
            } else {
                printf("\n>> History kosong, tidak bisa backward!\n");
            }

        } else if(kode == 3) {
            if(!isEmptyStack(forward)) {
                pop(&forward, &X);
                push(&history, X);

                printf("\n>> Forward ke halaman: %c\n", X);
            } else {
                printf("\n>> Tidak ada halaman untuk forward!\n");
            }
        } else if(kode == 4) {
            printf("\nKeluar dari program...\n");
            break;
        } else {
            printf("\nKode tidak valid!\n");
        }

        if(kode >= 1 && kode <= 3) {
            printf("Current page: ");
            if(!isEmptyStack(history)) {
                printf("%c\n", infotop(history));
            } else {
                printf("Kosong\n");
            }

            printf("Stack History : ");
            viewStack(history);

            printf("Stack Forward : ");
            viewStack(forward);
        }

    } while(kode != 4);

    printf("\n=== SELESAI ===\n");
    return 0;
}