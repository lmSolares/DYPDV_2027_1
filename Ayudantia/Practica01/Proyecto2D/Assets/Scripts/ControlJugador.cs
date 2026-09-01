using UnityEngine;

public class ControlJugador : MonoBehaviour
{
    void Update()
    {
        float h = Input.GetAxis("Horizontal");
        Debug.Log("Movimiento horizontal: " + h);

        if (Input.GetButtonDown("Jump"))
        {
            Debug.Log("Salto detectado");
        }
    }
}
