#include <iostream>

using namespace std;

char X(int h, int v, char board[3][3]){
	if (board[h][v]=='p'){
		board[h][v]='X';
	}
	return(board[3][3]);
}

char O(int h, int v, char board[3][3]){
	if (board[h][v]=='p'){
		board[h][v]='O';
	}
	return(board[3][3]);
}

void update(char board[3][3]){
	for (int i=0;i<3;++i){
		for (int j=0;j<3;++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void checker(int h, int v){
	if ((h!=1) && (h!=2) && (h!=3)){
		cout<<endl<<"Your coordinates must be 0,1, or 2"<<endl;
	}
	if ((v!=1) && (v!=2) && (v!=3)){
		cout<<endl<<"Your coordinates must be 0,1, or 2"<<endl;
	}
}

int didwin(char board[3][3]){
	int win = 0;
	if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){win = 1;}
	else if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){win = 1;}
	else if((board[0][0] == board[1][0]) && (board[1][0] == board[2][0])){win = 1;}
	else if((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])){win = 1;}
	else if((board[0][2] == board[1][2]) && (board[1][2] == board[2][2])){win = 1;}
	else if((board[0][0] == board[1][0]) && (board[1][0] == board[2][0])){win = 1;}
	else if((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])){win = 1;}
	else if((board[0][2] == board[1][2]) && (board[1][2] == board[2][2])){win = 1;}
	return(win);
}

int main(int argc, char** argv) {
	char board [3][3] = {
	{'p','p','p'},
	{'p','p','p'},
	{'p','p','p'}
	};
	update(board);
	int win = 0;
	while (win == 0){
		cout<<endl<<"Player 1: Enter Coordinates:"<<endl;
		int h;
		int v;
		cin >> h;
		cin >> v;
		checker(h,v);
		X(h,v,board);
		update(board);
		int win = didwin(board);
		cout<<endl<<"Player 2: Enter Coordinates:"<<endl;
		cin >> h;
		cin >> v;
		checker(h,v);
		O(h,v,board);
		update(board);
		win = didwin(board);
	}
	return 0;
}
