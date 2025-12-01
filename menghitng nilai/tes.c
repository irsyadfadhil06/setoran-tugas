#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk fungsi exit() jika ingin ditambahkan

// Fungsi untuk menentukan nilai huruf
void konversiNilaiHuruf(int nilaiAngka) {
    if (nilaiAngka >= 85 && nilaiAngka <= 100) {
        printf("Nilai Huruf Anda adalah: **A**\n");
    } else if (nilaiAngka >= 75 && nilaiAngka < 85) {
        printf("Nilai Huruf Anda adalah: **B**\n");
    } else if (nilaiAngka >= 65 && nilaiAngka < 75) {
        printf("Nilai Huruf Anda adalah: **C**\n");
    } else if (nilaiAngka >= 50 && nilaiAngka < 65) {
        printf("Nilai Huruf Anda adalah: **D**\n");
    } else if (nilaiAngka >= 0 && nilaiAngka < 50) {
        printf("Nilai Huruf Anda adalah: **E**\n");
    } else {
        printf("Error: Nilai **%d** di luar rentang valid (0-100).\n", nilaiAngka);
    }
}

int main() {
    int nilai;

    printf("========================================\n");
    printf("     KONVERSI ANGKA KE HURUF\n");
    printf("========================================\n");
    
    // Input nilai
    printf("Masukkan nilai angka (0-100): ");
    
    // Menggunakan scanf untuk mengambil input integer
    if (scanf("%d", &nilai) != 1) {
        printf("Input tidak valid. Harap masukkan angka.\n");
        // Membersihkan buffer input
        while (getchar() != '\n');
        return 1; // Keluar dengan kode error
    }

    printf("--- Hasil Konversi ---\n");
    // Memanggil fungsi konversi
    konversiNilaiHuruf(nilai);
    printf("----------------------\n");

    return 0;
}