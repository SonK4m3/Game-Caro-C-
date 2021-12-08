/*-------------------------------------
	Name: GAME CARO 
	Copyright: (C) 2021
	Author: SonK4m3
	Description: 
	
	game caro 2 players in console
-------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

//--------------------------------

const int MAX = 9;
const int WinCondition_3 = 3;
const int WinCondition = 5;
bool display_STOP, game_STOP;

//-------------------------------

struct Board {
	int a[MAX][MAX];
	int n;
	int condition;
	int remains;	// so o chua danh
	
	int X_main[MAX][MAX];
	int X_side[MAX][MAX];
	int X_row[MAX][MAX];
	int X_col[MAX][MAX];
	
	int O_main[MAX][MAX];
	int O_side[MAX][MAX];
	int O_row[MAX][MAX];
	int O_col[MAX][MAX];
	
	int maxX;
	int maxO;
}board;

struct Player {
	char C;
	char in_turn;
}player1, player2;

//---------------------------------

void Print_board();
bool isInt(string s);
int Str_Int(string s);
void Continue();

//---------------------------------
// khoi tao nguoi choi
void Init_player(Player &p1, Player &p2){
	cout << "Player 1 chon X hoac O:\n";
	
	while(cin >> p1.C){
		if(p1.C == 'X' || p1.C == 'O'){
			if(p1.C == 'X'){
				cout << "Player 1 chon X - Player 2 chon O\n";
				p2.C = 'O';
			}
			else if(p1.C == 'O'){
				cout << "Player 1 chon O - Player 2 chon X\n";
				p2.C = 'X';
			}
			break;
		}
		else	cout << "getInput lai ...\n";	
	}
	
	p1.in_turn = 'Y';
	p2.in_turn = 'N';
}

// khoi tao ban co
void Init_board(){
	cout << "Nhap kich thuoc ban co:\n";
	while(cin >> board.n){
		if(board.n < 1 || board.n > MAX)
			cout << "Nhap lai kich thuoc ban co ...\n";
		else 
			break;
	}
	
	board.remains = board.n * board.n;
	board.condition = (board.n > 3) ? WinCondition : WinCondition_3;
	
	for(int i = 0; i < board.n; i ++){
		for(int j = 0; j < board.n; j++)
			board.a[i][j] = -1;
	}
}

// khoi tao game
void Init(){
	
	Init_board();
	
	Init_player(player1, player2);
	
	Print_board();	
}

//------------------------------------------
// in ban co
void Print_board(){
	if(!display_STOP){
		for(int i = 0; i <= board.n; i ++){
			if(i == 0)	cout << "  ";
			else cout << " " << i << " ";
		}
		
		cout << endl;
		
		for(int i = 0; i < board.n; i ++){
			cout << i + 1<< " ";
			for(int j = 0; j < board.n; j ++){
				if(board.a[i][j] == -1)
					cout << " - ";	
				else if(board.a[i][j] == 1)
					cout << " X ";
				else if(board.a[i][j] == 0)
					cout << " O ";
			}
			cout << endl;
		}
	}
}

// in thong bao 
void Print_notice(){
	if(!display_STOP){
		cout << "Nhap exit de thoat.\n";
	}
} 

//-------------------------------------------
// nhap input
void Get_input(Player &p1, Player &p2, string mes = "Player 1 turn: \n"){
	if(p1.in_turn == 'Y'){
		cout << mes;
			
		string input_player;
			
		scanf("\n");
		getline(cin, input_player);
		
		int x = 0, y = 0;
		char ch;
		
		vector<string> v;
		stringstream arr(input_player);
		
		while(!arr.eof()){
			string tmp;
			arr >> tmp;
			v.push_back(tmp);
		}
		
		if(v.size() == 3 && isInt(v[0]) && isInt(v[1]) && v[2].size() == 1){
			x = Str_Int(v[0]);
			y = Str_Int(v[1]);
			ch = v[2][0];
			if(x >= 1 && x <= board.n && y >= 1 && y <= board.n && v[2][0] == p1.C && board.a[x - 1][y - 1] == -1){
				if(ch == 'O')
					board.a[x - 1][y - 1] = 0;
				else if(ch == 'X')
					board.a[x - 1][y - 1] = 1;
				
				board.remains -= 1;
				
				p1.in_turn = 'N';
				p2.in_turn = 'Y';
				
				if(display_STOP)	display_STOP = false;
			}
			else if(x < 1 || x > board.n || y < 1 || y > board.n){
				cout << "Hay danh o trong ban co, Xin nhap lai ...\n";
				display_STOP = true;
			}
			else if(board.a[x - 1][y - 1] != -1){
				cout << "O da duoc danh, Xin nhap lai ...\n";
				display_STOP = true;
			}
			else if(v[2][0] != p1.C){
				cout << "Ban nhap sai X O, Xin nhap lai ...\n";
				display_STOP = true;
			}
			else{
				cout << "Sai du lieu, Xin nhap lai ...\n";
				display_STOP = true;
			}
		}
		else if(v.size() == 1 && v[0] == "exit"){
			cout << "exit game ...\n";
			display_STOP = true;
			game_STOP = true;
		}
		else{
			cout << "Sai du lieu, Xin nhap lai ...\n";
			display_STOP = true;
		}
	}
	else Get_input(p2, p1, "Player 2 turn: \n");
}

//-----------------------------------------------
//kiem tra ban co da duoc danh het chua
bool isFull(){
	return (board.remains == 0);
}

void setRow(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 0;

	for(int i = 0; i < n; i ++){
		int cnt = 0;
		for(int j = 0; j < n; j ++){
			if(mat[i][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[i][j] = cnt;
			Max = max(Max, cnt);
		}
	} 
}

void setCol(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 0;

	for(int j = 0; j < n; j ++){
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(mat[i][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[i][j] = cnt;
			Max = max(Max, cnt);
		}
	}
}

void setMain(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 0;
	

	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = 0; j < n - i; j ++){
			if(mat[k][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[k][j] = cnt;
			Max = max(Max, cnt);
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i < n - j; i++){
			if(mat[i][k] == value)
				cnt++;
			else 
				cnt = 0;
			res[i][k] = cnt;
			Max = max(Max, cnt);
			k++;
		}
	}
}

void setSide(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 0;
	
	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = n - 1; j >= i; j --){
			if(mat[k][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[k][j] = cnt;
			Max = max(Max, cnt);
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i <= n - j; i++){
			if(mat[i][k] == value)
				cnt ++;
			else
				cnt = 0;
			res[i][k] = cnt;
			k--;
		}
	}
}

//tim nguoi t thua
void Process(){
	
	setRow(board.a, board.X_row, board.n, 'X', board.maxX);
	setRow(board.a, board.O_row, board.n, 'O', board.maxO);
	
	setCol(board.a, board.X_col, board.n, 'X', board.maxX);
	setCol(board.a, board.O_col, board.n, 'O', board.maxO);
	
	setMain(board.a, board.X_main, board.n, 'X', board.maxX);
	setMain(board.a, board.O_main, board.n, 'O', board.maxO);
	
	setSide(board.a, board.X_side, board.n, 'X', board.maxX);
	setSide(board.a, board.O_side, board.n, 'O', board.maxO);
	
	if(isFull()){
		cout << "-----------\n";
		cout << "Draw!\n";
		Continue();
		return;
	}
	
	if(board.maxO == board.condition){
		cout << "------------\n";
		if(player1.C == 'O')
			cout << "Player 1 Win!\n";
		else
			cout << "Player 2 Win!\n";
		Continue();
		return;
	}
	
	if(board.maxX == board.condition){
		cout << "-------------\n";
		if(player1.C == 'X')
			cout << "Player 1 Win!\n";
		else
			cout << "Player 2 Win!\n";
		Continue();
		return;
	}
}

//---------------------------------------
//choi tiep voi kich thuoc khac
void Continue(){
	cout << "---------------------------\n";
	cout << "Nhap 1 de tiep tuc choi lai\n"
		 << "Nhap 0 de thoat.\n";
		 
	string a; cin >> a;
	if(a == "1") Init();
	else if(a == "0"){
		cout << "---------------\n"
			 << "Exit game.";
		game_STOP = true;
	}
	else {
		Continue();
	}
}

// in man hinh
void Display(){
	
	game_STOP = false;
	display_STOP = false;
	
	while(!game_STOP){
				
		Get_input(player1, player2);
			
		Print_board();
		
		Print_notice();
				
		Process();
	}	
}

//--------------------------------------
int main(){
	
	Init();
	
	Display();
}

//--------------------------------------
bool isInt(string s){
	for(int i = 0; i < s.size(); i++)
		if(s[i] < '0' && s[i] > '9')
			return false;
	return true;
}

int Str_Int(string s){
	int res = 0;
	for(int i = 0; i < s.size(); i++)
		res = res * 10 + s[i] - '0';
	return res;
}
