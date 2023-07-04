using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player : MonoBehaviour
{
    private BoxCollider2D boxCollider;

    private Vector3 moveDelta;

    private Vector3 minusOne = new Vector3(-1, 1, 1);

    // Start is called before the first frame update
    private void Start()
    {
        boxCollider = GetComponent<BoxCollider2D>();    
    }

    private void FixedUpdate()
    {
        moveDelta = Vector3.zero;

        float x = Input.GetAxisRaw("Horizontal");
        float y = Input.GetAxisRaw("Vertical");

        //moveDelta �� �ʱ�ȭ
        moveDelta = new Vector3 (x, y, 0);

        //Horizontal �Է� ���� ���� ĳ������ �¿� ���� ����
        if(moveDelta.x > 0)
        {
            transform.localScale = Vector3.one;
        }
        else if(moveDelta.x < 0)
        {
            transform.localScale = minusOne;
        }

        //ĳ���� �����̱�
        transform.Translate(moveDelta * Time.deltaTime);
    }
}
