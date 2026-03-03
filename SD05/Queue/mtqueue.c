/* Program   : mtqueue.c */
/* Deskripsi : Main program uji coba ADT Queue kontigu*/
/* NIM/Nama  : 24060124200026 / Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 2 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "tqueue.c"

int main() 
{	
    /* kamus main */
    tqueue Q1, Q2;
    char e;

    /* algoritma */
    printf("===== PROGRAM UJI COBA ADT QUEUE =====\n\n");

    /* Inisialisasi */
    createQueue(&Q1);
    createQueue(&Q2);

    printf(">>> Kondisi awal Q1 <<<\n");
    printQueue(Q1);
    printf("isEmptyQueue(Q1) = %d\n", isEmptyQueue(Q1));
    printf("isFullQueue(Q1)  = %d\n", isFullQueue(Q1));
    printf("sizeQueue(Q1)    = %d\n\n", sizeQueue(Q1));

    /* Enqueue beberapa elemen */
    printf(">>> Enqueue ke Q1 <<<\n");
    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E'); 

    printQueue(Q1);
    printf("ViewQueue(Q1): ");
    viewQueue(Q1);
    printf("Head = %d, Tail = %d\n", head(Q1), tail(Q1));
    printf("infoHead = %c, infoTail = %c\n\n", infoHead(Q1), infoTail(Q1));

    /* Dequeue satu elemen */
    printf(">>> Dequeue dari Q1 <<<\n");
    dequeue(&Q1, &e);
    printf("Elemen yang diambil = %c\n", e);
    printQueue(Q1);
    printf("ViewQueue(Q1): ");
    viewQueue(Q1);
    printf("sizeQueue(Q1) = %d\n\n", sizeQueue(Q1));

    /* Dequeue semua sampai kosong */
    printf(">>> Dequeue semua <<<\n");
    while (!isEmptyQueue(Q1)) {
        dequeue(&Q1, &e);
        printf("Keluar: %c | Sisa Queue: ", e);
        viewQueue(Q1);
    }
    printf("Q1 sekarang kosong\n\n");

    /* Uji isOneElement */
    printf(">>> Uji isOneElement <<<\n");
    enqueue(&Q1, 'X');
    if (isOneElement(Q1)) {
        printf("Q1 berisi satu elemen: %c\n\n", infoHead(Q1));
    }

    /* Uji enqueue2 dan dequeue2 dengan Q1 dan Q2 */
    printf(">>> Uji enqueue2 dan dequeue2 <<<\n");
    enqueue2(&Q1, &Q2, 'P');
    enqueue2(&Q1, &Q2, 'Q');
    enqueue2(&Q1, &Q2, 'R');
    enqueue2(&Q1, &Q2, 'S');
    enqueue2(&Q1, &Q2, 'T');

    printf("Isi Q1: "); viewQueue(Q1);
    printf("Isi Q2: "); viewQueue(Q2);

    printf("Dequeue2 beberapa kali...\n");
    dequeue2(&Q1, &Q2, &e);
    printf("Keluar: %c\n", e);
    dequeue2(&Q1, &Q2, &e);
    printf("Keluar: %c\n", e);
    dequeue2(&Q1, &Q2, &e);
    printf("Keluar: %c\n", e);

    printf("Isi Q1 sekarang: "); viewQueue(Q1);
    printf("Isi Q2 sekarang: "); viewQueue(Q2);

    printf("\n===== UJI COBA SELESAI =====\n");

    return 0;
}
