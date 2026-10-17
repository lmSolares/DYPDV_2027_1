# Práctica 06: Movimiento Relativo a la Cámara (Camera-Relative Movement)

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Laboratorio/Practica06_3D/`

## Descripción

En esta práctica se modificó el movimiento del personaje para que las teclas WASD se interpreten según la orientación actual de la cámara. Con esta actualización, el personaje se mueve hacia donde mira la cámara.

## Requisitos

- Editor de Unity instalado.
- Carpeta de la práctica anterior (`Practica05_3D`) copiada y renombrada como base del proyecto.
- Prefabs del `PlayerCharacter` y `CameraRig` importados y configurados en la escena.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Laboratorio/Practica06_3D/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal ubicada en `Scenes/Practica06_3D.unity`.
4. Presionar el botón **Play** (►) para iniciar el modo de juego.

## Funcionamiento

Para comprobar el correcto funcionamiento de los objetivos de la práctica, una vez en ejecución verifica lo siguiente:

- **Movimiento según la cámara:** Al utilizar las teclas direccionales (W, A, S, D), el personaje debe moverse en la dirección hacia la que apunta la cámara. Si giras la cámara, la dirección de avance debe actualizarse automáticamente.
- **Rotación suave:** Al cambiar de dirección de movimiento, el personaje debe rotar sobre su propio eje.
- **Integración con Root Motion:** Las acciones de locomoción deben seguir funcionando correctamente en conjunto con el nuevo sistema de cámara.
