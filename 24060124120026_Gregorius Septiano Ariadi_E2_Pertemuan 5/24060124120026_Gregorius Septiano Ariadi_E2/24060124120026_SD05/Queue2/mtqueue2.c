/* Program   : mtqueue2.c*/
/* Deskripsi : Program uji coba ADT Queue versi 2*/
/* NIM/Nama  : 24060124200026 / Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 2 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "tqueue2.c"

int main()
{
    /* kamus main */
    tqueue2 Q1, Q2;
    char e;
    
    /* algoritma */
    printf("===== PROGRAM UJI COBA ADT QUEUE2 =====\n\n");

    /* 1. Create Queue */
    printf(">>> Kondisi awal Q1 <<<\n");
    createQueue2(&Q1);
    printQueue2(Q1);
    printf("isEmptyQueue2(Q1) = %d\n", isEmptyQueue2(Q1));
    printf("isFullQueue2(Q1)  = %d\n", isFullQueue2(Q1));
    printf("sizeQueue2(Q1)    = %d\n", sizeQueue2(Q1));

    /* 2. Enqueue beberapa elemen */
    printf("\n>>> Enqueue ke Q1 <<<\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    viewQueue2(Q1);
    printf("Head = %d, Tail = %d\n", head2(Q1), tail2(Q1));
    printf("infoHead = %c, infoTail = %c\n", infoHead2(Q1), infoTail2(Q1));

    /* 3. Dequeue satu elemen */
    printf("\n>>> Dequeue dari Q1 <<<\n");
    dequeue2(&Q1, &e);
    printf("Elemen yang diambil = %c\n", e);
    viewQueue2(Q1);
    printf("Head = %d, Tail = %d\n", head2(Q1), tail2(Q1));
    printf("sizeQueue2(Q1) = %d\n", sizeQueue2(Q1));

    /* 4. Dequeue semua */
    printf("\n>>> Dequeue semua <<<\n");
    while (!isEmptyQueue2(Q1)) {
        dequeue2(&Q1, &e);
        printf("Keluar: %c | Sisa Queue: ", e);
        viewQueue2(Q1);
    }
    printf("Q1 sekarang kosong\n");

    /* 5. Uji isOneElement */
    printf("\n>>> Uji isOneElement2 <<<\n");
    enqueue2(&Q1, 'X');
    if (isOneElement2(Q1)) {
        printf("Q1 berisi satu elemen: %c\n", infoHead2(Q1));
    }

    /* 6. Uji enqueue2N */
    printf("\n>>> Uji enqueue2N <<<\n");
    enqueue2N(&Q1, 2); // input manual dari keyboard
    printf("Isi Q1 sekarang: ");
    viewQueue2(Q1);
    printf("Head = %d, Tail = %d\n", head2(Q1), tail2(Q1)); 
    printf("infoHead = %c, infoTail = %c\n", infoHead2(Q1), infoTail2(Q1));

    /* 7. Uji isTailStop dan resetHead */
    printf("\n>>> Uji isTailStop dan resetHead <<<\n");
    while (!isFullQueue2(Q1)) {
        enqueue2(&Q1, 'Z');
    }
    printf("Isi penuh: ");
    viewQueue2(Q1);
    printf("Tail stop? %d\n", isTailStop(Q1));
    resetHead(&Q1);
    printf("Setelah resetHead: ");
    viewQueue2(Q1);

    /* 8. Uji Queue2 kedua */
    printf("\n>>> Uji enqueue2 & dequeue2 pada Q2 <<<\n");
    createQueue2(&Q2);
    enqueue2(&Q2, 'P');
    enqueue2(&Q2, 'R');
    enqueue2(&Q2, 'T');
    printf("Isi Q2: ");
    viewQueue2(Q2);
    printf("\n");

    printf("Dequeue2 beberapa kali...\n");
    dequeue2(&Q1, &e); printf("Keluar: %c\n", e);
    dequeue2(&Q2, &e); printf("Keluar: %c\n", e);
    dequeue2(&Q1, &e); printf("Keluar: %c\n", e);
    printf("Isi Q1 sekarang: "); viewQueue2(Q1); 
    printf("Isi Q2 sekarang: "); viewQueue2(Q2); 

    /* 9. Uji isEqualQueue2 */
    printf("\n>>> Uji isEqualQueue2 <<<\n");
    if (isEqualQueue2(Q1, Q2))
        printf("Q1 dan Q2 sama\n");
    else
        printf("Q1 dan Q2 berbeda\n");

    /* 10. Cetak kondisi akhir dengan printQueue2 */ 
    printf("\n>>> Kondisi akhir Q1 dan Q2 <<<\n"); 
    printQueue2(Q1); 
    printQueue2(Q2);

    printf("\n===== UJI COBA SELESAI =====\n");

    return 0;
}
