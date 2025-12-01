// main_nilai.c (Controller + Implementasi Model & View)
#include <stdio.h>
#include "model.h"
#include "view.h"

// =================================================================
// Implementasi Model (Logika Penentuan Nilai)
// =================================================================

char tentukanNilaiHuruf(int nilaiAngka) {
    if (nilaiAngka >= 85 && nilaiAngka <= 100) {
        return 'A';
    } else if (nilaiAngka >= 75 && nilaiAngka < 85) {
        return 'B';
    } else if (nilaiAngka >= 65 && nilaiAngka < 75) {
        return 'C';
    } else if (nilaiAngka >= 50 && nilaiAngka < 65) {
        return 'D';
    } else if (nilaiAngka >= 0 && nilaiAngka < 50) {
        return 'E';
    } else {
        // Mengembalikan 'X' untuk menandakan nilai di luar rentang valid
        return 'X'; 
    }
}

// =================================================================
// Implementasi View (Tampilan Output)
// =================================================================

void tampilkanHeader() {
    printf("========================================\n");
    printf("     PROGRAM KONVERSI NILAI ANGKA KE HURUF\n");
    printf("               (STRUKTUR MVC C)\n");
    printf("========================================\n");
    printf("Kriteria Nilai:\n");
    printf("A: 85-100 | B: 75-84 | C: 65-74 | D: 50-64 | E: 0-49\n");
    printf("----------------------------------------\n");
    printf("Masukkan nilai angka (0-100) atau 00 untuk keluar: ");
}

void tampilkanHasil(int nilaiAngka, char nilaiHuruf) {
    printf("\n--- Hasil Konversi ---\n");
    printf("Nilai Angka: %d\n", nilaiAngka);
    printf("Nilai Huruf Anda adalah: **%c**\n", nilaiHuruf);
    printf("----------------------\n");
}

void tampilkanPesanError(const char *pesan) {
    printf("\n[ERROR] %s\n", pesan);
}

// =================================================================
// Controller (Logika Utama Program)
// =================================================================

int main() {
    int nilai;
    char hasilHuruf;

    do {
        tampilkanHeader(); // Panggil View
        
        // Mengambil input dan memeriksa validitas
        if (scanf("%d", &nilai) != 1) {
            tampilkanPesanError("Input tidak valid. Harap masukkan angka.");
            // Membersihkan buffer input
            while (getchar() != '\n'); 
            continue;
        }

        if (nilai == 00) {
            printf("\nProgram selesai. Terima kasih.\n");
            break;
        }

        // 1. Panggil Model
        hasilHuruf = tentukanNilaiHuruf(nilai);

        // 2. Controller memutuskan apa yang harus ditampilkan berdasarkan hasil Model
        if (hasilHuruf != 'X') {
            tampilkanHasil(nilai, hasilHuruf); // Panggil View untuk hasil sukses
        } else {
            tampilkanPesanError("Nilai di luar rentang valid (0-100)."); // Panggil View untuk error
        }

    } while (nilai != 00);

    return 0;
}