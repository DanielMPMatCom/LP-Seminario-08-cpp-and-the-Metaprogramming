# C++ y la Metaprogramación

### 1 Implemente utilizando **TMP** (_Template Metaprogramming_) de `C++`:

- Un algoritmo que calcule en tiempo de **COMPILACIÓN** el n-ésimo valor de la secuencia de _Fibonnacci_.
  Ver [TMP_Fibonacci.cpp](TMP_Fibonacci.cpp)
- Implemente un `template` que permite desenrollar (_unroll_) una expresión `for` de manera que se genere código secuencial que simule la ejecución de esta expresión.
  Ver [TMP_Unroll_Basic.cpp](TMP_Unroll_Basic.cpp) y [TMP_Unroll_Fn.cpp](TMP_Unroll_Fn.cpp)

### 2 ¿Cómo surge la meta-programación utilizando `templates`?

- Explique la propuesta `if (init; condition)` y `switch (init; condition)`. (Puede ser útil en `C#`?)

La metaprogramación en C++ utilizando templates surgió de manera bastante inesperada. Durante el proceso de estandarización de C++, los desarrolladores descubrieron que el sistema de plantillas era en realidad una máquina de Turing completa. Erwin Unruh fue el primero en demostrar la metaprogramación de plantillas en una reunión del comité al ordenar al compilador que imprimiera números primos en mensajes de error. La metaprogramación con templates en C++ permite a los programadores generar código en tiempo de compilación, lo que puede resultar en programas más eficientes. Esto se logra utilizando plantillas para crear constantes, funciones o estructuras de datos en tiempo de compilación.  Los cálculos se realizan una vez en tiempo de compilación en lugar de en cada tiempo de ejecución.

### 3 Explique el principio **SFINAE** de `C++`.

SFINAE, que significa “Substitution Failure Is Not An Error” (El fallo de sustitución no es un error), es un principio en C++ donde una sustitución inválida de parámetros de plantilla no es en sí misma un error. Cuando se crean candidatos para la resolución de sobrecarga, algunos (o todos) los candidatos de ese conjunto pueden ser el resultado de plantillas instanciadas con argumentos de plantilla (potencialmente deducidos) sustituidos por los parámetros de plantilla correspondientes. Si ocurre un error durante la sustitución de un conjunto de argumentos para cualquier plantilla dada, el compilador elimina la sobrecarga potencial del conjunto de candidatos en lugar de detenerse con un error de compilación, siempre que el error de sustitución sea uno de los que el estándar C++ otorga tal tratamiento.

Por ejemplo, SFINAE puede usarse para determinar si un tipo contiene un cierto typedef1. También se puede encontrar uno de los usos principales de SFINAE a través de las expresiones enable_if. enable_if es un conjunto de herramientas, disponibles en la Biblioteca Estándar desde C++11, que internamente usan SFINAE. Permiten incluir o excluir sobrecargas de posibles plantillas de función o especialización de plantillas de clase

```cpp
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

En este ejemplo, intentar usar un tipo no de clase en un nombre calificado (T::foo) resulta en un fallo de deducción para f `<int>` porque int no tiene un tipo anidado llamado foo, pero el programa está bien formado porque una función válida permanece en el conjunto de funciones candidatas

### 4 Implemente utilizando `constexpr` de `C++`:

- Un algoritmo que calcule en tiempo de compilación el n-ésimo valor de la secuencia de _Fibonnacci_.
  Ver [constexpr_Fibonacci.cpp](constexpr_Fibonacci.cpp)
- Una clase `Point` que se pueda instanciar en tiempo de compilación.
  Ver [constexpr_Point.cpp](constexpr_Point.cpp)
- Un algoritmo que calcule el punto intermedio entre dos puntos en tiempo de compilación.
  Ver [constexpr_Point.cpp](constexpr_Point.cpp)

### 5 Explique hasta dónde se pueden utilizar las `constexpr` de `C++14`.

La palabra clave `constexpr` fue introducida en C++11 y mejorada en C++14. `constexpr` indica que el valor de una variable o función puede ser evaluado en tiempo de compilación. En C++14, las funciones `constexpr` se volvieron más flexibles y poderosas. En C++11, las funciones `constexpr` solo podían contener una única instrucción `return`. Sin embargo, en C++14, pueden contener múltiples declaraciones (como bucles y ramificaciones), lo que permite escribir funciones `constexpr` más complejas. Además, en C++11, `constexpr` implica `const`, pero esto ya no es cierto en versiones posteriores del estándar. Esto significa que en C++14 y versiones posteriores, puedes tener miembros de datos mutables en una clase `constexpr`. Una función `constexpr` no puede ser virtual, no puede ser un bloque de intento de función (function-try-block), y no puede ser una `coroutine`. En C++14, puedes tener miembros de datos mutables en una clase `constexpr`. Para los constructores y destructores `constexpr`, la clase no debe tener clases base virtuales. Aunque una función `constexpr` podría ser calculada durante el tiempo de compilación, el compilador no tiene que hacerlo. A menos que se utilice en un contexto donde se requiere una constante de tiempo de compilación, como la inicialización de una variable `constexpr`, o el uso en un límite de matriz.

Ejemplo de como utilizar `constexpr` en C++14

```cpp
constexpr int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    constexpr int fact5 = factorial(5); // Calculado en tiempo de compilación
    return 0;
}
```

### 6 Sobre las características propuestas para `C++17`:

- Explique en que consiste _template argument deduction for class templates_ y en qué puede ser útil.

La deducción de argumentos de plantilla para plantillas de clase, también conocida como Class Template Argument Deduction (CTAD), es una característica introducida en C++17. Esta característica permite que los argumentos de la plantilla se deduzcan automáticamente a partir de los argumentos del constructor. En otras palabras, en lugar de especificar explícitamente los argumentos de la plantilla, el compilador puede deducirlos automáticamente en base a los argumentos del constructor. Esto puede simplificar el código y hacerlo más legible.

Ejemplo de _template argument deduction for class templates_ en C++17:

```cpp
template <typename T>
class MyContainer {
public:
    MyContainer(T value) {
        // ...
    }
};

