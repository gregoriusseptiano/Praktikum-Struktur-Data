/* File      : proses.c */
/* Deskripsi : Penerapan ADT Proses dan ADT Queue digunakan untuk mensimulasikan penjadwalan proses CPU 
               dengan algoritma SJF (Shortest Job First).
               Queue direpresentasikan secara kontigu menggunakan array, di mana posisi head berpindah
               (bergeser) saat elemen dikeluarkan. */
/* NIM/Nama  : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal   : Jumat, 10 Oktober 2025 */
/***********************************************/

#include <stdio.h>
#include "proses.h"

/* KONSTRUKTOR */
/*procedure makeProses (output P: Proses, input x: character, y:integer) 
{I.S.: -}
{F.S.: P terdefinisi, kosong}
{Proses: mengisi nilai IdProses dengan x dan BurstTime dengan y} */
void MakeProses(Proses *P, char x, int y) {
    (*P).IdProses = x;
    (*P).burstTime = y;
}

/* Mutator */
/* Procedure SetIDProses(input/output P:Proses, input x:character)
{ I.S.: P terdefinisi, x terdefinisi }
{ F.S.: nilai id pada Proses P berubah sesuai parameter x }
{ Proses: mengganti IDProses dari Proses } */
void SetIDProses(Proses *P, char x) {
    (*P).IdProses = x;
}

/* Procedure SetBurstTime(input/output P:Proses, input y:integer)
{ I.S.: P terdefinisi, y terdefinisi }
{ F.S.: nilai burstTime pada Proses P berubah sesuai parameter y }
{ Proses: mengganti Burst Time dari Proses } */
void SetBurstTime(Proses *P, int y) {
    (*P).burstTime = y;
}

/* SELEKTOR */
/*function GetIDProses(P: Proses) -> character 
{mengembalikan nilai komponen IdProses P} */
char GetIDProses(Proses P) {
    return P.IdProses;
}

/*function GetBurstTime(P: Proses) -> integer 
{mengembalikan nilai komponen BurstTime P} */
int GetBurstTime(Proses P) {
    return P.burstTime;
}

// ****************************************
//     BAGIAN ADT QUEUE
// ****************************************

/*procedure CreateQueue (output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi IdProses = '-' dan BursTime = -999, head=tail=0 } */ 
void CreateQueue(tqueue *Q) {
    (*Q).head = 0;
    (*Q).tail = 0;
}

/* Function IsEmptyQueue(Q:tqueue) -> boolean
   Mengembalikan true jika Queue kosong */
boolean IsEmptyQueue(tqueue Q) {
    return (head(Q) == 0 && tail(Q) == 0);
}

/* Function IsFullQueue(Q:tqueue) -> boolean
   Mengembalikan true jika Queue penuh */
boolean IsFullQueue(tqueue Q) {
    return (tail(Q) == MAX - 1);
}

/* Procedure Enqueue(Q:tqueue, P:Proses)
   I.S.: Q dan P terdefinisi
   F.S.: elemen P ditambahkan ke antrian jika belum penuh */
void Enqueue(tqueue *Q, Proses P) {
    if (IsFullQueue(*Q)) {
        printf("Queue penuh\n");
        return;
    }
    if (IsEmptyQueue(*Q)) {
        (*Q).head = 1;
        (*Q).tail = 1;
    } else {
        (*Q).tail++;
    }
    (*Q).wadah[(*Q).tail] = P;
}

/* procedure Dequeue(input/output Q:tqueue)
   I.S.: Q terdefinisi, mungkin kosong
   F.S.: jika tidak kosong, mengeluarkan elemen pertama (head)
         dan menggeser elemen lainnya */
Proses Dequeue(tqueue *Q) {
    /* Kamus Lokal */
    int i;
    Proses P;
    /* Algoritma */
    P = (*Q).wadah[(*Q).head];
    if ((*Q).head == (*Q).tail) {
        (*Q).head = 0;
        (*Q).tail = 0;
    } else {
        for (i = (*Q).head; i < (*Q).tail; i++) {
            (*Q).wadah[i] = (*Q).wadah[i + 1];
        }
        (*Q).tail--;
    }
    return P;
}

/* Procedure PrintQueue(Q:tqueue)
   I.S.: Q terdefinisi
   F.S.: menampilkan seluruh elemen antrian ke layar */
void PrintQueue(tqueue Q) {
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    if (IsEmptyQueue(Q)) {
        printf("Queue kosong\n");
    } else {
        printf("Antrian proses:\n");
        for (i = head(Q); i <= tail(Q); i++) {
            printf("Proses %c | Burst Time: %d\n",
                   GetIDProses(Q.wadah[i]),
                   GetBurstTime(Q.wadah[i]));
        }
    }
}

/* Procedure SortByBurstTime(Q:tqueue)
   I.S.: Q berisi elemen
   F.S.: antrian diurutkan berdasarkan Burst Time dari kecil ke besar */
void SortByBurstTime(tqueue *Q) {
    /*Kamus Lokal*/
    int i, j;
    for (i = (*Q).head; i < (*Q).tail; i++) {
        for (j = i + 1; j <= (*Q).tail; j++) {
            if (GetBurstTime((*Q).wadah[i]) > GetBurstTime((*Q).wadah[j])) {
                Proses temp = (*Q).wadah[i];
                (*Q).wadah[i] = (*Q).wadah[j];
                (*Q).wadah[j] = temp;
            }
        }
    }
}
