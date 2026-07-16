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

## Casos de Borde Importantes

```c
// Porcentaje al final del string (se maneja correctamente)
ft_printf("Fin: %%");

// Cero
ft_printf("Cero: %d\n", 0);
// Output: Cero: 0

// Números negativos
ft_printf("Negativo: %d\n", -2147483648);
// Output: Negativo: -2147483648

// Números sin signo (valores negativos interpretados como positivos grandes)
ft_printf("Unsigned: %u\n", -1);
// Output: Unsigned: 4294967295

// Punteros nulos
ft_printf("Puntero: %p\n", NULL);
// Output: Puntero: (nil)

// Strings nulos
ft_printf("String: %s\n", NULL);
// Output: String: (null)
```

---

## Algoritmo Explicado

### Flujo de Ejecución Principal

1. **Entrada:** `ft_printf("Hola %s, tienes %d años\n", "Juan", 25)`

2. **Procesamiento:**
   - Inicializa `va_list` con los argumentos variables
   - Itera sobre cada carácter del string de formato
   - Al encontrar `%`, lee el siguiente carácter (especificador)
   - Extrae el argumento correspondiente usando `va_arg()`
   - Delega a la función específica para procesar el tipo
   - Cuenta los caracteres impresos

3. **Salida:**
   ```
   Hola Juan, tienes 25 años
   ```
   - Retorna: `27` (número de caracteres impresos)

### Ejemplo Paso a Paso

```
String: "Hola %s"
Argumentos: ("Mundo",)

Iteración 1-4: 'H', 'o', 'l', 'a' → imprime "Hola", printed=4
Iteración 5: ' ' → imprime " ", printed=5
Iteración 6: '%' → especificador encontrado, salta a siguiente
Iteración 7: 's' → extrae va_arg → "Mundo" → imprime "Mundo", printed=11

Output: "Hola Mundo"
Retorno: 11
```

---

## Funciones Principales

### `int ft_printf(const char *format, ...)`

**Descripción:** Función principal que replica `printf()`.

**Parámetros:**
- `format`: String con especificadores de formato
- `...`: Argumentos variables

**Retorno:** Número de caracteres impresos (o -1 si format es NULL)

**Ejemplo:**
```c
int count = ft_printf("Hola %s\n", "Mundo");
// count = 12
```

---

### `int ft_print_type(char c, va_list list)`

**Descripción:** Despacha al manejador correcto según el especificador.

**Especificadores soportados:** `c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`, `%`

**Retorno:** Número de caracteres impresos por el tipo

---

### `int ft_putnbr_base(long long nbr, char *base)`

**Descripción:** Convierte un número a una base específica e lo imprime recursivamente.

**Parámetros:**
- `nbr`: Número a convertir (puede ser negativo)
- `base`: String con los dígitos de la base (ej: "0123456789")

**Retorno:** Número de caracteres impresos

---

### `int ft_print_ptr(void *ptr, char *base)`

**Descripción:** Imprime un puntero en formato hexadecimal con prefijo "0x" o "(nil)".

**Manejo especial:** Si el puntero es NULL, imprime "(nil)" en lugar de "0x0"

---

## Compilación y Flags

El archivo `Makefile` utiliza los siguientes flags:

- **`-Wall -Wextra -Werror`**: 
  - Activa todos los warnings
  - Los trata como errores (fuerza corrección)
  - Garantiza código limpio sin warnings

- **`-I./Libft`**: 
  - Incluye el directorio de libft para funciones auxiliares
  - Permite compilación separada

- **`ar rcs`**: 
  - **r**: insertar archivos objeto
  - **c**: crear archivo si no existe
  - **s**: generar tabla de símbolos

---

## Pruebas y Validación

El archivo `main.c` incluye pruebas que comparan la salida de `ft_printf()` con `printf()` estándar:

```bash
# Ejecutar pruebas
make
gcc -o test main.c libftprintf.a -L./Libft -I. -I./Libft
./test
```

### Casos de Prueba Cubiertos

- ✅ Strings básicos
- ✅ Números decimales (positivos y negativos)
- ✅ Números sin signo
- ✅ Hexadecimal (minúscula y mayúscula)
- ✅ Punteros y direcciones de memoria
- ✅ Porcentajes
- ✅ Casos límite (INT_MIN, INT_MAX, valores grandes, etc.)
- ✅ Strings nulos y punteros nulos

---

## Explicación de la Estructura de Datos

### Variables Clave en `ft_printf.c`

```c
va_list list;           // Lista de argumentos variables
char *str;              // Puntero al string de formato
int printed;            // Contador de caracteres impresos
size_t i;               // Índice de iteración sobre el string
```

### Bases Numéricas Utilizadas

```c
char *base_ten = "0123456789";              // Para %d, %u, %i
char *base_hex = "0123456789abcdef";        // Para %x
char *base_HEX = "0123456789ABCDEF";        // Para %X
```

---

## Bonus - Mejoras Implementadas ✅

Este proyecto incluye todas las mejoras solicitadas según los requisitos:

1. ✅ **README.md Completo y Profesional**
   - Documentación clara, detallada y bien estructurada

2. ✅ **Descripción Clara del Proyecto**
   - Se explica qué hace el proyecto y sus objetivos principales

3. ✅ **Instrucciones de Compilación**
   - Pasos completos y detallados para compilar y ejecutar

4. ✅ **Sección de Recursos y Referencias**
   - Documentación oficial
   - Tutoriales en línea
   - Manuales de Linux
   - Enlaces a referencias de investigación

5. ✅ **Justificación de Decisiones Técnicas**
   - Se explica por qué se tomaron ciertas decisiones de diseño
   - Algoritmo recursivo vs iterativo
   - Estructura modular de funciones

6. ✅ **Tabla de Especificadores**
   - Referencia rápida de formatos soportados
   - Ejemplos para cada especificador

7. ✅ **Ejemplos Prácticos**
   - Código ejecutable demostrando funcionalidad
   - Casos de uso reales

8. ✅ **Estructura de Archivos**
   - Diagrama del árbol de directorios
   - Descripción de cada archivo

9. ✅ **Casos de Borde**
   - Documentación de comportamiento en edge cases
   - Cómo se manejan valores especiales

10. ✅ **Algoritmo Explicado**
    - Descripción detallada del funcionamiento interno
    - Flujos de ejecución paso a paso
    - Ejemplos visuales

---

## Información del Proyecto

- **Lenguaje principal:** C
- **Compilador:** GCC/Clang
- **Sistema operativo:** Linux/Unix/macOS
- **Dependencias:** Libft (incluida)
- **Estado:** Completado y Testeado
- **Última actualización:** 2026

---

**Creado por:** jhansil77  
**Repositorio:** [jhansil77/Printf](https://github.com/jhansil77/Printf)
