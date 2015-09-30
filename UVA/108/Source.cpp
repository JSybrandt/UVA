#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<complex>

using namespace std;

int main()
{

	//read everything
	int data[100][100]={0};
	int n;
	cin>>n;
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0 ; j < n; j++)
		{
			cin>>data[j][i]; //we are referencing [x][y] or [col][row] with tl corner at [0][0]
		}
	}

	//get cumulative sums for each col
	int sums[100][100]={0};
	for(int x=0;x<n;x++){
		int sum=0;
		for(int y=0;y<n;y++){
			sum+=data[x][y];
			sums[x][y]=sum;
		}
	}

	int result = -9999; //result is lower than the lowest possible value

	//try every row combo
	int subcols[100]={0};
	for(int a=0;a<n;a++)
		for(int b=a; b<n;b++){

			//fill subcol sums
			for(int i=0;i<n;i++){
				subcols[i]=sums[i][b];
				if(a>0)
					subcols[i]-=sums[i][a-1];
			}

			int val=0,large=0;
			for(int i=0;i<n;i++){
				val = max(0,val+subcols[i]);
				large = max(large,val);
			}

			result = max(large,result);

		}

	cout<<result<<endl;

	return 0;
}