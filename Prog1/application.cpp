#include "application.h"
#include "number.h"
#include "matrix.h"

using namespace std;

Tapplication::Tapplication()
{


}
int Tapplication::exec()
{
	HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int select;
	Tmatrix matrix;
	int capacity;

	while (true)
	{
		select = menu();
		switch (select)
		{
		case 49:
			system("cls");
			printf("fill in the capacity = ");
			cin >> capacity;
			matrix.FillMatrix(capacity);
			break;
		case 50:
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Matrix's determinant: " << matrix.PrintDet() << endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);
			break;
		case 51:
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Here is your's matrix transposition: "<< endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			matrix.Transposition();
			matrix.PrintMatrix();
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);
			break;
			break;
		case 52:
		{
			system("cls");
			cout << "4\n";
		}
		break;
		case 53:
		{
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Here is your matrix:" << endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			matrix.PrintMatrix();
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);
		}
		break;
		case 27:
			system("cls");
			cout << "Good bye\n";
			return 0;
			break;
		default:
			break;

		}
	}
}

int Tapplication::menu()
{
	printf("1 - fill in matrix\n");
	printf("2 - find determinant\n");
	printf("3 - transpositioning\n");
	printf("4 - rang\n");
	printf("5 - print current matrix\n");
	printf("esc - exit\n");
	printf("_________________________________________________________________________________________________________________________________\n");
	int select = _getch();
	return select;

}