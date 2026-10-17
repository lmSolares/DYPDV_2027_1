using UnityEngine;
public class PlayerMovementAnim : MonoBehaviour {
    Animator anim;
    CharacterController controller;
    public Transform cameraTransform;

    void Start() {
        anim = GetComponent<Animator>();
        controller = GetComponent<CharacterController>();
        if (cameraTransform == null) {
            cameraTransform = Camera.main.transform;
        }
    }

    void Update() {
        float x = Input.GetAxis("Horizontal");
        float z = Input.GetAxis("Vertical");
        float speedValue = new Vector2(x, z).magnitude;
        anim.SetFloat("Speed", speedValue);

        Vector3 camForward = cameraTransform.forward;
        Vector3 camRight = cameraTransform.right;

        camForward.y = 0;
        camRight.y = 0;
        camForward.Normalize();
        camRight.Normalize();

        Vector3 direction = (camForward * z) + (camRight * x);

        if (direction.magnitude > 0.1f) {
            transform.rotation = Quaternion.Slerp(
                transform.rotation,
                Quaternion.LookRotation(direction),
                Time.deltaTime * 10f
            );
        }
        if (Input.GetKeyDown(KeyCode.Space)) {
            anim.SetBool("IsJumping", true);
        } else {
            anim.SetBool("IsJumping", false);
        }
    }
}
