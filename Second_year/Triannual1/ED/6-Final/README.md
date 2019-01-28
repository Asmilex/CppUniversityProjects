# Scrabble: guía de uso

## Disclaimer

- **Está pensado para usarse UTF8**
- Probado con `g++ 8.2.1` y `clang++ 7.0.1`.
- Las líneas de diseño seguidas se recogen en [Kary Coding Standards](https://kcs.library.kary.us/).

## Vistazo general

La estructura del proyecto es la siguiente:

```txt
├── bin
├── doc
│  ├── Doxyfile
│  ├── html
│  └── latex
├── files
│  ├── diccionario1.txt
│  ├── diccionario2.txt
│  ├── diccionario500.txt
│  ├── diccionario1000.txt
│  └── listado-general.txt
├── include
│  ├── diccionario.h
│  └── letras.h
├── Makefile
├── obj
├── README.md
└── src
   ├── cantidad_letras.cpp
   ├── diccionario.cpp
   ├── letras.cpp
   ├── testdiccionario.cpp
   └── testletras.cpp
```

- En `files`, se recogen los diferentes diccionarios. Los 4 primeros son proporcionados por el departamento. El siguiente es un listado con $80000$ palabras del español. Es un caso extremo
- `src` contiene lo siguiente:
    - 3 programas principales: `cantidad_letras`, `testdiccionario` y `testletras`. Cada uno tiene su respectivo main
    - `cantidad_letras` neceista que `testletras` sea ejecutado antes
    - `diccionario.cpp` y `letras.cpp` recoge las implementaciones de las respectivas cabeceras

## Diccionario

El diseño es muy similar al propuesto en el guión. Sin embargo, se ha cambiado el nombre de los métodos al inglés. En general, sus palabras son más cortas e identificables. Estandariza nomenclaturas como `size()`.
La implementación es muy sencilla y no hay demasiado que comentar.

## Letras

### Overview

Esta está ideada de manera diferente a la propuesta. Inspeccionemos la parte privada:

```c++
Diccionario diccionario;
    
list < char > lista_letras      = {0};
unsigned int  puntuaciones [26] = {0};  // NOTE ordenadas de A - Z. Sin Ñ
unsigned int  frecuencia   [26] = {0};

static const unsigned int default_random_letters = 0;
```

`Diccionario diccionario`: lista de palabras disponibles. Se usará a la hora de calcular frecuencias, puntuaciones (a no ser que estén especificadas), búsqueda de palabras o formaciones.

Dado que sabemos de antemano qué letras aparecerán, nos ahorramos la creación de módulos pequeños a favor de **dos arrays sencillos**: `puntuaciones` y `frecuencia`. Una vez se carga un diccionario, se calculan los respectivos parámetros, y se almacenan en ellos los valores. Dado que el conjunto de letras a usar es conocido, los accesos a memoria serán directos. Nos evitaremos hacer búsquedas.

El diseño propuesto estaba ideado para usar `set< Letras >`. A rasgos generales, el efecto es el mismo. `set` es más seguro usarlo, pero no hay necesidad si se controlan bien los índices. En particular, se hubiera usado las `.find()` y el hecho de que no se pueden repetir letras. Para mí, no hay necesidad de ello.

`list < char > lista_letras` recoge la cantidad de letras generadas aleatoriamente. Puede ser modificado en la propia creación del objeto o durante su vida.

Usamos `static const unsigned int default_random_letters = 0;` para indicar que generamos 0 letras por defecto. Es decir, a no ser que se especifique lo contrario, no necesitaremos generarlas. Este no deja de ser un valor por defecto y puede ser sobreescrito en cualquier momento, durante la vida del objeto

### Constructores

Los constructores juegan un papel fundamental aquí

```c++
Bolsa_Letras (    const Diccionario  dic
              ,   const unsigned int num_letras = default_random_letters );

Bolsa_Letras (    const Diccionario  dic
              ,   const unsigned int score[26]
              ,   const unsigned int frec[26] 
              ,   const unsigned int num_letras = default_random_letters );

Bolsa_Letras (    const Diccionario dic
              ,   const string      file
              ,   const int         n = default_random_letters );

Bolsa_Letras ( const Bolsa_Letras& otro );
```



El más básico especifica un diccionario y se calculan las frecuencias y las puntuaciones a partir de sus palabras. Además, puede generar letras.
También es posible indicar directamente las frecuencias y las puntuaciones, para aligerar la carga de trabajo.
La siguiente posibilidad es indicar el diccionario y un archivo. Este archivo corresponde al punto $3.2.2$ del guión. A efectos prácticos, es una variación de la opción anterior
El último es un constructor de copia

### Funciones destacables

Si no viene comentado aquí, es porque no hay mucho que destacar de ellas. De todas formas, el doxygen es funcional y describe bien el uso de todas.

Las funciones más interesantes son las siguientes:

```c++
void generate_random_letters ( const int numero );
list< string > search_longest_words ( const unsigned int longitud ) const;
list< string > search_rarest_words () const;
bool can_be_formed ( const string palabra ) const;
```

#### can_be_formed()

Se supone que la lista de letras generadas aleatoriamente no está vacía

###### El comentario es clave:

> Para cada letra de la lista de letras, el número de ocurrencias en la alabra debe ser menor o igual que las veces que está presente en la lista

Por tanto, usamos una lambda para comprobar si una letra está en la lista. Si todas lo están, por tanto, existe la posibilidad de que pueda ser formada. Existe, dado que debemos comprobar que la cantidad de veces que aparece una letra en la palabra **no debe superar** a las que aparece en la lista. Si la lista es `C A S`, no se puede formar *casa*.
Nótese el uso de C++ moderno. Simplifica mucho el diseño y mejora la legibilidad. Uno de mis fundamentos a la hora de programa es hacer el código lo más sencillo y legible (ver Kary Coding Standard)

#### generate_random_letters ()

Recogido en un comentario:

Supongamos que tenemos la siguiente distribución de letras:
​    $$A: x_0, B: x_1, ..., Z: x_{26}$$

Se puede interpetrar como 
​    $$A, A, ...^{\times x_0}, A, B, ... ^{\times x_1}, B, ... ...,Y ,Z, ...^{\times x_{26}}, Z$$

Entonces, generamos un número aleatorio con una seed entre $[x_0, \sum_{i=0}^{26}{x_i}]$. Cuando 
​    $$\sum_{i=0}^{N}{x_i} \leq n < \sum_{i=0}^{M}{x_i}$$
Sabemos que la letra generada es la correspondiente a $N+65$. El 65 viene de trasladar el intervalo $[0, 26]$ a $[65, 91]$, correspondientes a su valor en ASCII.

#### seach_longest_words y search_rarest_words

Su funcionamiento es muy similar. Recorren las palabras del diccionario buscando los requisitos, de mayor a menor (para sacar las más valiosas en una iteración)

## Programas

### testdiccionario

Recibe el fichero con el diccionario y enseña que la clase funciona. No tiene mucho misterio. Es el mismo que proporciona el guión

### testletras

Este es el programa que más chicha. Incluye los modos de juego por puntuación y por longitud. 

Parámetros: `./testletras diccionario letras num_letras {L/P}`

- `diccionario` es el diccionario a cargar
- `letras` el fichero en el que guardar lo resultados
- `num_letras` las letras a generar
- `{L/P}` la modalidad. L para longitud, P para puntuación

### cantidad_letras

Requiere el fichero letras generado en el programa anterior

Cargas las frecuencias de dicho fichero y devuelve otro con la frecuencia absoluta y relativa

