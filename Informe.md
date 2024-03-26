# C++ y la metaprogramación
### 1 Implemente utilizando **TMP** (_Template Metaprogramming_) de `C++`:
- Un algoritmo que calcule en tiempo de **COMPILACIÓN** el n-ésimo valor de la secuencia de _Fibonnacci_.
Ver TPM_Fibonacci.cpp
- Implemente un `template` que permite desenrollar (_unroll_) una expresión `for` de manera que se genere código secuencial que simule la ejecución de esta expresión.
Ver TPM_Unroll_Basic.cpp y TPM_Unroll_Fn.cpp

### 2 ¿Cómo surge la meta-programación utilizando `templates`?

La metaprogramación en C++ utilizando templates surgió de manera bastante inesperada. Durante el proceso de estandarización de C++, los desarrolladores descubrieron que el sistema de plantillas era en realidad una máquina de Turing completa. Erwin Unruh fue el primero en demostrar la metaprogramación de plantillas en una reunión del comité al ordenar al compilador que imprimiera números primos en mensajes de error. La metaprogramación con templates en C++ permite a los programadores generar código en tiempo de compilación, lo que puede resultar en programas más eficientes. Esto se logra utilizando plantillas para crear constantes, funciones o estructuras de datos en tiempo de compilación.  Los cálculos se realizan una vez en tiempo de compilación en lugar de en cada tiempo de ejecución. 

### 3 Explique el principio **SFINAE** de `C++`.
SFINAE, que significa “Substitution Failure Is Not An Error” (El fallo de sustitución no es un error), es un principio en C++ donde una sustitución inválida de parámetros de plantilla no es en sí misma un error. Cuando se crean candidatos para la resolución de sobrecarga, algunos (o todos) los candidatos de ese conjunto pueden ser el resultado de plantillas instanciadas con argumentos de plantilla (potencialmente deducidos) sustituidos por los parámetros de plantilla correspondientes. Si ocurre un error durante la sustitución de un conjunto de argumentos para cualquier plantilla dada, el compilador elimina la sobrecarga potencial del conjunto de candidatos en lugar de detenerse con un error de compilación, siempre que el error de sustitución sea uno de los que el estándar C++ otorga tal tratamiento.

Por ejemplo, SFINAE puede usarse para determinar si un tipo contiene un cierto typedef1. También se puede encontrar uno de los usos principales de SFINAE a través de las expresiones enable_if. enable_if es un conjunto de herramientas, disponibles en la Biblioteca Estándar desde C++11, que internamente usan SFINAE. Permiten incluir o excluir sobrecargas de posibles plantillas de función o especialización de plantillas de clase

``` cpp
struct Test { typedef int foo; };

template <typename T>
void f(typename T::foo) {} // Definición #1

template <typename T>
void f(T) {} // Definición #2

int main() {
    f<Test>(10); // Llamada #1.
    f<int>(10); // Llamada #2. Sin error (aunque no existe int::foo)
                 // gracias a SFINAE.
    return 0;
}
```

En este ejemplo, intentar usar un tipo no de clase en un nombre calificado (T::foo) resulta en un fallo de deducción para f<int> porque int no tiene un tipo anidado llamado foo, pero el programa está bien formado porque una función válida permanece en el conjunto de funciones candidatas

### 4 Implemente utilizando `constexpr` de `C++`:
- Un algoritmo que calcule en tiempo de compilación el n-ésimo valor de la secuencia de _Fibonnacci_.
Ver constexpr_Fibonacci.cpp
- Una clase `Point` que se pueda instanciar en tiempo de compilación.
Ver constexpr_Point.cpp
- Un algoritmo que calcule el punto intermedio entre dos puntos en tiempo de compilación.
Ver constexpr_Point.cpp