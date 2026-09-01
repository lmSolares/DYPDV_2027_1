# Práctica 1: Introducción a Unity 2D, Sprites y Colisiones Básicas

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Ayudantia/Practica01/Proyecto2D/`

## Descripción
En está práctica nos introducimos a Unity 2D. Se ven los conceptos básicos para un proyecto, como importar *spritesheets*, configuración de físicas con `Rigidbody2D` y `BoxCollider2D`, e implementación de un sistema de detección de *inputs* y colisiones.

## Requisitos
* Unity Hub y el Editor de Unity instalados (plantilla 2D Core).
* Clonar este repositorio.

## Instrucciones de Ejecución
1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Ayudantia/Practica01/Proyecto2D/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal ubicada en `Assets/Scenes/SampleScene.unity`.
4. Abrir la ventana de **Console** (`Window > General > Console`), para que se vea mejor, se puede activar la opción **Collapse**.
5. Presionar el botón **Play** (►) para iniciar el *Game Loop*.

## Funcionamiento
Para comprobar el correcto funcionamiento de los objetivos de la práctica, haz clic izquierdo dentro de la pestaña **Game** una vez que el proyecto esté en ejecución y realiza las siguientes pruebas:

### 1. Detección de Inputs
* **Movimiento Horizontal:** Al presionar las teclas `A` / `D` o las flechas de dirección, la consola imprimirá repetidamente el valor capturado (`Movimiento horizontal: 1` o `-1`).
* **Salto:** Al presionar la tecla `Space`, la consola registrará el mensaje `Salto detectado`.
