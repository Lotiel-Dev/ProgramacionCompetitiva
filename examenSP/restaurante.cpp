un restaurante sirve n platos distintos, preparados con ingredientes diferentes. Hay suficientes ingredientes
para servir el plato i , ci veces.

hoy hay m clientes, son demasiados y puede que no hayan suficientes ingredientes para preparar todos sus platos.
intentando que todos queden satisfechos, se pide a cada cliente que haga una lista de platos que estarian dispuestos a comer.
se intenta servir exactamente un plato a cada cliente, y el plato debe ser uno presente en su lista.
Puede que sea imposible servir un plato a todos los clientes; en ese caso se sirve un plato a la mayor cantidad de clientes posible
debes calcular la maxima cantidad de platos que se pueden servir  de modo que se respeten las listas de cada clientes.

Entrada
la primer linea contiene dos enteros n(1<=n<=100) y m(1<=m<=100), indicando la cantidad de platos y clientes respectivamente
la segunda linea contiene una lista de n enteros ci(1<=ci<=100), indicando la cantidad de veces que se puede preparar el plato i.
sigen m lineas. la i-esima linea empieza con un entero k(1<=k<=n), siguen k enteros pj(1<=pj<=n), indicando que el cliente i esta dispuesto a comer el plato pj.

Salida
se debe imprimir un entero indicando la maxima cantidad de platos que se pueden servir.

Sample input 
3 4
2 2 1
1 1
1 3
2 3 1
1 3
Sample output 
3

Explicacion

nota: se puede servir el plato 1 al primer cliente, el plato 3 al segundo cliente y el plato 1 al tercer cliente.
No hay forma de servir un plato a todos los clientes respetando sus listas.

Time limit: 1 sec 
memory limit: 256MB 
source limit: 1024KB
