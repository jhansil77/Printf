# Printf - Implementación personalizada de printf en C

> **Nota:** Este proyecto fue creado como parte del currículo de 42 por jhansil77.

## Descripción del Proyecto

`ft_printf` es una reimplementación personalizada de la función estándar `printf()` de la librería C (`stdio.h`). El objetivo principal es replicar el comportamiento de la función original, permitiendo formatear y mostrar en pantalla textos y variables mediante especificadores de formato.

Este proyecto forma parte de la formación en programación C de la Escuela 42 y demuestra el dominio de:
- Funciones con número variable de argumentos (`va_list`, `va_start`, `va_arg`, `va_end` de `<stdarg.h>`)
- Manejo de tipos de datos y conversión de bases numéricas (decimal, hexadecimal)
- Manejo de punteros y direcciones de memoria
- Uso de funciones auxiliares e integración con la librería `Libft`
- Gestión de salida estándar y conteo de caracteres impresos

---

## Características Implementadas

### Especificadores de Formato Soportados

| Especificador | Descripción | Ejemplo de Uso | Salida Esperada |
|---|---|---|---|
| `%c` | Imprime un solo carácter | `ft_printf("%c", 'A');` | `A` |
| `%s` | Imprime una cadena de caracteres (string) | `ft_printf("%s", "Hola 42");` | `Hola 42` |
| `%p` | Imprime la dirección de memoria de un puntero en hexadecimal con prefijo `0x` | `ft_printf("%p", ptr);` | `0x7ffeefbff5c0` |
| `%d` | Imprime un número entero decimal con signo | `ft_printf("%d", -42);` | `-42` |
| `%i` | Imprime un entero en base 10 con signo | `ft_printf("%i", 100);` | `100` |
| `%u` | Imprime un número entero decimal sin signo | `ft_printf("%u", 4294967295U);` | `4294967295` |
| `%x` | Imprime un número hexadecimal en minúsculas | `ft_printf("%x", 255);` | `ff` |
| `%X` | Imprime un número hexadecimal en mayúsculas | `ft_printf("%X", 255);` | `FF` |
| `%%` | Imprime el símbolo de porcentaje | `ft_printf("100%%");` | `100%` |

---

## Estructura del Proyecto

```text
ft_printf/
├── Makefile          # Reglas de compilación (all, clean, fclean, re)
├── ft_printf.h       # Archivo de cabecera con prototipos e includes
├── ft_printf.c       # Función principal ft_printf y lógica de procesado de formato
├── utils.c           # Funciones auxiliares para imprimir tipos, bases y punteros
├── main.c            # Programa de prueba con casos de test
└── Libft/            # Librería auxiliar de funciones estándar
```

### Descripción de Archivos

- **`ft_printf.h`**: Declara los prototipos de las funciones, incluye las librerías necesarias (`<stdarg.h>`, `<unistd.h>`) e integra `"Libft/libft.h"`.
- **`ft_printf.c`**:
  - `ft_printf()`: Punto de entrada, inicializa `va_list` y llama a `print_output()`.
  - `print_output()`: Recorre la cadena de formato, escribe caracteres ordinarios y delega especificadores (`%`) a `ft_print_type()`.
  - `ft_print_type()`: Evalúa el carácter especificador y ejecuta la función correspondiente de `utils.c`.
- **`utils.c`**:
  - `ft_print_char()`: Imprime un carácter individual.
  - `ft_print_str()`: Imprime una cadena de caracteres (maneja cadenas nulas imprimiendo `(null)`).
  - `ft_print_ptr()`: Imprime direcciones de memoria (maneja punteros nulos imprimiendo `(nil)`).
  - `ft_putnbr_base()`: Convierte e imprime números enteros con signo en cualquier base recursivamente.
  - `ft_putnbr_base_ul()`: Convierte e imprime enteros sin signo (`unsigned long`) para direcciones de memoria.

---

## Instrucciones de Compilación y Uso

### Requisitos Previos
- Compilador: `cc`, `gcc` o `clang`
- Herramienta: `make`
- Sistema operativo: Linux / macOS / Unix

### Comandos de Compilación

Para generar la librería estática `libftprintf.a`:

```bash
make
```

Otros comandos del `Makefile`:

```bash
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los archivos objeto y libftprintf.a
make re       # Recompila el proyecto desde cero
```

### Ejemplo de Uso en C

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hola %s! El número es %d y en hex es %x.\n", "Mundo", 42, 42);
    ft_printf("Caracteres impresos: %d\n", len);
    return (0);
}
```

Para compilar tu programa enlazando con la librería:

```bash
cc main.c libftprintf.a -I. -ILibft -o mi_programa
./mi_programa
```

---

## Casos Especiales Manejados

1. **Cadenas Nulas (`%s`)**: Si se pasa `NULL` a `%s`, se imprime `(null)` y devuelve `6`.
2. **Punteros Nulos (`%p`)**: Si se pasa `NULL` a `%p`, se imprime `(nil)` y devuelve `5`.
3. **Porcentaje (`%%`)**: Imprime un único carácter `%`.
4. **Límites de Tipos**: Procesa de forma correcta los valores límites como `INT_MIN`, `INT_MAX` y enteros sin signo de 32 bits (`UINT_MAX`).
