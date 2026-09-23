#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    printf("--- Iniciando pruebas de ft_printf ---\n\n");

    // 1. Texto simple
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Hola Mundo\n");
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Hola Mundo\n");
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 2. Caracteres
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Test Char: %c\n", 'A');
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Test Char: %c\n", 'A');
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 3. Strings
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("String: %s\n", "42 School");
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("String: %s\n", "42 School");
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 4. NULL Strings (Caso importante en 42)
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("NULL: %s\n", (char *)NULL);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wformat-overflow"
# pragma GCC diagnostic ignored "-Wformat"
#endif
    ret2 = printf("NULL: %s\n", (char *)NULL);
#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic pop
#endif
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 5. Punteros
    int x = 42;
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Ptr: %p\n", &x);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Ptr: %p\n", &x);
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 6. NULL Punteros
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("NULL Ptr: %p\n", (void *)NULL);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("NULL Ptr: %p\n", (void *)NULL);
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 7. Enteros (Dec/Int)
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Ints: %d, %i\n", -42, 0);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Ints: %d, %i\n", -42, 0);
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 8. Límites de enteros
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Limites: %d, %d\n", INT_MAX, INT_MIN);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Limites: %d, %d\n", INT_MAX, INT_MIN);
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 9. Unsigned
    printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Unsigned: %u\n", 4294967295U);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Unsigned: %u\n", 4294967295U);
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 10. Hexadecimales
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Hex: %x, %X\n", 255, 255);
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Hex: %x, %X\n", 255, 255);
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // 11. Mixto y %
	printf("------MI FUNCION:------\n");
	fflush(stdout);
    ret1 = ft_printf("Mixto: %d test %c %s %%\n", 10, 'Z', "f");
	fflush(stdout);
	printf("------FUNCION ORIGINAL:------\n");
	fflush(stdout);
    ret2 = printf("Mixto: %d test %c %s %%\n", 10, 'Z', "f");
	fflush(stdout);
    printf("Retornos: ft_printf=%d, printf=%d\n\n", ret1, ret2);
    return (0);

}