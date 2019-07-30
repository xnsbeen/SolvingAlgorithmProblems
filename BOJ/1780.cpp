#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <math.h>
#include <sstream>

using namespace std;

int arr[2500][2500];
int w=0,b=0,p=0;
void color(int y,int x,int n){
	int c = arr[y][x];
	int chk = 0; 
	for(int i=y;i<y+n;++i)
		for(int j=x;j<x+n;++j){
			if(c!=arr[i][j]){
				chk=1;
				break;
			}
		}
	if(chk==1){
		color(y,x,n/3);
		color(y,x+n/3,n/3);
		color(y,x+n*2/3,n/3);
		color(y+n/3,x,n/3);
		color(y+n/3,x+n/3,n/3);
		color(y+n/3,x+n*2/3,n/3);
		color(y+n*2/3,x,n/3);
		color(y+n*2/3,x+n/3,n/3);
		color(y+n*2/3,x+n*2/3,n/3);
	}
	else{
		if(c==1) b++;
		else if(c==-1) p++; 
		else w++;
	}
}

int main(int argc, char* argv[]) {
	int n;
	cin>>n;
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&arr[i][j]);
	color(0,0,n);
	cout<<p<<endl<<w<<endl<<b<<endl;
	return 0;
}
