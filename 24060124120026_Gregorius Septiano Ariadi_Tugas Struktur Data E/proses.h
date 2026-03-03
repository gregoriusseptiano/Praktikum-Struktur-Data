#ifndef PROSES_H
#define PROSES_H
#include "boolean.h"

/* File      : proses.h */
/* Deskripsi : ADT Proses dan ADT Queue digunakan untuk mensimulasikan penjadwalan proses CPU 
               dengan algoritma SJF (Shortest Job First).
               Struktur data direpresentasikan secara kontigu menggunakan array dengan indeks 
               dimulai dari 1.
               Queue menyimpan elemen bertipe Proses, yang terdiri atas IDProses dan Burst Time. */
/* NIM/Nama  : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal   : Jumat, 10 Oktober 2025 */
/***********************************************/

/* type Proses = < IdProses: character, BurstTime: integer > */
typedef struct {
    char IdProses;
    int burstTime;
} Proses;

/* type tqueue = < wadah: array [1..5] of Proses, head: integer, tail: integer >
   {cara akses: Q:tqueue, Q.head = head(Q), Q.tail = tail(Q)} */
#define MAX 6
typedef struct {
    Proses wadah[MAX];
    int head;
    int tail;
} tqueue;

/* KONSTRUKTOR */
/*procedure makeProses (output P: Proses, input x: character, y:integer) 
{I.S.: -}
{F.S.: P terdefinisi, kosong}
{Proses: mengisi nilai IdProses dengan x dan BurstTime dengan y} */
void MakeProses(Proses *P, char x, int y);

/* Mutator */
/* Procedure SetIDProses(input/output P:Proses, input x:character)
{ I.S.: P terdefinisi, x terdefinisi }
{ F.S.: nilai id pada Proses P berubah sesuai parameter x }
{ Proses: mengganti IDProses dari Proses } */
void SetIDProses(Proses *P, char x);

/* Procedure SetBurstTime(input/output P:Proses, input y:integer)
{ I.S.: P terdefinisi, y terdefinisi }
{ F.S.: nilai burstTime pada Proses P berubah sesuai parameter y }
{ Proses: mengganti Burst Time dari Proses } */
void SetBurstTime(Proses *P, int y);

/* SELEKTOR */
/*function GetIDProses(P: Proses) -> character 
{mengembalikan nilai komponen IdProses P} */
char GetIDProses(Proses P);

/*function GetBurstTime(P: Proses) -> integer 
{mengembalikan nilai komponen BurstTime P} */
int GetBurstTime(Proses P);

/*function Head(Q:tqueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
#define head(Q) (Q).head 

/*function Tail(Q:tqueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
#define tail(Q) (Q).tail

/*procedure CreateQueue (output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi IdProses = '-' dan BursTime = -999, head=tail=0 } */ 
void CreateQueue(tqueue *Q);

/* Function IsEmptyQueue(Q:tqueue) -> boolean
   Mengembalikan true jika Queue kosong */
boolean IsEmptyQueue(tqueue Q);

/* Function IsFullQueue(Q:tqueue) -> boolean
   Mengembalikan true jika Queue penuh */
boolean IsFullQueue(tqueue Q);

/* Procedure Enqueue(Q:tqueue, P:Proses)
   I.S.: Q dan P terdefinisi
   F.S.: elemen P ditambahkan ke antrian jika belum penuh */
void Enqueue(tqueue *Q, Proses P);

/* procedure Dequeue(input/output Q:tqueue)
   I.S.: Q terdefinisi, mungkin kosong
   F.S.: jika tidak kosong, mengeluarkan elemen pertama (head)
         dan menggeser elemen lainnya */
Proses Dequeue(tqueue *Q);

/* Procedure PrintQueue(Q:tqueue)
   I.S.: Q terdefinisi
   F.S.: menampilkan seluruh elemen antrian ke layar */
void PrintQueue(tqueue Q);

/* Procedure SortByBurstTime(Q:tqueue)
   I.S.: Q berisi elemen
   F.S.: antrian diurutkan berdasarkan Burst Time dari kecil ke besar */
void SortByBurstTime(tqueue *Q);

#endif
