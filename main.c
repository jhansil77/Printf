#include "ft_printf.h"
#include <stdio.h>

int main() {
    int count1, count2;

    // Prueba básica
    count1 = ft_printf("Hola %s\n", "mundo");
    count2 = printf("Hola %s\n", "mundo");
    printf("Retorno: ft_printf=%d, printf=%d\n", count1, count2);

    // Prueba de punteros y números
    ft_printf("Hex: %x, Puntero: %p\n", 42, &count1);
    printf("Hex: %x, Puntero: %p\n", 42, &count1);

    // CASOS DE BORDE IMPORTANTES:
    ft_printf("Porcentaje: %%\n");
    ft_printf("Cero: %d\n", 0);
    ft_printf("Negativo: %d\n", -2147483648);
    ft_printf("Unsigned: %u\n", -1); // Debería imprimir el valor máximo de unsigned int
    return (0);
}