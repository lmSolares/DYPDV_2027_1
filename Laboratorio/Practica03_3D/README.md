# Práctica 3: Física, Colisiones e Interacción (Unity 3D)

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Laboratorio/Practica03_3D/`

## Descripción

En esta práctica se introduce la interacción física en un entorno 3D mediante el uso de componentes `Rigidbody`, `Colliders` y `Triggers`. El proyecto permite empujar cajas, recolectar objetos esparcidos por el mapa y activar el mecanismo de apertura de una puerta.

## Requisitos

- Editor de Unity instalado.
- Carpeta de la práctica anterior (`Practica02_3D`) copiada y renombrada como base del proyecto.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Laboratorio/Practica03_3D/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal ubicada en `Scenes/Practica03_3D.unity`.
4. Presionar el botón **Play** (►) para iniciar la simulación.

## Funcionamiento

Para comprobar el correcto funcionamiento de los objetivos de la práctica, una vez ya ejecutando verificar lo siguiente:

- Caminar contra los cubos (`PushBox` de color morado) en la escena, estos deben ser empujados por el jugador usando las físicas del motor.
- Al caminar sobre las esferas (`PickupItem`), estas deben desaparecer automáticamente de la escena y registrar un mensaje de "Objeto recogido" en la consola de Unity.
- Acercarse a la puerta (`DoorPrefab`), al entrar en la zona invisible de activación (Trigger), la puerta se elevará. Al salir de la zona, la puerta bajara y se cerrará por sí sola.
