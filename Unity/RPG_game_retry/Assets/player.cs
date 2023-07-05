using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player : MonoBehaviour
{
    private BoxCollider2D boxCollider;

    private Vector3 moveDelta;

    private Vector3 minusOne = new Vector3(-1, 1, 1);

    private RaycastHit2D hit;

    public float moveX = 1;
    public float moveY = 1;

    private bool isWalkFirst = true;
    private bool isIdleNow = false;
    private Animator animator;

    // Start is called before the first frame update
    private void Start()
    {
        boxCollider = GetComponent<BoxCollider2D>();
        animator = GetComponent<Animator>();
    }

    private void FixedUpdate()
    {
        //moveDelta = Vector3.zero;

        float x = Input.GetAxisRaw("Horizontal") * moveX;
        float y = Input.GetAxisRaw("Vertical") * moveY;

        if(isWalkFirst && (x!=0 || y!=0))
        {
            isWalkFirst = false;
            isIdleNow = false;
            animator.Play("walk");
        }

        if(x==0&&y==0&&!isIdleNow)
        {
            isWalkFirst=true;
            isIdleNow=true;
            animator.Play("idle");
        }

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
        //transform.Translate(moveDelta * Time.deltaTime);

        hit = Physics2D.BoxCast(transform.position, boxCollider.size, 0, new Vector2(0, moveDelta.y), Mathf.Abs(moveDelta.y * Time.deltaTime), LayerMask.GetMask("Blocking"));

        if(hit.collider == null)
        {
            transform.Translate(0, moveDelta.y * Time.deltaTime, 0);
        }

        hit = Physics2D.BoxCast(transform.position, boxCollider.size, 0, new Vector2(moveDelta.x, 0), Mathf.Abs(moveDelta.x * Time.deltaTime), LayerMask.GetMask("Blocking"));

        if(hit.collider == null)
        {
            transform.Translate(moveDelta.x * Time.deltaTime, 0, 0);
        }
    }
}
