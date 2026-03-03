/************************************/
/* Program   : maintabel.c          */
/* Deskripsi : aplikasi driver modul Tabel */
/* NIM/Nama  : 24060124120026/Gregorius Septiano Ariadi */
/* Tanggal   : 11/09/2025           */
/***********************************/

#include <stdio.h>
#include "tabel.h"

int main() {
    // Kamus
    Tabel T1; 
    Tabel T2;
    Tabel T3;
    int pos;
    char x;

    // Algoritma
    printf("=== DEMO PENGUJIAN MODUL TABEL ===\n\n");

        // buat T1
    createTable(&T1);
    printf("Isi T1 setelah createTable:\n");
    printTable(T1);

    addXTable(&T1, 'H');
    addXTable(&T1, 'I');
    addXTable(&T1, 'J');
    addXTable(&T1, 'K');
    addXTable(&T1, 'L');
    addXTable(&T1, 'M');
    addXTable(&T1, 'M');
    addXTable(&T1, 'H');
    printf("\nIsi T1 setelah addXTable:\n");
    viewTable(T1);

    printf("\nUkuran T1 = %d\n", getSize(T1));
    printf("Apakah T1 kosong? %s\n", isEmptyTable(T1) ? "Ya" : "Tidak");
    printf("Apakah T1 sudah penuh? %s\n", isFullTable(T1) ? "Ya" : "Tidak");

    x = 'M';
    searchX(T1, x, &pos);
    printf("\nLetak kemunculan pertama '%c' di T1 = %d\n", x, pos);
    printf("Banyaknya '%c' di T1 = %d\n", x, countX(T1, x));
    printf("Jumlah huruf vokal dalam T1 = %d\n", countVocal(T1));

    delXTable(&T1, 'M');
    printf("\nIsi T1 setelah delXTable('M'):\n");
    viewTable(T1);

    delAllXTable(&T1, 'M');
    printf("\nIsi T1 setelah delAllXTable('M'):\n");
    viewTable(T1);

    addUniqueXTable(&T1, 'D');
    addUniqueXTable(&T1, 'O');
    printf("\nIsi T1 setelah addUniqueXTable:\n");
    viewTable(T1);

        // buat T2
    createTable(&T2);
    addXTable(&T2, 'Z');
    addXTable(&T2, 'H');
    addXTable(&T2, 'I');
    addXTable(&T2, 'J');
    addXTable(&T2, 'Z');
    printf("\nApakah isi T1 identik dengan T2? %s\n", isEqualTable(T1, T2) ? "Ya" : "Tidak");

    printf("\n=== Modus ===\n");
    printf("Elemen yang paling sering muncul di T1 = %c\n", Modus(T1));
    printf("Elemen yang paling sering muncul di T2 = %c\n", Modus(T2));

       // buat T3
    createTable(&T3);
    addXTable(&T3, 'A');
    addXTable(&T3, 'B');
    addXTable(&T3, 'C');
    addXTable(&T3, 'D');
    addXTable(&T3, 'E');
    addXTable(&T3, 'X');
    printf("Status T2 dan T3 = %d\n", isEqualTable(T2, T3));

    printf("\n=== getInverseTable ===\n");
    printf("Tabel T3 sebelum di inverse :\n");
    viewTable(T3);
    printf("\nTabel T3 setelah di inverse :\n");
    viewTable(getInverseTable(T3));

    printf("\n=== inverseTable ===\n");
    printf("Tabel T1 sebelum di inverse :\n");
    viewTable(T1);
    printf("\nTabel T1 setelah di inverse :\n");
    inverseTable(&T1);
    viewTable(T1);

    printf("\n=== delXTable ===\n");
    x = 'J';
    printf("Tabel T2 sebelum delete %c :\n", x);
    viewTable(T2);
    printf("\nTabel T2 seteah delete %c :\n", x);
    delXTable(&T2, x);
    viewTable(T2);

    printf("\n=== delTable ===\n");
    printf("Tabel T3 sebelum delete pada idx ke-1:\n");
    viewTable(T3);
    printf("\nTabel T3 setelah delete pada idx ke-1 :\n");
    delTable(&T3, 1);
    viewTable(T3);

    printf("\n=== delAllXTable ===\n");
    x = 'K';
    printf("Tabel T1 sebelum delete %c :\n", x);
    viewTable(T1);
    printf("\nTabel T1 setelah delete %c :\n", x);
    delAllXTable(&T1, x);
    viewTable(T1);

    printf("\n=== sortAsc ===\n");
    printf("Tabel T1 sebelum sortAsc :\n");
    viewTable(T1);
    printf("\nTabel T1 setelah sortAsc :\n");
    sortAsc(&T1);
    viewTable(T1);

    printf("\n=== sorDesc ===\n");
    printf("Tabel T3 sebelum sortDesc :\n");
    viewTable(T3);
    printf("\nTabel T3 setelah sortDesc :\n");
    sortDesc(&T3);
    viewTable(T3);

    printf("\n=== AKHIR DEMO MODUL TABEL ===\n");
    return 0;
}
