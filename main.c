#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    printf("--- Iniciando pruebas de ft_printf ---\n\n");

    // 1. Texto simple
	printf("------MI FUNCION:------\n");
    ret1 = ft_printf("Hola Mundo\n");
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Hola Mundo\n");
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 2. Caracteres
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Test Char: %c\n", 'A');
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Test Char: %c\n", 'A');
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 3. Strings
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("String: %s\n", "42 School");
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("String: %s\n", "42 School");
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 4. NULL Strings (Caso importante en 42)
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("NULL: %s\n", (char *)NULL);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("NULL: %s\n", (char *)NULL);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 5. Punteros
    int x = 42;
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Ptr: %p\n", &x);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Ptr: %p\n", &x);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 6. NULL Punteros
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("NULL Ptr: %p\n", (void *)NULL);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("NULL Ptr: %p\n", (void *)NULL);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 7. Enteros (Dec/Int)
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Ints: %d, %i\n", -42, 0);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Ints: %d, %i\n", -42, 0);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 8. Límites de enteros
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Limites: %d, %d\n", INT_MAX, INT_MIN);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Limites: %d, %d\n", INT_MAX, INT_MIN);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 9. Unsigned
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Unsigned: %u\n", 4294967295U);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Unsigned: %u\n", 4294967295U);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 10. Hexadecimales
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Hex: %x, %X\n", 255, 255);
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Hex: %x, %X\n", 255, 255);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 11. Mixto y %
	printf("------MI ORIGINAL:------\n");
    ret1 = ft_printf("Mixto: %d test %c %s %%\n", 10, 'Z', "f");
	printf("------FUNCION ORIGINAL:------\n");
    ret2 = printf("Mixto: %d test %c %s %%\n", 10, 'Z', "f");
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);
    return (0);

}