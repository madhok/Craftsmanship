
int getval(int running, int multiplyBy, int sum) //3,3,4
{
	int multiplier[3] = {1,-1,0,};
	int n = 3;	
	int index = 1;// = running*multiplyBy ;
	int modval;
	if(multiplyBy == 3)
	{
		n = 9;
		modval = (running) % n;
		
	}
	else if(multiplyBy == 9)
	{
		n = 27;
		modval = (running) % n;
	}
	 modval = (running) % n;
	while(modval > multiplyBy && multiplyBy != 1)
	{
		modval = modval/multiplyBy;
		index++;
	}
	/*if((modval)/multiplyBy) < multiplyBy)
	{
		modval = ((modval -1)/multiplyBy) + 1;
	}
	else
	{
		modval = ((modval -1)/multiplyBy);
	}*/
	//cout << "getval is " << multiplier[modval- 1] << endl;
	cout << index << endl;
	return 	multiplier[index- 1];	
}



	/*
	int num = 0;
	int printval = 0;
	int prev = 0;
	int num1 = 1;
	int num2 = 3;
	int num3 = 9;
	int num4 = 27;
	int sum1 = num1; //1
	int sum2 = sum1 + num2; // 4 
	int sum3 = sum2 + num3; // 13
	int sum4 = sum3 + num4; //27
	
	for(int i = 1; i < weight; i++)
	{
	if(i > sum2)
	{
	printval = getval(i, num1, num1) * num1  
				+ getval(i, num2, num1 + num2) * num2 //3,3,4
				+ getval(i, num3, num1 + num2+ num3) * num3;
	}		
	else if(i > sum1)
	{	
	printval = getval(i, num1, num1) * num1
				+ getval(i, num2, num1 + num2) * num2 ;
	}
	else
	{
		
		printval = getval(i, num1, num1) * num1;
	}
	cout << printval << ",";
	
	
	//printval = getval(i, num1, num1) * num1 +
				// getval(i, num2, num1 + num2) * num2 
				/*+ getval(i, num3, num1 + num2+ num3) * num3 
				+ getval(i, num4, num1 + num2 + num3 + num4) * num4*/;
	
	
/*		if(i > sample.at(num))
		{
			num++;
		}
		for(int numtomultiply = 0; numtomultiply < 3; numtomultiply++)
		{
			printval = sample.at(num++) * multiplier[numtomultiply] ;
			printval += sample.at(num++) * multiplier[numtomultiply] ;
			printval += sample.at(num) * multiplier[numtomultiply] ;
			
		cout << printval << "," ;			
		}				
	}*/	