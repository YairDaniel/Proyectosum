#include <iostream>
using namespace std;

// La función sum_asm está marcada con el atributo __declspec(naked), lo que significa
// que no usará la pila de llamadas de forma predeterminada, lo que permite escribir
// código ensamblador inline.
__declspec(naked) int sum_asm(int* numbers, int length) {
    __asm {
        // Se guarda el puntero de la pila en ebp y se copia el puntero de la pila
        // en esp para preparar el marco de pila.
        push ebp
        mov ebp, esp

        // Se inicializa el registro eax con 0, que se utilizará para almacenar la
        // suma de los elementos del arreglo.
        mov eax, 0

        // Se mueve el valor de length al registro ecx.
        mov ecx, [ebp + 12]

        // Se mueve el valor del puntero numbers al registro esi.
        mov esi, [ebp + 8]

        // Se inicia un bucle con el nombre loop_start.
        loop_start:

            // Se agrega el valor en memoria apuntado por esi a eax.
            add eax, [esi]

            // Se actualiza el puntero esi para apuntar al siguiente elemento del arreglo.
            add esi, 4

            // Se decrementa el contador ecx y se repite el bucle hasta que ecx sea 0.
            loop loop_start

        // Se restaura el puntero de la pila y se devuelve el control a la función llamadora.
        pop ebp
        ret
    }
}

int main() {
    int numbers[100];
    int length = 0;
    int num;

    // Se solicita al usuario que ingrese números y se almacenan en el arreglo.
    cout << "Ingrese los números (ingrese cualquier letra para terminar):" << endl;

    while (std::cin >> num) {
        if (length < 100) {
            numbers[length] = num;
            length++;
        }
        else {
            std::cout << "El arreglo está lleno. No se pueden agregar más números." << std::endl;
            break;
        }
    }

    // Se calcula la suma de los números utilizando la función sum_asm.
    int sum = sum_asm(numbers, length);

    // Se muestra el resultado en la consola.
    cout << "Suma: " << sum << endl;

    return 0;
}