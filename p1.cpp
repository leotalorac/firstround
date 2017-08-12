#import <iostream>

using namespace std;

int main(){
	int n,num;
	int pos;
	cin>>n>>num;
	int rsup;
	int rinf;
	//distance
	int d=0;
	//get the numbers of the square
	for(int i =1;num>i*i;i+=2){
		rinf =i*i;
		rsup =(i+2)*(i+2);
		d++;
	}
	//cout<<"d:"<<d<<endl;
	rinf = rinf+1;
	int rank = rsup-rinf;
	int step = (rank+1)/4;
	//center init
	int center = (n+1)/2;
	int x = center;
	int y = center;	
	//cout<<"y: "<<y<<" x: "<<x<<endl;
	int op =0;
	if(num!=1){
	
		if(rinf<=num && num<=rinf+step-1){
			//top
			op=1;
		}
		else{
			rinf+=(step-1);
			for(int l=2;l<5;l++){
				if(rinf<=num && num<=rinf+step){
					//left, bot , right
					op=l;
					break;
				}
				rinf+=(step);			
			}
		}
		//redefine
		rsup = rinf+step;
		rank = rsup-rinf;
		int crank;
		if(op==1){
			rank-=1;
			crank = rank/2;
		}else{
			crank = (rank+1)/2;
		}
		//center of rank
		
		int numbers[rank];
		int pd=0;
		//full array
		for(int k=0;k<=rank;k++){
			numbers[k]=rinf+k;
		}
		//cout<<"numbers: ";
		/*for(int k=0;k<=rank;k++){
			cout<<numbers[k]<<" ";
		}*/
		for(int k=0;k<=rank;k++){
			if(numbers[k]==num){
				pd = k-crank;			
			}
		}
		//cout<<"Pd: " <<pd<<endl;
		//set the values
		switch(op){
			case 1:
				//top
				y+=d;
				x-=pd;
				break;
			case 2:
				//left
				y+=pd;
				x-=d;
				break;
			case 3:
				//button
				y-=d;
				x+=pd;
				break;
			case 4:
				//right
				y+=pd;
				x+=d;
				break;
		}
	}
	cout<<"Line = "<<y<<", column = "<<x<<".";
}
