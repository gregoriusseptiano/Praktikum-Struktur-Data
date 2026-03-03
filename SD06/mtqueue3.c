/* Program   : mtqueue3.c */
/* Deskripsi : Main program untuk menguji semua fungsi dan prosedur queue versi 3 */
/* NIM/Nama  : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal   : Kamis, 9 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue3.c"

int main() 
{	
    /* Kamus */
    tqueue3 Q;
    char E;

    /* Algoritma */
    printf("=== Uji Program Queue Versi 3 ===\n\n");

    /* 1. createQueue3 */
    createQueue3(&Q);
    printf("Setelah createQueue3:\n");
    printQueue3(Q);
    printf("isEmptyQueue3 = %d\n", isEmptyQueue3(Q));
    printf("isFullQueue3 = %d\n\n", isFullQueue3(Q));

    /* 2. enqueue3 */
    printf("Enqueue A, B, C\n");
    enqueue3(&Q, 'A');
    enqueue3(&Q, 'B');
    enqueue3(&Q, 'C');
    printQueue3(Q);
    printf("Elemen queue: ");
    viewQueue3(Q);
    printf("Head = %d, Tail = %d\n", head3(Q), tail3(Q));
    printf("InfoHead = %c, InfoTail = %c\n\n", infoHead3(Q), infoTail3(Q));

    /* 3. dequeue3 */
    printf("Dequeue satu elemen...\n");
    dequeue3(&Q, &E);
    printf("Elemen yang dihapus: %c\n", E);
    printQueue3(Q);
    printf("Elemen queue: ");
    viewQueue3(Q);
    printf("Head = %d, Tail = %d\n\n", head3(Q), tail3(Q));

    /* 4. Tambah elemen hingga penuh */
    printf("Enqueue D, E, F\n");
    enqueue3(&Q, 'D');
    enqueue3(&Q, 'E');
    enqueue3(&Q, 'F'); 
    printQueue3(Q);
    printf("Elemen queue: ");
    viewQueue3(Q);
    printf("isFullQueue3 = %d\n\n", isFullQueue3(Q));

    /* 5. Uji sizeQueue3 dan isTailOverHead */
    printf("Jumlah elemen = %d\n", sizeQueue3(Q));
    printf("isTailOverHead = %d\n\n", isTailOverHead(Q));

    /* 6. Hapus beberapa elemen lagi */
    printf("Dequeue dua elemen...\n");
    dequeue3(&Q, &E);
    printf("Dihapus: %c\n", E);
    dequeue3(&Q, &E);
    printf("Dihapus: %c\n", E);
    printQueue3(Q);
    printf("Elemen queue: ");
    viewQueue3(Q);
    printf("Head = %d, Tail = %d\n", head3(Q), tail3(Q));
    printf("isOneElement3 = %d\n\n", isOneElement3(Q));

    /* 7. Kosongkan queue */
    printf("Mengosongkan queue...\n");
    while (!isEmptyQueue3(Q)) {
        dequeue3(&Q, &E);
        printf("Dequeue: %c\n", E);
    }
    printQueue3(Q);
    printf("isEmptyQueue3 = %d\n", isEmptyQueue3(Q));

    printf("\n=== Pengujian selesai ===\n");
    return 0;
}
