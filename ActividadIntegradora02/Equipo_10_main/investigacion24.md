# Investigación AI 2.4
#### *Maarten van 't Hoff - A01764070*
La problema 4 de la Actividad Integradora 2 indica un espacio de N puntos, representando a los centrales para conectar nuevas casas al red. Lo que queremos ver es la distancia entre los centrales cuando añadimos una nueva. Aquí queremos buscar la central más cercana a la central nueva.

### Árbol KD
La solución que es sencillo y eficiente para hacer esto es con un árbol KD. Esto es un árbol que permite buscar el vecino más cercano en K dimensiones. Requiere un preprocesamiento, en cual se hace un árbol binario, dividiendo el espacio en sectores o cuadros. Cada nivel del árbol mira al proximo dimensión espacial, así que si estamos en 2 dimensiones, el árbol se va alternando entre `x` y `y` cada nivel. Cada vez cuando se elige un punto para añadir al árbol, partimos el espacio por el punto que escogimos, como vemos en el imagen de abajo. Este preprocesamiento tiene un complejidad en tiempo de `O(N*log(N))` y un complejidad espacial de `O(N)` para crear el árbol binario.

<center>
<img src="https://www.baeldung.com/wp-content/uploads/sites/4/2023/03/kdtree.png" width="400">
</center>

Con el preprocesamiento listo, lo que necesitamos hacer es travesar al árbol binario. Como cada nivel se esta alternando entre `x` y `y` buscamos el sector más cercana al punto nuevo en cada nivel, pero solo en respeto a una dimensión. Esto significa que hay una posibilidad de que el punto inicial que escogimos como el "más cercano" no es justo. Lo que hacemos para evitar esto es cuando recursimos hacia arriba vamos mirando si la distancia entre el candidado más cercano es más largo que la distancia con el otro sector que no controlamos. Si esto es el caso, vamos a travesar al árbol por la otra rama para ver si hay un punto más cercano ahí. Con eso, podemos buscar el punto más cercano con una complejidad promedio de `O(log(N))`, con el peor caso de `O(N)`.

#### *Bibliografía*
1. Hristov, H. (2023, March 29). Introduction to K-D Trees. Baeldung CS. https://www.baeldung.com/cs/k-d-trees
1. Stable Sort. (2020, October 9). KD-Tree Nearest Neighbor Data Structure [Video]. YouTube. https://www.youtube.com/watch?v=Glp7THUpGow