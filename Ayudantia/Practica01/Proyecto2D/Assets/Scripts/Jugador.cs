using UnityEngine;

public class Jugador : MonoBehaviour
{

    void OnCollisionEnter2D(Collision2D col)
    {
        Debug.Log("Se choco con: " + col.gameObject.name);
    }


    void OnCollisionStay2D(Collision2D col)
    {
        Debug.Log("Se sigue tocando: " + col.gameObject.name);
    }
}
