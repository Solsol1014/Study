using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class FloatingTextManager : MonoBehaviour
{
    public GameObject textContainer; //积己等 floatingText狼 何葛 开且.
    public GameObject textPrefab;

    private List<FloatingText> floatingTexts = new List<FloatingText>();

    private void Update()
    {
        foreach (FloatingText txt in floatingTexts)
            txt.UpdateFloatingText();
    }

    public void show(string msg, int fontSize, Color color, Vector3 position, Vector3 motion, float duration)
    {
        FloatingText floatingText = GetFloatingText();

        floatingText.text.text = msg;
        floatingText.text.fontSize = fontSize;
        floatingText.text.color = color;

        //Transfer world space to screen space so we can use it in the UI
        floatingText.gameObject.transform.position = Camera.main.WorldToScreenPoint(position);
        floatingText.motion = motion;
        floatingText.duration = duration;

        floatingText.Show();
    }

    private FloatingText GetFloatingText()
    {
        FloatingText txt = floatingTexts.Find(t => !t.active);

        if (txt == null)
        {
            txt = new FloatingText();
            txt.gameObject = Instantiate(textPrefab);
            txt.gameObject.transform.SetParent(textContainer.transform);
            txt.text = txt.gameObject.GetComponent<Text>();

            floatingTexts.Add(txt);
        }

        return txt;
    }
}
