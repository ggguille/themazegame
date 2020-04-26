# PLATZI - Introducción C++
## Proyecto final

```
        ,     \    /      ,        
       / \    )\__/(     / \       
      /   \  (_\  /_)   /   \      
 ____/_____\__\@  @/___/_____\____ 
|             |\../|              |
|              \VV/               |
|           Welcome to            |
|         *The Maze Game*         |
|_________________________________|
 |    /\ /      \\       \ /\    | 
 |  /   V        ))       V   \  | 
 |/     `       //        '     \| 
 `              V                '
```

Para compilar el proyecto basta con usar el comando **_make_** (CMake).
Este genera una carpeta _./build_ con los recursos del programa y su ejecutable.

Los mapas se pueden ver en los archivos de la carpeta maps.
Estos estan definidos en una grilla de caracteres de 15X10.

* **0** -> espacio vacío
* **1** -> pared
* **P** -> posicion inicial del jugador
* **$** -> posicion del tesoro
* **x** -> posicion inicial de un enemigo

_Exemplo_:
```
1111111111
1P01x00001
1001111101
1000000001
1011010001
1000x10001
1111111101
1000000001
1111011111
1000000001
1111101001
1000001001
1010111001
1x1000$101
1111111111
```
