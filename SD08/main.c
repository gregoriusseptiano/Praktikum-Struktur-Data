/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR, representasi fisik pointer */
/* NIM & Nama : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal : Kamis, 13 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main() {
    //kamus lokal
    List2 L, L1, L2, L3;
    address P, Q;
    infotype X, V;
    int count;
    float freq;

    //algoritma
    printf("=== PENGUJIAN ADT LIST BERKAIT SIRKULAR ===\n\n");

    printf("Menguji Alokasi dan Dealokasi...\n");
    P = Alokasi('Z');
    if (P != NIL)
        printf("Alokasi berhasil, info(P) = %c\n", info(P));
    else
        printf("Alokasi gagal\n");
    Dealokasi(&P);
    if (P == NIL)
        printf("Dealokasi berhasil, pointer kosong\n\n");

    CreateList(&L);
    if (IsEmptyList(L))
        printf("List berhasil dibuat, masih kosong\n\n");

    printf("Tambahkan elemen ke list:\n");
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'I');
    InsertVLast(&L, 'U');
    InsertVLast(&L, 'E');
    InsertVLast(&L, 'O');
    PrintList(L);
    printf("Jumlah elemen list = %d\n", NbElm(L));
    if (IsOneElm(L))
        printf("List berisi satu elemen\n\n");
    else
        printf("List berisi lebih dari satu elemen\n\n");

    printf("Ubah huruf 'I' jadi 'Z'...\n");
    UpdateX(&L, 'I', 'Z');
    PrintList(L);
    printf("\n");

    count = CountVocal(L);
    printf("Jumlah huruf vokal = %d\n", count);
    printf("Huruf 'A' muncul %d kali\n", CountX(L, 'A'));
    freq = FrekuensiX(L, 'A') * 100;
    printf("Frekuensi huruf 'A' = %.2f%%\n\n", freq);

    SearchX(L, 'U', &Q);
    if (Q != NIL)
        printf("Elemen 'U' ditemukan di alamat %p\n", (void*)Q);
    else
        printf("Elemen 'U' tidak ditemukan\n");

    printf("Ganti semua huruf 'U' jadi 'X'...\n");
    UpdateX(&L, 'U', 'X');
    PrintList(L);
    printf("\n");

    printf("Sisipkan huruf 'B' setelah huruf 'A'...\n");
    InsertVAfterX(&L, 'A', 'B');
    PrintList(L);
    printf("\n");

    printf("Sisipkan huruf 'C' sebelum huruf 'Z'...\n");
    InsertVBeforeX(&L, 'Z', 'C');
    PrintList(L);
    printf("\n");

    printf("Uji versi nilai (tanpa pointer langsung)...\n");
    InsertVFirst(&L, 'K');
    InsertVLast(&L, 'L');
    PrintList(L);
    printf("\n");

    printf("Hapus elemen pertama (versi nilai)...\n");
    DeleteVFirst(&L, &V);
    printf("Elemen dihapus: %c\n", V);
    PrintList(L);
    printf("\n");

    printf("Hapus elemen terakhir (versi nilai)...\n");
    DeleteVLast(&L, &V);
    printf("Elemen dihapus: %c\n", V);
    PrintList(L);
    printf("\n");

    printf("Hapus huruf 'B'...\n");
    DeleteX(&L, 'B');
    PrintList(L);
    printf("\n");

    printf("Balik urutan list...\n");
    Invers(&L);
    PrintList(L);
    printf("\n");

    printf("Nilai modus list: %c\n", Modus(L));
    printf("Jumlah kemunculan modus: %d\n\n", MaxMember(L));

    printf("Cari semua posisi huruf 'E'...\n");
    SearchAllX(L, 'E');
    printf("\n");

    printf("Gabungkan dua list...\n");
    CreateList(&L1);
    InsertVLast(&L1, 'P');
    InsertVLast(&L1, 'Q');
    InsertVLast(&L1, 'R');
    InsertVLast(&L1, 'S');
    printf("Isi List1:\n");
    PrintList(L1);
    printf("\n");

    ConcatList(L, L1, &L3);
    printf("Hasil gabungan:\n");
    PrintList(L3);
    printf("\n");

    printf("Pisahkan list menjadi dua...\n");
    SplitList(L3, &L, &L2);
    printf("List 1:\n");
    PrintList(L);
    printf("List 2:\n");
    PrintList(L2);
    printf("\n");

    printf("Salin List 1 ke List baru...\n");
    CopyList(L, &L3);
    PrintList(L3);
    printf("\n");

    printf("Jumlah huruf 'N' diikuti 'G': %d\n", CountNG(L3));

    printf("\n=== SELESAI ===\n");
    return 0;
}
