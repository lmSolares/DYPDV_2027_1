# Práctica 4: Animación de Personaje (Animator, Estados y Root Motion)

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Laboratorio/Practica04_3D/`

## Descripción

En esta práctica se integra un sistema de animación 3D utilizando un Animator Controller, estados, transiciones, Blend Trees y Root Motion. El objetivo principal es animar a un personaje en tercera persona, permitiéndole transicionar entre los estados de reposo (Idle), caminar (Walk), correr (Run) y saltar (Jump), siendo las propias animaciones las que impulsan su desplazamiento.

## Requisitos

- Editor de Unity instalado.
- Carpeta de la práctica anterior (`Practica03_3D`) copiada y renombrada como base del proyecto.
- Modelo 3D y animaciones (importadas con Rig configurado en Humanoid).

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Laboratorio/Practica04_3D/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal ubicada en `Scenes/Practica04_3D.unity`.
4. Presionar el botón **Play** (►) para iniciar el modo de juego.

## Funcionamiento

Para comprobar el correcto funcionamiento de los objetivos de la práctica, una vez en ejecución verifica lo siguiente:

- **Sistema de Locomoción:** Utiliza las teclas direccionales (W, A, S, D). Al moverte, el personaje transicionará desde su estado de reposo (Idle), a caminar (Walk), y acelerará hasta correr (Run) gracias a la configuración del Blend Tree.
- **Salto:** Al presionar la tecla **Espacio**, el personaje ejecutará la animación de salto desde cualquier estado en el que se encuentre.
- **Root Motion:** Notarás que el desplazamiento del personaje en el entorno es controlado y movido directamente por los datos de las animaciones, respondiendo a los inputs capturados por el script de control de animaciones (`PlayerMovementAnim.cs`).
