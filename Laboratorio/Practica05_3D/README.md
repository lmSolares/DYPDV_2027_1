# Práctica 05 - Cámara TPS Avanzada (Orbit, Follow, Collision)

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Laboratorio/Practica05_3D/`

## Descripción

En esta práctica se implementa un sistema de cámara en tercera persona que permite seguir al personaje, rotar a su alrededor, ajustar la sensibilidad, ademas de evitar atravesar paredes mediante un sistema de colisión de cámara.

## Requisitos

- Editor de Unity instalado.
- Carpeta de la práctica anterior (`Practica04_3D`) copiada y renombrada como base del proyecto.
- Escena configurada con el `PlayerCharacter` y obstáculos (elementos 3D con Colliders) alrededor del personaje para probar las interacciones.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Laboratorio/Practica05_3D/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal ubicada en `Scenes/Practica05_3D.unity`.
4. Presionar el botón **Play** (►) para iniciar el modo de juego.

## Funcionamiento

Para comprobar el correcto funcionamiento de los objetivos de la práctica, una vez en ejecución verifica lo siguiente:

- **Cámara:** Utiliza el ratón para rotar la vista horizontal y verticalmente alrededor del personaje.
- **Seguimiento:** Mueve al personaje utilizando las teclas de movimiento; la cámara debe seguir su posición.
- **Colisión de Cámara:** Acerca el personaje a las paredes en la escena. La cámara se acerca automáticamente al jugador mediante _Raycasts_ para evitar atravesar las paredes.