int main() {
    // En lugar de especificar explícitamente el tipo de plantilla
    // MyContainer<int> container(42);
  
    // Con CTAD en C++17, el compilador deduce automáticamente el tipo de plantilla
    auto container = MyContainer(42);
  
    return 0;
}
```

En este ejemplo, en lugar de tener que especificar explícitamente MyContainer `<int>`, puedes simplemente escribir MyContainer(42), y el compilador deducirá automáticamente que el tipo de plantilla es int. Además, puedes definir tus propias reglas de deducción personalizadas con deduction guides. Los deduction guides permiten proporcionar reglas personalizadas para la deducción de argumentos de plantilla de clase.

- Explique la propuesta `if (init; condition)` y `switch (init; condition)`. (Puede ser útil en `C#`?)
  Las propuestas if (init; condition) y switch (init; condition) son características introducidas en C++17. En C++, estas construcciones permiten declarar una variable en la condición de un if o switch, limitando su alcance al bloque de dichas instrucciones. Esto puede ser útil para evitar la “fuga” de variables al ámbito circundante

Por ejemplo, en lugar de escribir:

```cpp
{
    auto val = GetValue();
    if (condition(val)) {
        // en caso de éxito
    } else {
        // en caso de fracaso
    }
}
```

Ahora podemos escribir

```cpp
if (auto val = GetValue(); condition(val)) {
    // en caso de éxito
} else {
    // en caso de fracaso
}
```

En este caso, val solo es visible dentro de las declaraciones if y else, por lo que no “se filtra” al ámbito circundante.

Ejemplo de la sintaxis para el _switch_:

```cpp
switch (int i = rand() % 20 + 1; i) {
    case 20:
        cout << "Lucky" << "\n";
        break;
    default:
        cout << i << "\n";
        break;
}
```

La utilidad de una funcionalidad como _switch (init; condition)_ en `C#` puede depender de varios factores, incluyendo el estilo de programación y los requisitos del proyecto, entre las utilidades tenemos que al igual que en `C++`, esta característica podría ayudar a limitar el alcance de las variables en `C#`, lo que puede hacer que el código sea más limpio y fácil de entender, además `C#` ya tiene una sintaxis similar en sus bucles `for`, por lo que los desarrolladores podrían encontrar útil y coherente tener la misma funcionalidad en `switch`. Sin embargo, la necesidad de esta característica puede no ser tan alta en `C#`, ya que el lenguaje ya ofrece otras construcciones poderosas para el control de flujo, como `if`, `else if`, `switch`, `foreach`, y `using`, que pueden cubrir la mayoría de los casos de uso.

- Exponga brevemente otras 2 propuestas al lenguaje que le parezcan atractivas.

##### 1.

Las expresiones plegables son una característica introducida en C++17 que permite realizar operaciones con paquetes de parámetros de plantillas. Un paquete de parámetros es una lista de parámetros de plantilla que puede tener un número variable de argumentos. Las expresiones plegables proporcionan una forma concisa de aplicar un operador a todos los elementos de un paquete de parámetros. Por ejemplo, si tienes una función de plantilla variádica que acepta un número arbitrario de argumentos, puedes sumar todos los argumentos con una expresión plegable:

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // Expresión plegable
}
```

En este caso, (... + args) es una expresión plegable que expande el paquete de parámetros args aplicando el operador + a cada argumento. Las expresiones plegables pueden ser de dos tipos: unarios y binarios. Los pliegues unarios a izquierda y derecha se conocen como pliegues unarios. En un pliegue unario, la expresión debe contener un paquete de parámetros sin expandir.

Ver [expresiones_plegables.cpp](expresiones_plegables.cpp)

##### 2.

El fallthrough es un atributo introducido en C++17 que se utiliza en las declaraciones de switch para indicar que la “caída” (o “fallthrough”) de un caso a otro es intencional. En C++, cuando se ejecuta un caso en una declaración de switch y no se encuentra una declaración de break, el control “cae” al siguiente caso. Este comportamiento puede introducir errores si no es intencional, por lo que algunos compiladores y analizadores estáticos emiten una advertencia en este caso. El atributo fallthrough se utiliza para especificar en el código que esta “caída” es intencional y no debe generar una advertencia.

Ejemplo del uso de fallthrough:

```cpp
switch (device.status) {
    case sleep:
        device.wake();
        [[fallthrough]]; // Indica que la caída al siguiente caso es intencional
    case ready:
        device.run();
        break;
    case bad:
        handle_error();
        break;
    default:
        break;
}
```

En este ejemplo, si el estado del dispositivo es `sleep`, va a llamar a `wake()` y luego va a verificar el estado `ready`.
