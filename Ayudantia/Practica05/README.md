# Práctica 5: Inteligencia Artificial Básica, Patrullaje y Herencia

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Ayudantia/Practica05/`

## Descripción

En esta práctica agrego una superclase `Personaje`, de la cual heredan tanto el jugador como los enemigos para compartir atributos de vida y métodos de daño. Se implementó un enemigo básico con inteligencia artificial de patrullaje tipo "Goomba", el cual cambia de dirección automáticamente al chocar con paredes u obstáculos. Además, se añadió un sistema de detección de daño bidireccional y las animaciones correspondientes para el enemigo.

## Requisitos

- Unity Hub y el Editor de Unity instalados (plantilla 2D Core).
- Práctica 4 completada con el proyecto Unity funcional (movimiento, animaciones del jugador y efectos de sonido).
- Clonar este repositorio.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Ayudantia/Practica05/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal de la práctica.
4. Presionar el botón **Play** (►) para iniciar la ejecución.

## Funcionamiento

Para demostrar el funcionamiento del proyecto, hacer clic izquierdo dentro de la pestaña **Game** una vez que esté en ejecución y realizar las siguientes pruebas:

- **Patrullaje del Enemigo:** Observarás a un enemigo moviéndose de lado a lado reproduciendo su animación de caminata. Al colisionar con una pared o un obstáculo, este invertirá su dirección automáticamente (volteando también su sprite).
- **Daño al Jugador:** Si utilizas las teclas de movimiento (`A` / `D` o flechas) para caminar hacia el enemigo y lo chocas lateralmente, el jugador recibirá daño (se restará vida) y por lo tanto desaperecera.
- **Derrotar al Enemigo:** Si utilizas la tecla `Space` para saltar y logras caer directamente sobre la parte superior del enemigo, este será quien reciba el daño y desaparecerá de la escena.
