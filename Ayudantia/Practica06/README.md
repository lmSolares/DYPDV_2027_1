# Práctica 6: Proyectiles, Colisiones Avanzadas y Plataformas

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Ayudantia/Practica06/`

## Descripción

En esta práctica se implementaron las mecánicas para que el jugador pueda disparar elementos en el entorno. Se creó un sistema de disparo instanciando un prefab de proyectil, el cual hereda la velocidad y dirección del jugador al momento de ser lanzado, e incluye su animación y sonido. Además, se añadio una plataforma móvil que transporta al personaje al emparentar su `Transform`, y se configuraron colisiones avanzadas para que los proyectiles dañen a los enemigos heredados de la Práctica 05 o se destruyan al chocar contra las paredes.

## Requisitos

- Unity Hub y el Editor de Unity instalados (plantilla 2D Core).
- Práctica 5 completada con el proyecto Unity funcional (Superclase `Personaje` y enemigo tipo Goomba).
- Clonar este repositorio.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Ayudantia/Practica06/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal de la práctica.
4. Presionar el botón **Play** (►) para iniciar la ejecución.

## Funcionamiento

Para demostrar el funcionamiento del proyecto, hacer clic izquierdo dentro de la pestaña **Game** una vez que esté en ejecución y realizar las siguientes pruebas:

- **Sistema de Disparo:** Presiona el botón de disparo (por defecto clic izquierdo o `Ctrl`) para lanzar un proyectil, se reproduce la animación y el sonido de ataque. Si disparas mientras caminas, el proyectil viajará más rápido al sumar la velocidad actual del jugador.
- **Colisiones del Proyectil:** Dispara hacia el enemigo (Hongo) para comprobar que este reciba daño y desaparezca. Si el proyectil impacta contra una pared o un obstáculo, se destruirá automáticamente.
- **Plataformas Móviles:** Utiliza el salto para subirte a la plataforma en movimiento. El personaje será transportado de un punto A a un punto B sin resbalarse, ya que se convierte temporalmente en hijo de la plataforma.
