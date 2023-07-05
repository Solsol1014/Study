using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Weapon : Collidable
{
    public int damagePoint = 1;
    public int weaponLevel = 0;

    private float coolTime = 0.5f;
    private float lastSwing;

    public Animator anim;

    protected override void Update()
    {
        base.Update();

        if(Input.GetKeyDown(KeyCode.Space))
        {
            if(Time.time - lastSwing < coolTime)
            {
                lastSwing = Time.time;
                Swing();
            }
        }
    }

    private void Swing()
    {
        anim.SetTrigger("Swing");
    }
}
