# Práctica 4: Animaciones 2D, Transiciones y Sonido

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Ayudantia/Practica04/`

## Descripción

En esta práctica se integró un sistema de animaciones 2D utilizando un Animator Controller. Esto permite sincronizar el estado visual del personaje (reposo, caminar, saltar y caer). Ademas, se implementó el giro del sprite según la dirección del movimiento y se añadieron efectos de sonido básicos (pasos y saltos) gestionados mediante un componente AudioSource.

## Requisitos

- Unity Hub y el Editor de Unity instalados (plantilla 2D Core).
- Práctica 3 completada con el proyecto Unity funcional (movimiento avanzado, coyote time, buffer de salto y frenado).
- Clonar este repositorio.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Ayudantia/Practica04/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal de la práctica (por ejemplo, `SampleScene`).
4. Presionar el botón **Play** (►) para iniciar la ejecución.

## Funcionamiento

Para demostrar el funcionamiento del proyecto, hacer clic izquierdo dentro de la pestaña **Game** una vez que esté en ejecución y realizar las siguientes pruebas:

- **Animación de Movimiento:** Al usar las teclas `A` / `D` o las flechas de dirección, el personaje se desplazará reproduciendo la animación de caminar ("Walk") y volteará su cuerpo hacia la dirección correspondiente. Al detenerse, regresará suavemente a su estado de reposo ("Idle").
- **Animaciones de Aire:** Al presionar la tecla `Space`, el personaje iniciará la animación de salto ("Jump") en su fase de ascenso. En cuanto su velocidad vertical sea negativa y comience a descender, transicionará automáticamente a la animación de caída ("Fall") hasta tocar el suelo.
- **Efectos de Sonido:** Se emitirá un efecto de sonido cada vez que el personaje inicie un salto. Del mismo modo, mientras camine sobre el suelo, se reproducirá un sonido de pasos.