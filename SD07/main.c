/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal : Kamis, 06 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main()
{
    // Kamus
    address A, B, P, Q;
    List1 Senarai, L1, L2;
    char c;

    // Algoritma
    printf("=== PENGUJIAN ADT LIST BERKAIT POINTER ===\n\n");

    // 1. CreateList dan IsEmptyList
    CreateList(&Senarai);
    printf("List dibuat.\n");
    if (IsEmptyList(Senarai))
        printf("List masih kosong.\n");

    // 2. InsertVFirst dan InsertVLast
    InsertVFirst(&Senarai, 'A');
    InsertVLast(&Senarai, 'I');
    InsertVLast(&Senarai, 'U');
    InsertVLast(&Senarai, 'E');
    InsertVLast(&Senarai, 'O');
    printf("\nIsi list setelah InsertVFirst & InsertVLast:\n");
    PrintList(Senarai);

    // 3. NbElm
    printf("\nJumlah elemen list = %d\n", NbElm(Senarai));

    // 4. UpdateX
    printf("\nUbah huruf 'I' jadi 'Z'...\n");
    UpdateX(&Senarai, 'I', 'Z');
    PrintList(Senarai);

    // 5. CountVocal
    printf("\nBanyak huruf vokal = %d\n", CountVocal(Senarai));

    // 6. CountX dan FrekuensiX
    printf("Huruf 'A' muncul %d kali\n", CountX(Senarai, 'A'));
    printf("Frekuensi huruf 'A' = %.2f%%\n", FrekuensiX(Senarai, 'A'));

    // 7. SearchX dan UpdateAllX
    SearchX(Senarai, 'U', &Q);
    if (Q != NIL)
        printf("\nElemen 'U' ditemukan di alamat %p\n", Q);
    printf("Ganti semua huruf 'U' jadi 'X'\n");
    UpdateAllX(&Senarai, 'U', 'X');
    PrintList(Senarai);

    // 8. InsertVAfter
    printf("\nSisipkan huruf 'B' setelah huruf 'A'\n");
    InsertVAfter(&Senarai, 'A', 'B');
    PrintList(Senarai);

    // 9. DeleteVFirst
    printf("\nHapus elemen pertama...\n");
    DeleteVFirst(&Senarai, &c);
    printf("Elemen yang dihapus: %c\n", c);
    PrintList(Senarai);

    // 10. DeleteVLast
    printf("\nHapus elemen terakhir...\n");
    DeleteVLast(&Senarai, &c);
    printf("Elemen yang dihapus: %c\n", c);
    PrintList(Senarai);

    // 11. Invers
    printf("\nBalik urutan list...\n");
    Invers(&Senarai);
    PrintList(Senarai);

    // 12. Modus dan NbModus
    printf("\nNilai modus list: %c\n", Modus(Senarai));
    printf("Jumlah kemunculan modus: %d\n", NbModus(Senarai));

    // 13. ConcatList
    printf("\nGabungkan dua list...\n");
    CreateList(&L1);
    CreateList(&L2);
    InsertVLast(&L1, 'P');
    InsertVLast(&L1, 'Q');
    InsertVLast(&L2, 'R');
    InsertVLast(&L2, 'S');
    ConcatList(L1, L2, &Senarai);
    PrintList(Senarai);

    // 14. SplitList
    printf("\nPisahkan list menjadi dua...\n");
    SplitList(Senarai, &L1, &L2);
    printf("List 1:\n");
    PrintList(L1);
    printf("List 2:\n");
    PrintList(L2);

    // 15. CopyList
    printf("\nSalin List 1 ke List baru...\n");
    CopyList(L1, &Senarai);
    PrintList(Senarai);

    printf("\n=== SELESAI ===\n");
    return 0;
}