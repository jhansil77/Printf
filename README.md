# Printf - Implementación personalizada de printf en C

> **Nota:** Este proyecto fue creado como parte del currículo de 42 por jhansil77.

## Descripción del Proyecto

**Printf** es una implementación personalizada de la función estándar `printf()` de la librería C. El objetivo es replicar el comportamiento de la función original, permitiendo formatear y imprimir strings utilizando especificadores de formato como `%d`, `%s`, `%x`, `%p`, entre otros.

Este proyecto forma parte de la formación en programación en C y demuestra la comprensión de:
- Argumentos variables (`va_list`)
- Gestión de memoria
- Recursividad
- Conversión de datos
- Manejo de bases numéricas

### Objetivo General

Crear una función `ft_printf()` completamente funcional que replique el comportamiento de `printf()` estándar, soportando los especificadores de formato más comunes y devolviendo la cantidad de caracteres impresos.

---

## Instrucciones de Compilación e Instalación

### Requisitos Previos
- Compilador: `gcc` o `clang`
- Sistema: Linux/Unix/macOS
- Make (para compilación automática)
- Librería Libft (incluida como submódulo)

### Compilación

Para compilar el proyecto completo, usa el `Makefile`:

```bash
# Compilar la librería estática libftprintf.a
make

# Limpiar archivos objeto
make clean

# Limpiar todo (objetos + librería)
make fclean

# Recompilar desde cero
make re
```
## Características Implementadas

### Especificadores Soportados

| Especificador | Descripción | Ejemplo |
|---|---|---|
| `%c` | Carácter individual | `ft_printf("%c", 'A');` → `A` |
| `%s` | String | `ft_printf("%s", "Hola");` → `Hola` |
| `%d` | Número entero decimal (con signo) | `ft_printf("%d", 42);` → `42` |
| `%i` | Número entero decimal (con signo) | `ft_printf("%i", -15);` → `-15` |
| `%u` | Número entero sin signo | `ft_printf("%u", 4294967295);` → `4294967295` |
| `%x` | Número hexadecimal en minúsculas | `ft_printf("%x", 255);` → `ff` |
| `%X` | Número hexadecimal en mayúsculas | `ft_printf("%X", 255);` → `FF` |
| `%p` | Puntero (dirección de memoria) | `ft_printf("%p", ptr);` → `0x7fff5fbff8c0` |
| `%%` | Carácter de porcentaje | `ft_printf("100%%");` → `100%` |


---

## Estructura del Proyecto

```
Printf/
├── README.md                 # Este archivo
├── Makefile                  # Archivo de compilación
├── ft_printf.h              # Archivo de encabezado
├── ft_printf.c              # Función principal ft_printf
├── ft_putnbr_base.c         # Funciones de conversión de bases y output
├── main.c                   # Archivo de pruebas
└── Libft/                   # Librería personalizada (submódulo)
    ├── Makefile
    ├── libft.h
    └── ... (funciones auxiliares)
```

### Descripción de Archivos

- **ft_printf.h**: Encabezado que define la función `ft_printf()` y funciones auxiliares
- **ft_printf.c**: Contiene la función principal `ft_printf()` que procesa el string de formato y delega el output a funciones especializadas
- **ft_putnbr_base.c**: Implementa funciones para imprimir números en diferentes bases (decimal, hexadecimal, etc.) y manejo de caracteres/strings
- **main.c**: Archivo de pruebas que verifica que la implementación coincida con `printf()` estándar

---

## Recursos y Referencias

### Documentación Relacionada

1. **Manuales de Linux (`man`)**: 
   - Consulta directa en la terminal: `man printf`
   - Verifica el comportamiento exacto de los parámetros y especificaciones

2. **Documentación Online**:
   - [Documentación oficial de printf](https://man7.org/linux/man-pages/man3/printf.3.html)
   - [Cprogramming.com - Argumentos Variables](https://www.cprogramming.com/tutorial/c/lesson17.html)
   - [TutorialsPoint - Funciones de C](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm)

3. **Conceptos Clave a Estudiar**:
   - Conversión entre bases numéricas
   - Recursividad y manejo de pilas de llamadas
   - Trabajo con punteros y casting de tipos
   - Argumentos variables (`va_list`, `va_start`, `va_arg`, `va_end`)

### Especificación de Entrada/Salida

- **Entrada:** String de formato y argumentos variables
- **Salida:** String formateado impreso en stdout
- **Retorno:** Número de caracteres impresos (o -1 en caso de error)

### Uso de Libft

Este proyecto integra la librería `libft`, especificando para qué partes del proyecto se utiliza:
- **`ft_strlen()`**: Para calcular la longitud de strings
- **`ft_putchar_fd()`**: Para escribir caracteres individuales
- **`ft_putstr_fd()`**: Para escribir strings completos

Estas funciones se utilizan principalmente en la gestión de output y procesamiento de formatos.

---

## Decisiones Técnicas y Justificaciones

### Algoritmo de Conversión de Bases

Se utilizó una **aproximación recursiva** para convertir números a diferentes bases. Esta decisión se tomó porque:

- Simplifica la inversión del orden de dígitos
- Es más intuitiva y fácil de entender
- Reduce la necesidad de buffers intermedios
- Aprovecha la naturaleza recursiva del problema

```c
int ft_putnbr_base(long long nbr, char *base)
{
    // Procesa recursivamente cada dígito
    // Detiene la recursión cuando nbr < base_n
}
```

### Manejo de Argumentos Variables

Se utiliza `<stdarg.h>` para acceder a argumentos variables:
- **`va_start()`**: Inicializa el acceso a argumentos
- **`va_arg()`**: Extrae el siguiente argumento
- **`va_end()`**: Finaliza el acceso

Esta es la única forma estándar en C de manejar un número variable de argumentos.

### Estructura de Funciones Auxiliares

La implementación se divide en funciones especializadas para mantener el código limpio y reutilizable:

- **`ft_print_type()`**: Despacha a la función correcta según el especificador
- **`print_output()`**: Itera sobre el string de formato y coordina el procesamiento
- **`ft_putnbr_base()`**: Convierte números a cualquier base
- **`ft_print_char()`**: Maneja caracteres individuales
- **`ft_print_str()`**: Maneja strings
- **`ft_print_ptr()`**: Maneja punteros

---
