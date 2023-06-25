package samsung_algorithm_pre;

import java.util.Scanner;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
//class Solution
public class no2third
{
	public static void main(String args[]) throws Exception
	{

		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		
		String n, x, y;
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			
			n = sc.next();
			x = sc.next();
			y = sc.next();
			
			if (Integer.parseInt(x)<Integer.parseInt(y))
			{
				String temp = x;
				x = y;
				y = temp;
			}
			
			char[] nnum = n.toCharArray();
			char[] xnum = x.toCharArray();
			char[] ynum = y.toCharArray();
			char[] solnum = new char[nnum.length];
			Boolean small = false;
			Integer depth = 0;
			
			if(small);
			dfs(nnum, solnum, xnum[0], ynum[0], depth, small);
			
		}
		
		sc.close();
	}

	private static char[] dfs(char[] nnum, char[] solnum, char x, char y, Integer i, Boolean small) {
		// TODO Auto-generated method stub
		
		int depth = i;
		
		if(nnum[i]>x)
		{
			solnum[i] = x;
			small = true;
		}
		else if (nnum[i]==x)
		{
			solnum[i] = x;
			solnum = dfs(nnum, solnum, x, y, ++i, small);
		}
		else if (nnum[i]>y)
		{
			solnum[i] = y;
			small = true;
		}
		else if (nnum[i]==y)
		{
			
		}
		else
		{
			
		}
		
		return solnum;
	}
}