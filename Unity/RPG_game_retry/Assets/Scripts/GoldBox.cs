using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GoldBox : Collectable
{
    public Sprite emptyBox;
    public int goldAmount = 10;

    protected override void OnCollide(Collider2D coll)
    {
        if(!collected)
        {
            collected = true;
            GetComponent<SpriteRenderer>().sprite = emptyBox;

            string msg = "+" + goldAmount + "°ñµå È¹µæ!";
            int fontSize = 25;
            Color color = new Color(255, 255, 0);
            Vector3 position = transform.position;
            Vector3 motion = Vector3.up * 50;
            float duration = 3.0f;

            GameManager.instance.showText(msg, fontSize, color, position, motion, duration);
            GameManager.instance.gold += goldAmount;
        }
    }
}
