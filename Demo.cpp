#include<bits/stdc++.h>
using namespace std;

const int MAX = 9;
bool display_STOP, game_STOP;

struct Banco {
	int a[MAX][MAX];
	int n;
}banco;

struct Player {
	char C;
	char in_turn;
}player1, player2;

void inbanco();
bool isInt(string s);
int Str_Int(string s);

// khoi tao nguoi choi
void khoitao_player(Player &p1, Player &p2){
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
		else	cout << "Nhap lai ...\n";	
	}
	
	p1.in_turn = 'Y';
	p2.in_turn = 'N';
}

// khoi tao ban co
void khoitao_banco(){
	cout << "Nhap kich thuoc ban co:\n";
	while(cin >> banco.n){
		if(banco.n < 1 || banco.n > MAX)
			cout << "Nhap lai kich thuoc ban co ...\n";
		else 
			break;
	}
	
	for(int i = 0; i < banco.n; i ++){
		for(int j = 0; j < banco.n; j++)
			banco.a[i][j] = -1;
	}
}

// khoi tao game
void khoitao(){
	
	khoitao_banco();
	
	khoitao_player(player1, player2);
	
	inbanco();	
}

// in ban co
void inbanco(){
	if(!display_STOP){
		for(int i = 0; i <= banco.n; i ++){
			if(i == 0)	cout << "  ";
			else cout << " " << i << " ";
		}
		
		cout << endl;
		
		for(int i = 0; i < banco.n; i ++){
			cout << i + 1<< " ";
			for(int j = 0; j < banco.n; j ++){
				if(banco.a[i][j] == -1)
					cout << " - ";	
				else if(banco.a[i][j] == 1)
					cout << " X ";
				else if(banco.a[i][j] == 0)
					cout << " O ";
			}
			cout << endl;
		}
	}
}

// in thong bao 
void inthongbao(){
	if(!display_STOP){
		cout << "Nhap nuoc co tiep theo\n";
		cout << "Nhap exit de thoat.\n";
	}
} 

// nhap input
void nhap(Player &p1, Player &p2, string mes = "Player 1 turn: \n"){
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
			if(x >= 1 && x <= banco.n && y >= 1 && y <= banco.n && v[2][0] == p1.C && banco.a[x - 1][y - 1] == -1){
				if(ch == 'O')
					banco.a[x - 1][y - 1] = 0;
				else if(ch == 'X')
					banco.a[x - 1][y - 1] = 1;
				
				p1.in_turn = 'N';
				p2.in_turn = 'Y';
				if(display_STOP)	display_STOP = false;
			}
			else if(banco.a[x - 1][y - 1] != -1){
				cout << "O da duoc danh, Xin nhap lai ...\n";
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
	else nhap(p2, p1, "Player 2 turn: \n");
}

// in man hinh
void Display(){
	
	game_STOP = false;
	display_STOP = false;
	
	while(!game_STOP){
				
		nhap(player1, player2);
			
		inbanco();
	}	
}

int main(){
	
	khoitao();
	
	Display();
}

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
