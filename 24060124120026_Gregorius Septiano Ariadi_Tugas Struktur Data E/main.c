/* Program   : main.c */
/* Deskripsi : Program utama (driver) digunakan untuk mensimulasikan penjadwalan proses CPU dengan
               memanfaatkan ADT Proses dan ADT Queue. */
/* NIM/Nama  : Gregorius Septiano Ariadi / 24060124120026 */
/* Tanggal   : Jumat, 10 Oktober 2025 */
/***********************************************/

#include <stdio.h>
#include "proses.c"

int main() {
    /* Kamus */
    tqueue Q;
    Proses P1, P2, P3, P4, P5, keluar;
    int waktuMulai, waktuSelesai, i;

    /* Algoritma */
    printf("Simulasi Penjadwalan Proses CPU (SJF)\n\n");

    printf("=== Uji 1: Inisialisasi Queue ===\n");
    CreateQueue(&Q);
    PrintQueue(Q);
    printf("Queue kosong? %d\n", IsEmptyQueue(Q));
    printf("Queue penuh?  %d\n\n", IsFullQueue(Q));

    printf("=== Uji 2: Pembuatan Proses ===\n");
    MakeProses(&P1, 'A', 2);
    MakeProses(&P2, 'B', 5);
    MakeProses(&P3, 'C', 8);
    MakeProses(&P4, 'D', 2);
    MakeProses(&P5, 'E', 6);
    printf("Proses dibuat: A(2), B(5), C(8), D(2), E(6)\n\n");

    printf("=== Uji 3: Enqueue Proses ===\n");
    Enqueue(&Q, P1);
    Enqueue(&Q, P2);
    Enqueue(&Q, P3);
    Enqueue(&Q, P4);
    Enqueue(&Q, P5);
    PrintQueue(Q);
    printf("Head = %d, Tail = %d\n", head(Q), tail(Q));
    printf("Queue penuh? %d\n\n", IsFullQueue(Q));

    printf("=== Uji 4: Urutkan Berdasarkan Burst Time (SJF) ===\n");
    SortByBurstTime(&Q);
    PrintQueue(Q);
    printf("\n");

    printf("=== Uji 5: Simulasi Eksekusi Proses ===\n");
    waktuMulai = 0;
    for (i = head(Q); i <= tail(Q); i++) {
        waktuSelesai = waktuMulai + GetBurstTime(Q.wadah[i]);
        printf("Proses %c dimulai %d, selesai %d (Burst: %d)\n",
               GetIDProses(Q.wadah[i]),
               waktuMulai, waktuSelesai, GetBurstTime(Q.wadah[i]));
        waktuMulai = waktuSelesai;
    }

    printf("\n=== Uji 6: Dequeue Semua Proses ===\n");
    while (!IsEmptyQueue(Q)) {
        keluar = Dequeue(&Q);
        printf("Keluar: %c | Sisa antrian: ", GetIDProses(keluar));
        PrintQueue(Q);
    }
    printf("Queue kosong sekarang.\n\n");

    printf("=== Uji 7: Kondisi Akhir ===\n");
    printf("Queue kosong? %d\n", IsEmptyQueue(Q));
    printf("Queue penuh?  %d\n", IsFullQueue(Q));
    PrintQueue(Q);

    return 0;
}