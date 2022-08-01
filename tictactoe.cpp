#include<iostream>
#include<string.h>
using namespace std;
class TICKTACTOE
{
    char p1,p2;
	char ttt[3][3];
	int tts[3][3],counter,w,sum;
    public:
        TICKTACTOE()
        {   
			sum=0;
        	counter=1;
        	w=0;
             for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    ttt[i][j]=0;
        			tts[i][j]=counter++;  
					    
                }   
            	
			}
        }
        
void input1()
	{
				int r,c,t;
    				cout<<"Player1 pls enter location"<<endl;
    				cin>>t;
    				if(t>=1 && t<=3){
    					r=0;
    					c=t-1;
					}
					else if(t>=4&& t<=6){
    					r=1;
    					c=t-4;
					}
					else if(t>=7 && t<=9){
						r=2;
						c=t-7;
					}
					
    				if(check(r,c,1)==0){
					ttt[r][c]=p1; sum++;
					input2();
					
					
				}
			play(p1);
					
	}
		
void input2()
	{
		int r,c,t;
    				cout<<"Player2 pls enter location"<<endl;
    				cin>>t;
    				if(t>=0&& t<=2){
    					r=0; c=t-1;
					}
					else if(t>=3&& t<=5){
    					r=1; c=t-4;
					}
					else if(t>=6 && t<=9){
						r=2; c=t-7;
					}
					    			
    			if(check(r,c,2)==0){				
				ttt[r][c]=p2; sum++;
				}
			
			play(p2);
	}
	
void sign()
	{
		char signs;
		cout<<"pls choose X or O"<<endl;
		cout<<"player 1: "<<endl;	
		cin>>signs;
		if(signs=='X'){
			p1='X';
			p2='O';
		}
		else if(signs=='O'){
		p1='O';
		p2='X';
		}
		else {
			cout<<"invalid charater"<<endl;
			sign();
		}
		cout<<"Player1 sign is "<<p1<<endl<<"player2 sign is "<<p2<<endl;
	}
	
void display()
	{
    system("cls");
    cout<<"WELCOME TO TICK TAC TOE"<<endl;
    cout<<" \t\t-----------------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Row "<<i<<"\t\t|";
        for(int j=0;j<3;j++){
            cout<<"_"<<ttt[i][j];
            cout<<"_"<<" |";
        	}
        
    	cout<<endl;
    	
		}
	    cout<<" \t\t-----------------"<<endl;
	    for(int i=0;i<3;i++){
        cout<<"\t\t\t|";
        for(int j=0;j<3;j++){
            cout<<"_"<<tts[i][j];
            cout<<"_"<<" |";
        	}
        
    	cout<<endl;
    	
		}
		if(sum==8){
			cout<<"Try again later"<<endl;
			TICKTACTOE();
			sign();
			display();
			sum=0;
		}
		input1();   		
    }
    
int check(int r,int c,int i)
{
		if(ttt[r][c]==0){
			return 0;
		}
		else
		{
			cout<<"Invalid move"<<endl;
			if(i=1){
			input1();
		}
		else if(i=2){
		input2();
	}
		}
		
		
}	
void play(char pl)
	{
		for(int i=0;i<3;i++)
		{
			if(ttt[i][0]==ttt[i][1] && ttt[i][1]==ttt[i][2] && ttt[i][2]=='X')
			{
				if(p1=='X' && p2=='O')
					{
						winner(1);
						w=1;	
					}
				else 
					{
						winner(2);
						w=1;			
					}
			}	
				if(ttt[i][0]==ttt[i][1] && ttt[i][1]==ttt[i][2] && ttt[i][2]=='O')
				{
					if(p1=='O' && p2=='X')
					{
						winner(1);
						w=1;	
					}
				else 
					{
						winner(2);
						w=1;			
							
				}	
					
			
			break;
		}
			for(int j=0;j<3;j++)
			{
				int i=0;
			  if(ttt[i][j]==ttt[i+1][j] && ttt[i+1][j]==ttt[i+2][j] && ttt[i+2][j]=='X')
				{
					if(p1=='X' && p2=='O')
					{
						winner(1);
						w=1;
					}
				else
					{
						winner(2);
						w=1;			
					}
					
					
					
				}
				if(ttt[i][j]==ttt[i+1][j] && ttt[i+1][j]==ttt[i+2][j] && ttt[i+2][j]=='O'){
					if(p1=='O' && p2=='X')
					{
						winner(1);
						w=1;
					}
				else
					{
						winner(2);
						w=1;			
					}
				}
			break;
			}
			
			 if(ttt[0][0]==ttt[1][1] && ttt[1][1]==ttt[2][2] && ttt[2][2]=='X'){
					if(p1=='X' && p2=='O')
					{
						winner(1);
						w=1;	
					}
				else
					{
						winner(2);
						w=1;			
					}	
				}
				if(ttt[0][0]==ttt[1][1] && ttt[1][1]==ttt[2][2] && ttt[2][2]=='O'){
						if(p1=='O' && p2=='X')
					{
						winner(1);
						w=1;
					}
				else
					{
						winner(2);
						w=1;			
					}
				}	
			  if(ttt[0][2]==ttt[1][1] && ttt[1][1]==ttt[2][0] && ttt[0][2]=='X'){
					if(p1=='X' && p2=='O')
					{
						winner(1);
						w=1;	
					}
				else
					{
						winner(2);
						w=1;			
					}
			}
			if( ttt[0][2]==ttt[1][1] && ttt[1][1]==ttt[0][2] && ttt[2][0]=='O'){
						if(p1=='O' && p2=='X')
					{
						winner(1);
						w=1;
					}
				else
					{
						winner(2);
						w=1;			
					}
			}
			//quit();	
			display();
	}
	}	


void winner(int i){
	int sum=0;
	if(i=1){
	system("cls");
	 cout<<" \t\t\t\t-----------------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"\t\t\t\t|";
        for(int j=0;j<3;j++){
            cout<<"_"<<ttt[i][j];
            cout<<"_"<<" |";
        	}
        
    	cout<<endl;
    	
		}
	    cout<<" \t\t\t\t-----------------"<<endl;
	    cout<<endl<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|\t\t player1\t\t\t|"<<endl;
	cout<<"|\t\t  Wins\t\t\t\t|"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<endl;
	exit(0);
	}
	if(i=2)
		{
	system("cls");
	cout<<"-------------------------------------------------"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|\t\t player2\t\t\t|"<<endl;
	cout<<"|\t\t  Wins\t\t\t\t|"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<endl;	
	exit(0);
		}
		if(i=3){
			
	system("cls");
	 cout<<" \t\t\t\t-----------------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"\t\t\t\t|";
        for(int j=0;j<3;j++){
            cout<<"_"<<ttt[i][j];
            cout<<"_"<<" |";
        	}
        
    	cout<<endl;
    	
		}
	    cout<<" \t\t\t\t-----------------"<<endl;
		}
	}

};

int main(){
	TICKTACTOE t;
	t.sign();
	t.display();
//	t.winner();
}
