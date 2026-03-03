/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal : Kamis, 20 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"
#include "boolean.h"

int main() {
    //kamus lokal
    List3 L, L1, L2;
    address P;
    char c;

    //algoritma
    printf("=== PENGUJIAN ADT LIST BERKAIT GANDA ===\n\n");

    // 1. CreateList dan IsEmptyList
    CreateList(&L);
    printf("List dibuat.\n");
    if (IsEmptyList(L)) {
        printf("List masih kosong.\n");
    }

    // 2. InsertVFirst dan InsertVLast
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'I');
    InsertVLast(&L, 'U');
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'O');
    printf("\nIsi list setelah InsertVFirst & InsertVLast:\n");
    PrintList(L);

    // 3. NbElm
    printf("\nJumlah elemen list = %d\n", NbElm(L));

    // 4. UpdateX
    printf("\nUbah huruf 'I' jadi 'Z'...\n");
    UpdateX(&L, 'I', 'Z');
    PrintList(L);

    // 5. CountVocal dan CountX
    printf("\nBanyak huruf vokal = %d\n", CountVocal(L));
    printf("Huruf 'A' muncul %d kali\n", CountX(L, 'A'));

    // 6. FrekuensiX dan CpuntNG
    printf("Frekuensi huruf 'A' = %.2f\n", FrekuensiX(L, 'A'));
    printf("Jumlah pola NG = %d\n", CountNG(L));

    // 7. SearchX dan UpdateX
    SearchX(L, 'U', &P);
    if (P != NIL) {
        printf("\nElemen 'U' ditemukan di alamat %p\n", P);
    }
    printf("Ganti semua huruf 'U' jadi 'X'\n");
    UpdateX(&L, 'U', 'X');
    PrintList(L);

    // 8. InsertVAfterX
    printf("\nSisipkan huruf 'B' setelah huruf 'A'\n");
    InsertVAfterX(&L, 'A', 'B');
    PrintList(L);

    // 9. InsertVBeforeX
    printf("\nSisipkan huruf 'C' sebelum huruf 'Z'\n");
    InsertVBeforeX(&L, 'Z', 'C');
    PrintList(L);

    // 10. DeleteVFirst
    printf("\nHapus elemen pertama...\n");
    DeleteVFirst(&L, &c);
    printf("Elemen yang dihapus: %c\n", c);
    PrintList(L);

    // 11. DeleteVLast
    printf("\nHapus elemen terakhir...\n");
    DeleteVLast(&L, &c);
    printf("Elemen yang dihapus: %c\n", c);
    PrintList(L);

    // 12. DeleteVAfterX
    printf("\nHapus elemen setelah huruf 'A'\n");
    DeleteVAfterX(&L, 'A', &c);
    printf("Elemen yang dihapus: %c\n", c);
    PrintList(L);

    // 13. DeleteVBeforeX
    printf("\nHapus elemen sebelum huruf 'O'\n");
    DeleteVBeforeX(&L, 'O', &c);
    printf("Elemen yang dihapus: %c\n", c);
    PrintList(L);

    // 14. DeleteX
    printf("\nHapus elemen 'B' dengan DeleteX...\n");
    DeleteX(&L, 'B');
    PrintList(L);

    // 15. SearchAllX
    printf("\nPosisi huruf 'X' di dalam list:\n");
    SearchAllX(L, 'X');

    // 16. Modus dan MaxMember
    printf("\nModus list: %c\n", Modus(L));
    printf("Jumlah kemunculan terbanyak: %d\n", MaxMember(L));

    // 17. ConcatList
    printf("\nContoh penggabungan list...\n");
    CreateList(&L1);
    CreateList(&L2);
    InsertVLast(&L1, 'M');
    InsertVLast(&L1, 'N');
    InsertVLast(&L2, 'P');
    InsertVLast(&L2, 'Q');
    ConcatList(L1, L2, &L);
    PrintList(L);

    // 18. SplitList
    printf("\nPisahkan list menjadi dua bagian...\n");
    SplitList(L, &L1, &L2);
    printf("List 1:\n");
    PrintList(L1);
    printf("List 2:\n");
    PrintList(L2);

    // 19. CopyList
    printf("\nSalin List1 ke list baru...\n");
    CopyList(L1, &L);
    PrintList(L);

    // 20. DeleteAllX
    printf("\nHapus semua huruf 'M'...\n");
    DeleteAllX(&L, 'M');
    PrintList(L);

    // 21. Invers
    printf("\nBalik urutan list...\n");
    Invers(&L);
    PrintList(L);

    printf("\n=== SELESAI ===\n");
    return 0;
}