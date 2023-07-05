using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager instance;
    private void Awake()
    {
        if(GameManager.instance != null)
        {
            Destroy(gameObject);
            return;
        }

        instance = this;
        SceneManager.sceneLoaded += LoadState;
        DontDestroyOnLoad(gameObject);
    }

    // Resources
    public List<Sprite> playerSprites;
    public List<Sprite> weaponSprites;
    public List<int> weaponPrices;
    public List<int> xpTable;

    // References
    public player player;
    // public weapon weapon..

    public FloatingTextManager floatingTextManager;

    // Logic
    public int gold;
    public int experience;

    // Save state
    /*
     * Int preferedSkin
     * Int gold
     * Int experience
     * Int weaponLevel
     */

    public void showText(string msg, int fontSize, Color color, Vector3 position, Vector3 motion, float duration)
    {
        floatingTextManager.show(msg, fontSize, color, position, motion, duration);
    }

    public void SaveState()
    {
        string s = "";

        s += "0" + "|";
        s += gold.ToString() + "|";
        s += experience.ToString() + "|";
        s += "0";

        PlayerPrefs.SetString("SaveState", s);
    }

    public void LoadState(Scene s, LoadSceneMode mode)
    {
        if (!PlayerPrefs.HasKey("SaveState")) return;
        
        string[] data = PlayerPrefs.GetString("SaveState").Split('|');

        // Change player skin
        gold = int.Parse(data[1]);
        experience = int.Parse(data[2]);
        // Change weapon level;

        Debug.Log("LoadState");
    }
}
