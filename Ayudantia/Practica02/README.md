# Práctica 2: Física Manual de Movimiento y Salto

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Ayudantia/Practica02/`

## Descripción

En esta práctica se implementa el movimiento y salto manual para el Jugador. Se utiliza la aceleración, velocidad y `deltaTime` para lograr darle movimiento al jugador. Ademas, se comunican los scripts utilizando `GetComponent`.

## Requisitos

- Unity Hub y el Editor de Unity instalados (plantilla 2D Core).
- Práctica 1 completada con el proyecto Unity funcional (prefab del jugador, detección de colisiones e inputs configurados).
- Clonar este repositorio.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Ayudantia/Practica02/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal de la práctica.
4. Presionar el botón **Play** (►) para iniciar la ejecución.

## Funcionamiento

Para demostrar el funcionamiento del proyecto, hacer clic izquierdo dentro de la pestaña **Game** una vez que esté en ejecución y realiza las siguientes pruebas:

- **Movimiento Lateral:** Al usar las teclas `A` / `D` o las flechas de dirección, el personaje se desplazará utilizando el cálculo manual de velocidad y aceleración.
- **Salto y Gravedad:** Al presionar la tecla `Space` , el personaje realizará un salto basado en aceleración vertical y caerá de regreso al suelo por el cálculo de la gravedad manual.
- **Detección de Suelo:** Se garantiza que el personaje se detiene correctamente sobre la plataforma y que únicamente puede volver a saltar si se encuentra tocando el suelo.
