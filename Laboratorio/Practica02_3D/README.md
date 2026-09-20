# Práctica 2: Terreno y Navegación (NavMesh)

**Alumno:** Luis Mario Solares Ramos
**Ubicación:** `/Laboratorio/Practica02_3D/`

## Descripción

En esta práctica se crea un entorno 3D con un terreno y 5 obstáculos para configurar un sistema de navegación utilizando NavMesh. La idea es lograr que un agente se mueva de forma autónoma por la escena esquivando los obstáculos.

## Requisitos

- Editor de Unity instalado.
- Paquete **IA Navigation** instalado desde el _Package Manager_.
- Carpeta de la práctica anterior (`Practica01_3D`) copiada y renombrada como base del proyecto.

## Instrucciones de Ejecución

1. Abrir **Unity Hub**.
2. Seleccionar la opción **Open** y navegar hasta la ruta `/Laboratorio/Practica02_3D/`.
3. Una vez que el editor cargue, dirigirse a la ventana **Project** y abrir la escena principal ubicada en `Scenes/Practica02_3D.unity`.
4. Presionar el botón **Play** (►) para iniciar la simulación.

## Funcionamiento

Para comprobar el correcto funcionamiento de los objetivos de la práctica, una vez ya ejecutando verificar:

- **Navegación Autónoma (Aleatoria):** Por defecto, el agente calculará rutas y se moverá automáticamente hacia destinos generados al azar dentro del terreno, detectando y evadiendo los cubos configurados como obstáculos.
