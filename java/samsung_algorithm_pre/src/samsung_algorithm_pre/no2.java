package samsung_algorithm_pre;

import java.util.Scanner;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
//class Solution
public class no2
{
	public static void main(String args[]) throws Exception
	{

		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		
		int n, x, y;
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			
			n = sc.nextInt();
			x = sc.nextInt();
			y = sc.nextInt();
			if(x<y)
			{
				int temp = x;
				x = y;
				y = temp;
			}
			
			String str = Integer.toString(n);
			
			int nnum = str.length();
			
			int n10 = (int) Math.pow(10, nnum-1);
			
			int num = 0;
			
			if(n/n10>=y)
			{
				if(n/n10>=x)
					num = x*n10;
				else
					num = y*n10;
				
				while(n10>1)
				{
					n10 = n10/10;
					
					if(num+n10*y>n)
					{
						num = 0;
						
						while (n10>1)
						{
							n10 = n10/10;
							
							num += x*n10;
						}
						
						break;
					}
					else
					{
						if(num+n10*x>n)
							num += n10*y;
						else
							num += n10*x;
					}
				}
			}
			else
			{	
				while (n10>1)
				{
					n10 = n10/10;
					
					num += x*n10;
				}
			}
			
			if(num==0)
				num = -1;
			
			System.out.println("#"+test_case+" "+num);
			
		}
		
		sc.close();
	}
}