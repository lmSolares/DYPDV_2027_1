using UnityEngine;

public class Door : MonoBehaviour
{
    public Vector3 openOffset = new Vector3(0, 5, 0);
    public float velocidad = 2.0f;
    private bool isOpen = false;
    public DoorTrigger doorTrigger; // Asignar en Inspector

    private Vector3 posicionCerrada;
    private Vector3 posicionAbierta;

    private void Start()
    {
        posicionCerrada = transform.position;
        posicionAbierta = transform.position + openOffset;
    }

    private void OnEnable()
    {
        if (doorTrigger != null)
        {
            doorTrigger.OnDoorOpen += OpenDoor;
            doorTrigger.OnDoorClose += CloseDoor;
        }
    }

    private void OnDisable()
    {
        if (doorTrigger != null)
        {
            doorTrigger.OnDoorOpen -= OpenDoor;
            doorTrigger.OnDoorClose -= CloseDoor;
        }
    }

    private void Update()
    {
        Vector3 posicionObjetivo = isOpen ? posicionAbierta : posicionCerrada;

        transform.position = Vector3.MoveTowards(transform.position, posicionObjetivo, velocidad * Time.deltaTime);
    }

    public void OpenDoor()
    {
        isOpen = true;
    }

    public void CloseDoor()
    {
        // Solo cambiamos el estado
        isOpen = false;
    }
}
