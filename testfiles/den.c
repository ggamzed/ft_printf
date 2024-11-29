#include <stdio.h>
#include <stdarg.h>

// Değişken sayıda parametre alacak bir fonksiyon
void print_numbers(int count, ...) {
    va_list args;  // Değişken sayıda parametreleri tutacak olan liste
    va_start(args, count);  // args'ı başlat, 'count' son sabit parametre

    char *a;
    a = va_arg(args, char *);
    printf("%s", a);

    int b;
    b = va_arg(args, int);
    printf("%d", b);

    va_end(args);  // args'ı temizle
}

int main() {
    // print_numbers fonksiyonuna 4 parametre gönderiyoruz
    print_numbers(4, "hello", );
    return 0;
}
