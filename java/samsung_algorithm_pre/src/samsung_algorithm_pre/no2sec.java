package samsung_algorithm_pre;

import java.util.Scanner;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
//class Solution
public class no2sec
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
			
			char[] xnum = x.toCharArray();
			char[] ynum = y.toCharArray();
			char[] nnum = n.toCharArray();
			char[] solnum = null;
			
			if(nnum[0]<ynum[0])
			{
				if (nnum.length-1>0)
				{
					solnum = new char[nnum.length-1];
					
					for(int i=0;i<solnum.length;i++)
					{
						solnum[i] = xnum[0];
					}
				}
			}
			else if(nnum[0]==xnum[0]||nnum[0]==ynum[0])
			{
				solnum = new char[nnum.length];
				
				if(nnum[0]==xnum[0])
					solnum[0] = xnum[0];
				else
					solnum[0] = ynum[0];
				
				for (int i=1;i<solnum.length;i++)
				{
					if(nnum[i]<ynum[0])
					{
						if (nnum.length-1>0)
						{
							solnum = new char[nnum.length-1];
							
							for(int j=0;i<solnum.length;j++)
							{
								solnum[j] = xnum[0];
							}
							
						}
						break;
					}
					else
					{
						if(nnum[i]==xnum[0]||nnum[i]==ynum[0])
						{
							
						}
						else
						{
							
						}
					}
				}
			}
			else
			{
				solnum = new char[nnum.length];
				
				if(nnum[0]<xnum[0])
					solnum[0] = ynum[0];
				else
					solnum[0] = xnum[0];
				
				for(int i=1;i<solnum.length;i++)
				{
					solnum[i] = xnum[0];
				}
			}
			
			if(solnum==null || solnum[0]=='0')
			{
				System.out.println("#"+test_case+" -1");
			}
			else
			{
				String str = new String(solnum);
				System.out.println("#"+test_case+" "+str);
			}
			
			
		}
		
		sc.close();
	}
}