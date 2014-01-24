/*TIC TAC TOE 5x5*/

#include <iostream>
#include <conio.h>
#include <conio2.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

class TicTacToe
{
	public:
		TicTacToe();      
		void initializeBoard();
		void PrintBoard();
		void getInput( char ,size_t&,size_t&);
		bool OccupySquare(size_t,size_t, char );
		char CheckForWinner();
		bool checkHorizontal( char );
		bool checkVertical( char );
		bool checkDiagonal( char );
		bool IsScratch();
		void printWinner(char);
		bool IsValidLocation( size_t,size_t);     
		void InitializeBoard();
		static const size_t rows = 5;
		static const size_t cols = 5;
	private:
		char board[rows][cols];
};

int main(int argc, char** argv) 
{
	
	int menu;
		
	SetConsoleTitle("- : : TIC TAC TOE : : -");
	textbackground(WHITE);
	textcolor(BLACK);

	do{
		
		system("cls");
		cout<<" ========================"<<endl;
		cout<<" | GAME TIC TAC TOE 5x5 |"<<endl;
		cout<<" ========================"<<endl;
		cout<<" | 1. Main              |"<<endl;
		cout<<" | 2. Keluar            |"<<endl;
		cout<<" ========================"<<endl;
		cout<<"  Masukkan pilihan : "; cin>>menu;
		
		switch(menu)
        {
			case 1:
            	{			
					system("cls");
					cout<<"========================"<<endl;
		        	cout<<"GAME TIC TAC TOE 5x5"<<endl;
                	cout<<"========================"<<endl;
					size_t r,c;
					char winner;

					TicTacToe a;
					while(true)
                	{
						//PEMAIN PERTAMA MULAI
						a.getInput('X',r,c);
						a.PrintBoard();
						winner=a.CheckForWinner();
						if (winner!=' ') //JIKA PEMAIN PERTAMA MENANG, KELUAR DARI PENGULANGAN
							break;
		
						//PEMAIN KEDUA MULAI
						a.getInput('O',r,c);
						a.PrintBoard();
						winner=a.CheckForWinner();
						if (winner!=' ') //JIKA PEMAIN KEDUA MENANG, KELUAR DARI PENGULANGAN
							break;
					}
					a.printWinner(winner);
					getch();
		     	}
				break;
			
			case 2:
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				textcolor(LIGHTBLUE);
				cout<<"              ====================================================="<<endl;
				cout<<"                   Terima Kasih sudah menggunakan program Kami"<<endl;
				cout<<"               Silakan tekan sembarang tombol untuk keluar program"<<endl;
				cout<<"              ====================================================="<<endl<<endl<<endl<<endl;
				textcolor(BLACK);
				break;
			
			default: 
				textcolor(LIGHTRED);
				cout<<"   Maaf! Pilihan Anda tidak terdefinisi!"<<endl;
				cout<<"   Tekan sembarang tombol untuk kembali memilih menu!"<<endl<<endl;
				textcolor(BLACK);
				getch();
				break;
		}
        		
	}while(menu!=2);
	return 0;
}

// PENGINISIALISASIAN PAPAN PERMAINAN
TicTacToe::TicTacToe()
{ 
	InitializeBoard();
}

void TicTacToe::InitializeBoard()
{for (int i = 0; i<rows; i++)
	{for (int j = 0; j<cols; j++)
    	{
			board[i][j]= ' ';
		}
    }   
}

// MENAMPILKAN PAPAN UNTUK DIISI KARAKTER "X" ATAU "O"
void TicTacToe::PrintBoard()
{
	int t;
	cout<<endl;
	cout<<"\n---|---|---|---|---\n";
	for(t=0; t<5; t++) 
	{
		cout<<" "<<board[t][0]<<" | "<< board[t][1]<<" | "<< board[t][2]<<" | "<< board[t][3]<<" | "<< board[t][4];  
    	if(t!=4) cout<<"\n---|---|---|---|---\n";
  	}
  	cout<<"\n---|---|---|---|---\n";
	cout<<endl; 
}

// MEMERIKSA APAKAH ADA SESEORANG YANG MENANG
char TicTacToe:: CheckForWinner()
{
	if (checkHorizontal('X'))
	{
 		return 'X';
	}
	if (checkVertical( 'X'))
	{
		return 'X';
	}
	if (checkDiagonal( 'X'))
	{
		return 'X';
	}
	if (checkHorizontal('O'))
	{
		return 'O';
	}
	if (checkVertical('O'))
	{
		return 'O';
	}
	if (checkDiagonal('O'))
	{	
		return 'O';
	}
	if (IsScratch())
	{
		return 'T';
	}
	return ' ';
}

// MEMERIKSA KEMENANGAN DALAM KEADAAN HORIZONTAL PADA PAPAN
bool TicTacToe::checkHorizontal(char marker)
{
	int i,j,count;
	for(i=0; i<rows; i++)
	{
		count=0;
		for(j=0;j<cols;j++)
		if(board[i][j]==marker)
			count++;
		if(count==5)
    		return true;
    }
	return false;
}

// MEMERIKSA KEMENANGAN DALAM KEADAAN VERTIKAL PADA PAPAN
bool TicTacToe::checkVertical(char marker)
{
	int i,j,count;
	for(i=0; i<rows; i++)
	{
		count=0;
    	for(j=0;j<cols;j++)
		if(board[j][i]==marker)
           count++;
    	if(count==5)
			return true;
    }
	return false;
}

// MEMERIKSA KEMENANGAN DALAM KEADAAN DIAGONAL PADA PAPAN
bool TicTacToe::checkDiagonal(char marker)
{
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2]&& board[2][2]==board[3][3]&& board[3][3]==board[4][4]&& board[0][0]==marker)
		return true;
	if(board[0][4]==board[1][3] && board[1][3]==board[2][2] && board[2][2]==board[3][1] && board[3][1]==board[4][0] && board[0][4]==marker)
		return true;
	return false;
}

// MEMERIKSA JIKA PERMAINAN SERI
bool TicTacToe::IsScratch()
{
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			if(board[i][j]==' ')
                return false;
	return true;
}

// MENAMPILKAN PEMENANG ATAU PERMAINAN SERI
void TicTacToe::printWinner(char marker)
{
	if(marker=='T')
		cout<<"PERMAINAN SERI!\n";
  	else
		cout<<"Pemenangnya adalah "<<marker<<"!!!\n";
}

// PENANDA KARAKTER "X" ATAU "O" YG DIINPUTKAN PEMAIN
void TicTacToe::getInput(char marker,size_t &r,size_t &c)
{
	for(;;)
	{
        cout<<endl;
		cout<<"Pemain "<<marker<<endl;
    	cout << "Masukkan baris(1-5): " ;
    	cin >> r;
    	cout << "Masukkan kolom(1-5): " ;
    	cin >> c;
    	if (OccupySquare(r,c,marker) )
        {
			return ;
        }
		cout << "Papan sudah terisi: ULANGI\n\n";
    }
}

// MEMVALIDASI APAKAH TEMPAT YANG AKAN DIISI TERSEDIA ATAU SUDAH TERISI
bool TicTacToe::IsValidLocation(size_t r,size_t c)
{
	if(r<1||r>rows||c<0||c>cols)
		return false;
	if(board[r-1][c-1]!=' ')
		return false;
 	else
		return true;
}

// MENANDAI JIKA SESEORANG SUDAH MENANG DENGAN BOOLEAN
bool TicTacToe::OccupySquare( size_t r,size_t c, char marker)
{
	if(IsValidLocation(r,c))
    {
		board[r-1][c-1]=marker;
     	return true;
    }
	return false;
}
