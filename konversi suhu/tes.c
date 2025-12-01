#include <stdio.h>

// Fungsi Konversi
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
    // Rumus: K = (F - 32) * 5/9 + 273.15
    // Lebih mudah: K = C + 273.15, di mana C adalah hasil fahrenheit_to_celcius(f)
    double c = fahrenheit_to_celcius(f);
    return celcius_to_kelvin(c);
}

double kelvin_to_celcius(double k) {
    // Rumus: C = K - 273.15
    return k - 273.15;
}

double kelvin_to_fahrenheit(double k) {
    // Rumus: F = (K - 273.15) * 9/5 + 32
    // Lebih mudah: F = C * 9/5 + 32, di mana C adalah hasil kelvin_to_celcius(k)
    double c = kelvin_to_celcius(k);
    return celcius_to_fahrenheit(c);
}

void tampilkanMenu() {
    printf("\n=====================================\n");
    printf("     MENGHITUNG KONVERSI SUHU\n");
    printf("=====================================\n");
    printf("Pilih Jenis Konversi:\n");
    printf("1. Celcius -> Fahrenheit dan Kelvin\n");
    printf("2. Fahrenheit -> Celcius dan Kelvin\n");
    printf("3. Kelvin -> Celcius dan Fahrenheit\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan (1-4): ");
}

int main() {
    int pilihan;
    double suhu_input, hasil1, hasil2;

    do {
        tampilkanMenu();
        // Menggunakan scanf untuk mengambil input integer (pilihan)
        if (scanf("%d", &pilihan) != 1) {
            printf("\nInput tidak valid. Harap masukkan angka.\n");
            // Membersihkan buffer input
            while (getchar() != '\n'); 
            continue;
        }

        if (pilihan >= 1 && pilihan <= 3) {
            printf("Masukkan nilai suhu: ");
            // Menggunakan %lf untuk double
            if (scanf("%lf", &suhu_input) != 1) {
                printf("Input suhu tidak valid.\n");
                while (getchar() != '\n'); 
                continue;
            }
        }

        switch (pilihan) {
            case 1:
                printf("\n--- CELCIUS (%.2lf °C) ---\n", suhu_input);
                hasil1 = celcius_to_fahrenheit(suhu_input);
                hasil2 = celcius_to_kelvin(suhu_input);
                printf("Hasil ke Fahrenheit: **%.2lf °F**\n", hasil1);
                printf("Hasil ke Kelvin: **%.2lf K**\n", hasil2);
                break;

            case 2:
                printf("\n--- FAHRENHEIT (%.2lf °F) ---\n", suhu_input);
                hasil1 = fahrenheit_to_celcius(suhu_input);
                hasil2 = fahrenheit_to_kelvin(suhu_input);
                printf("Hasil ke Celcius: **%.2lf °C**\n", hasil1);
                printf("Hasil ke Kelvin: **%.2lf K**\n", hasil2);
                break;

            case 3:
                printf("\n--- KELVIN (%.2lf K) ---\n", suhu_input);
                hasil1 = kelvin_to_celcius(suhu_input);
                hasil2 = kelvin_to_fahrenheit(suhu_input);
                printf("Hasil ke Celcius: **%.2lf °C**\n", hasil1);
                printf("Hasil ke Fahrenheit: **%.2lf °F**\n", hasil2);
                break;

            case 4:
                printf("\nTerima kasih, program selesai.\n");
                break;

            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
        
    } while (pilihan != 4);

    return 0;
}