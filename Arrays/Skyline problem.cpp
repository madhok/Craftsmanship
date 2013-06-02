//Skyline problem
class Building
{
	int left;
	int width;
	int height;	
};


void DrawSkyline(vector<Building> building)
{
	vector<int>height(building.size()) = 0;
	for(int i = 0; i < building.size(); i++)
	{
		for(int position = building[i].left; position < building[i].width; position++)
		{
			if(height[position] < building[position])
				height[position] = building[position];
		}
	}

	DrawLine(0, height[0]);
	for(int i = 1; i < height.size(); i++)
	{
		DrawLine(height[i-1], height[i]);
	}
	DrawLine(height.size(), 0);
}