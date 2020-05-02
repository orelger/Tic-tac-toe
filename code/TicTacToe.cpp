#include <iostream>
using namespace std;

void displayMap(char map[][3],int size){
	int i=0,j=0,z=0;

	cout << "   0   1   2"<<endl;
	for(i=0;i<size;i++){
		cout<<z;
		z++;
		for(j=0;j<size;j++){
			cout<<" "<<"|"<<map[i][j]<<"|";
		}
	cout<<endl;		
	}
	z=0;
}

bool chaeckMapPlayer1(char map[][3],int size,int line,int row)
{
	int win=0;
	for(int i=0;i<3;i++){
		if(map[line][i]=='X'){
			win++;				
		}
		else{
			win=0;
			break;
		}
	
		if(win==3){
			cout<<"player 1 win"<<endl;
			return true;
		}

	}
	
	for(int i=0;i<3;i++){
		if(map[i][row]=='X'){
			win++;				
		}
		else{
			win=0;
			break;
		}
	
		if(win==3){
			cout<<"player 1 win"<<endl;
			return true;
		}
	}

	if(map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X'){
		cout<<"player 1 win"<<endl;
			return true;
	}

	if(map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X'){
		cout<<"player 1 win"<<endl;
			return true;
	}

	return false;
}

bool chaeckMapPlayer2(char map[][3],int size,int line,int row)
{
	int win=0;
	for(int i=0;i<3;i++){
		if(map[line][i]=='O'){
			win++;				
		}
		else{
			win=0;
			break;
		}
	
		if(win==3){
			cout<<"player 2 win"<<endl;
			return true;
		}

	}
	
	for(int i=0;i<3;i++){
		if(map[i][row]=='O'){
			win++;				
		}
		else{
			win=0;
			break;
		}
	
		if(win==3){
			cout<<"player 2 win"<<endl;
			return true;
		}

	}

	if(map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O'){
		cout<<"player 2 win"<<endl;
			return true;
	}

	if(map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O'){
		cout<<"player 2 win"<<endl;
			return true;
	}
	return false;
}

bool gameOvaer(char map[][3],int size)
{
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(map[i][j]=='A'){
				return false;
			}
		}
	}
	return true;
}




int main()
{
	int line,row;
	char game1,game2;
	char map[3][3]={'A','A','A','A','A','A','A','A','A'};
	bool opp=false,gameover=false;
	cout<<"what do you want to choose: X or O"<<endl;
	cin>>game1;

	while(('X' != game1) && ('O' != game1)){
		cout<<"you can choose X or O"<<endl;
		cin>>game1;
	}

	cout<<"OK lets start:\n\n"<<endl;
	cout<<"Player 1 is X \nplayer 2 is O\n"<<endl;
	cout<<"player 1 starts to play"<<endl;
	displayMap(map,3);

	while(opp == false)
	{
		cout<<"player1: choose where do you want to put X in the board line and row"<<endl;
		cin >> line;
		cin >> row;
		map[line][row]='X';
		displayMap(map,3);
		opp=chaeckMapPlayer1(map,3,line,row);
		gameover=gameOvaer(map,3);
		if(opp == true)
			break;
		if(gameover == true)
		{
			cout<<"Game Over"<<endl;
			break;
		}
		
		cout<<"player2: choose where do you want to put X in the board line and row"<<endl;
		cin >> line;
		cin >> row;
		map[line][row]='O';
		displayMap(map,3);
		opp=chaeckMapPlayer2(map,3,line,row);
		gameover=gameOvaer(map,3);
		if(opp == true)
			break;
		if(gameover == true)
		{
			cout<<"Game Over"<<endl;
			break;
		}
	}

	cout<<"good bye"<<endl;
	
	return 0;
}