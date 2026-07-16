# Printf - Implementación personalizada de printf en C

> **Nota:** Este proyecto fue creado como parte del currículo de 42 por jhannsil.

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
