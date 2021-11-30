#include<iostream>
using namespace std;

const int MAX = 20;

struct Banco {
	int a[MAX][MAX];
	int n;
}banco;

struct Player {
	char C;
	char in_turn;
}player1, player2;

void inbanco();

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
	cin >> banco.n;
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

// in ra man hinh
void inthongbao(){
	cout << "Nhap nuoc co tiep theo\n";
	cout << "Nhap -1 de thoat.\n";
}

void Display(){
	while(true){
		inthongbao();
		
		// nhap input tam thoi. 
		
		int x, y;
		char c;
		cin >> x >> y >> c;
		if(x == -1){
			cout << "Exit...";
			break;
		}
		if(x >= 0 && x <= banco.n && y >= 0 && y <= banco.n && (c == 'X' || c == 'O') && banco.a[x - 1][y - 1] == -1){
			if(c == 'X')
				banco.a[x - 1][y - 1] = 1;
			else
				banco.a[x - 1][y - 1] = 0;
		}
		else
			cout << "Moi nhap lai...\n";
				
		//
			
		inbanco();
	}	
}

int main(){
	
	khoitao();
	
	Display();
}
