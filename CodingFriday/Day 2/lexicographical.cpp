








void stringreplacement(string givenStr, string toReplace)
{
 Bool reset = false;
 
  for(int i = 0, n = 0; i < strlen(givenStr); i++)
  {
  	if(givenStr[i] != toReplace[n])
 	{
 		n = 0;
 	}
 	//find the next ? in the string
 	if(givenStr[i] == '?')
 	{
 		if(n == strlen(toReplace) )
 		{
 			n = 0;
 		}
 		givenStr[i] = toReplace[n+1];
 	}
  }
 
 
 
 
 
 
 
 for(int i = 0, n = 0; i < strlen(givenStr); i++)
 {
 	//if given string letter and to replace are sam store in present
 	//else reset the Present and start toReplace from first
 	if(givenStr[i] != toReplace[n])
 	{
 		n = 0;
 	}
 	//find the next ? in the string
 	if(givenStr[i] == '?')
 	{
 		reset = true;
 		if(n == strlen(toReplace) )
 		{
 			n = 0;
 		}
 		givenStr[i] = toReplace[n+1];
 	}
 	else
 	{
 		reset = false;
 	} 	
 	if(n == strlen(toReplace))
 	{
 		
 		if(reset )
 		{
 			moveByonestepAndaddfirstletter(toReplace, )
 		}
 		n = 0;
 	}
 	
 	
 /*	
 	if(giverStr[i] == '?')
 	{
 		int j = i-1;
 		int replaceStrPos = strlen(toReplace);
 		
 		while(j >= 0)
 		{
 			//compare the previous value with the end of to Replace string
 			//if same then decrement both and compare again
 			//else add the current char of the replace string
 			if(compare(given[j],replaceStrPos)
 			{
 				j--;
 				replaceStrPos--;
 				continue;
 			}
 			else
 			{
 				given[i] = toReplace[replaceStrPos];
 			}
 		}
 	}
 	*/
 }
}