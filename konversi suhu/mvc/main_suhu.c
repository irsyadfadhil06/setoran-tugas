// main_suhu.c (Controller + Implementasi Model & View)
#include <stdio.h>
#include "model_suhu.h"
#include "view_suhu.h"

// =================================================================
// Implementasi Model (Logika Perhitungan)
// =================================================================

double celcius_to_fahrenheit(double c) {
    // Rumus: F = C * 9/5 + 32
    return (c * 9.0 / 5.0) + 32.0;
}

double celcius_to_kelvin(double c) {
    // Rumus: K = C + 273.15
    return c + 273.15;
}

double fahrenheit_to_celcius(double f) {
    // Rumus: C = (F - 32) * 5/9
    return (f - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double f) {
    // Konversi F -> C -> K
    double c = fahrenheit_to_celcius(f);
    return celcius_to_kelvin(c);
}

double kelvin_to_celcius(double k) {
    // Rumus: C = K - 273.15
    return k - 273.15;
}

double kelvin_to_fahrenheit(double k) {
    // Konversi K -> C -> F
    double c = kelvin_to_celcius(k);
    return celcius_to_fahrenheit(c);
}

// =================================================================
// Implementasi View (Tampilan Output)
// =================================================================

void tampilkanMenu() {
    printf("\n=====================================\n");
    printf("     PROGRAM KONVERSI SUHU (MVC C)\n");
    printf("=====================================\n");
    printf("Pilih Jenis Konversi:\n");
    printf("1. Celcius -> Fahrenheit dan Kelvin\n");
    printf("2. Fahrenheit -> Celcius dan Kelvin\n");
    printf("3. Kelvin -> Celcius dan Fahrenheit\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan (1-4): ");
}

void tampilkanHasilKonversi(double input, const char *satuanAsal, double hasil1, const char *satuan1, double hasil2, const char *satuan2) {
    printf("\n--- %s (%.2lf) ---\n", satuanAsal, input);
    printf("Hasil ke %s: **%.2lf**\n", satuan1, hasil1);
    printf("Hasil ke %s: **%.2lf**\n", satuan2, hasil2);
}

void tampilkanPesanError(const char *pesan) {
    printf("\n[ERROR] %s\n", pesan);
}

// =================================================================
// Controller (Logika Utama Program)
// =================================================================

int main() {
    int pilihan;
    double suhu_input;

    do {
        tampilkanMenu(); // Panggil View
        
        if (scanf("%d", &pilihan) != 1) {
            tampilkanPesanError("Input tidak valid. Harap masukkan angka.");
            while (getchar() != '\n'); 
            continue;
        }

        if (pilihan >= 1 && pilihan <= 3) {
            printf("Masukkan nilai suhu: ");
            if (scanf("%lf", &suhu_input) != 1) {
                tampilkanPesanError("Input suhu tidak valid.");
                while (getchar() != '\n'); 
                continue;
            }
        }

        // Panggil Model dan View berdasarkan Pilihan
        switch (pilihan) {
            case 1:
                tampilkanHasilKonversi(
                    suhu_input, "CELCIUS",
                    celcius_to_fahrenheit(suhu_input), "Fahrenheit (°F)", // Panggil Model
                    celcius_to_kelvin(suhu_input), "Kelvin (K)"         // Panggil Model
                );
                break;

            case 2:
                tampilkanHasilKonversi(
                    suhu_input, "FAHRENHEIT",
                    fahrenheit_to_celcius(suhu_input), "Celcius (°C)",
                    fahrenheit_to_kelvin(suhu_input), "Kelvin (K)"
                );
                break;

            case 3:
                tampilkanHasilKonversi(
                    suhu_input, "KELVIN",
                    kelvin_to_celcius(suhu_input), "Celcius (°C)",
                    kelvin_to_fahrenheit(suhu_input), "Fahrenheit (°F)"
                );
                break;

            case 4:
                printf("\nTerima kasih, program selesai.\n");
                break;

            default:
                tampilkanPesanError("Pilihan tidak valid. Silakan coba lagi.");
                break;
        }
        
    } while (pilihan != 4);

    return 0;
}