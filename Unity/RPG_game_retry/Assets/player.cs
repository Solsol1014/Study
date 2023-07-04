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

        //moveDelta 값 초기화
        moveDelta = new Vector3 (x, y, 0);

        //Horizontal 입력 값에 따라 캐릭터의 좌우 방향 변경
        if(moveDelta.x > 0)
        {
            transform.localScale = Vector3.one;
        }
        else if(moveDelta.x < 0)
        {
            transform.localScale = minusOne;
        }

        //캐릭터 움직이기
        transform.Translate(moveDelta * Time.deltaTime);
    }
}
