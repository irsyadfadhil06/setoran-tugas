// model_kendaraan.h
#ifndef MODEL_KENDARAAN_H
#define MODEL_KENDARAAN_H

#include <string.h>
#include <stdio.h>

// Deklarasi fungsi tampilan (simulasi method/virtual function)
typedef void (*TampilkanInfoFunc)(void*);

// Struktur dasar Kendaraan (Parent Class)
typedef struct {
    char merek[50];
    char model[50];
    int jumlahRoda;
    TampilkanInfoFunc tampilkanInfo; 
} Kendaraan;

// Struktur Roda Dua (Child Class)
typedef struct {
    Kendaraan super; 
    char tipe[50];   
} RodaDua;

// Struktur Roda Empat (Child Class)
typedef struct {
    Kendaraan super; 
    char segmen[50]; 
} RodaEmpat;

// Struktur Roda Enam (Child Class)
typedef struct {
    Kendaraan super; 
    char fungsi[50]; 
} RodaEnam;


// Deklarasi Constructor (Fungsi inisialisasi)
void init_Kendaraan(Kendaraan* k, const char* merek, const char* model, int roda, TampilkanInfoFunc info_func);
void init_RodaDua(RodaDua* rd, const char* merek, const char* model, const char* tipe);
void init_RodaEmpat(RodaEmpat* re, const char* merek, const char* model, const char* segmen);
void init_RodaEnam(RodaEnam* re, const char* merek, const char* model, const char* fungsi);

// Deklarasi Method (Fungsi tampilan spesifik, akan diimplementasikan di Controller)
void tampilkanInfo_RodaDua(void* obj);
void tampilkanInfo_RodaEmpat(void* obj);
void tampilkanInfo_RodaEnam(void* obj);

#endif