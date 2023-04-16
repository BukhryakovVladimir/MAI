#include <windows.h>
#include <iostream>
#include "Classes.h"	//���������� �������
extern HDC hdc;      // �������  �������� ����������

// ������ ��� �������� ��������� ���������� � �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*-----------------------------------------------------------------------*/
/*        ������ ������������ ������ Shape          */
/*----------------------------------------*/

Shape::Shape(int InitX, int InitY, int InitRdius) { X = InitX; Y = InitY; Length = InitRdius; };

  //�������� X ���������� �����
int Shape::GetX(void){return X;};

  //�������� Y ���������� �����
int Shape::GetY(void){return Y;};

 //�������� �����
void Shape::Show(void)
{
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//������ ������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 ����� ��� ��������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}
 
 //������ �����
void Shape::Hide(void)
{
	SetPixel(hdc, X    , Y    , RGB(0, 0, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X + 1, Y    , RGB(0, 0, 255));
	SetPixel(hdc, X    , Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}

void Shape::Expand(int DeltaLen)
{
	Hide();             //�������� ���������� �� ������ ��������
	Length += DeltaLen; //�������� ������ 
	if (Length < 0)     //��� �������������� ���������� �������
		Length = 5;
	Show();             //�������� ���������� � ����� ��������
}

void Shape::Reduce(int DeltaLen) { Expand(-DeltaLen); }

//����������� �����
void Shape::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};

void Shape::Drag(int Step)    //���������� ������
{
	int FigX, FigY;   //����� ���������� ������

	FigX = GetX();    //�������� ��������� ��������� ������
	FigY = GetY();

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			FigX -= Step;
			MoveTo(FigX, FigY);
			Sleep(60);
		}

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			FigX += Step;
			MoveTo(FigX, FigY);
			Sleep(60);
		}

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			FigY += Step;
			MoveTo(FigX, FigY);
			Sleep(60);
		}

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			FigY -= Step;
			MoveTo(FigX, FigY);
			Sleep(60);
		}
} 

/*-----------------------------------------------------------------------*/
/*        ������ ������ Glass            */
/*----------------------------------------*/
Glass::Glass(int InitX, int InitY, int InitLength):Shape(InitX, InitY, InitLength) {}

void Glass::Show(void)
{

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); //������� ����
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)

	POINT Glass[4] = { {X - 7 * Length, Y - 18 * Length}, {X + 7 * Length, Y - 18 * Length},
		{ X + 5 * Length, Y + 7 * Length}, {X - 5 * Length, Y + 7 * Length}, };
	
	POINT Straw[7] = { {X - 1 * Length, Y - 18 * Length}, {X - 1 * Length, Y - 22 * Length}, {X + 1 * Length, Y - 23 * Length},
		{X + 5 * Length, Y - 23 * Length}, {X + 5 * Length, Y - 21 * Length}, { X + 1 * Length, Y - 21 * Length}, {X + 1 * Length, Y - 18 * Length } };
	
	//������� �� ������� ����� �������
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(65, 105, 225)));
	Polygon(hdc, Glass, 4);
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(169, 169, 169)));
	Polygon(hdc, Straw, 7);
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
	Ellipse(hdc, X - 3 * Length, Y - 13 * Length, X + 3 * Length, Y - 7 * Length);
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Ellipse(hdc, X - 3 * Length, Y - 11 * Length, X + 3 * Length, Y - 7 * Length);
	// ��������� ���� ��������� �������
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

void Glass::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)    

	POINT Glass[4] = { {X - 7 * Length, Y - 18 * Length}, {X + 7 * Length, Y - 18 * Length},
	{ X + 5 * Length, Y + 7 * Length}, {X - 5 * Length, Y + 7 * Length}, };

	POINT Straw[7] = { {X - 1 * Length, Y - 18 * Length}, {X - 1 * Length, Y - 22 * Length}, {X + 1 * Length, Y - 23 * Length},
		{X + 5 * Length, Y - 23 * Length}, {X + 5 * Length, Y - 21 * Length}, { X + 1 * Length, Y - 21 * Length}, {X + 1 * Length, Y - 18 * Length } };

	//������� �� ������� ����� �������
	Polygon(hdc, Glass, 4);
	Polygon(hdc, Straw, 7);
	Ellipse(hdc, X - 3 * Length, Y - 13 * Length, X + 3 * Length, Y - 7 * Length);
	Ellipse(hdc, X - 3 * Length, Y - 11 * Length, X + 3 * Length, Y - 7 * Length);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}


/*-----------------------------------------------------------------------*/
/*        ������ ������ Sandwich            */
/*----------------------------------------*/
Sandwich::Sandwich(int InitX, int InitY, int InitLength):Shape(InitX, InitY, InitLength) {}

void Sandwich::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(242, 242, 242)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)

	POINT UpperBread[4] = { {X - 8 * Length, Y - 4 * Length}, {X - 8 * Length, Y + -2 * Length},
		{ X + 7 * Length, Y + -2 * Length}, {X + 7 * Length, Y - 4 * Length}, };

	POINT Cheese[4] = { {X - 8 * Length, Y - 2 * Length}, {X - 8 * Length, Y - 1 * Length},
		{ X + 7 * Length, Y - 1 * Length}, {X + 7 * Length, Y - 2 * Length}, };

	POINT Cutlet[4] = { {X - 8 * Length, Y -1 * Length}, {X - 8 * Length, Y + 1 * Length},
		{ X + 7 * Length, Y + 1 * Length}, {X + 7 * Length, Y -1 * Length}, };

	POINT LowerBread[4] = { {X - 8 * Length, Y + 1 * Length}, {X - 8 * Length, Y + 3 * Length},
		{ X + 7 * Length, Y + 3 * Length}, {X + 7 * Length, Y + 1 * Length}, };

	//������� �� ������� ����� �������
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(218, 165, 32)));
	Polygon(hdc, UpperBread, 4);
	Polygon(hdc, LowerBread, 4);
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 0)));
	Polygon(hdc, Cheese, 4);
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(105, 61, 61)));
	Polygon(hdc, Cutlet, 4);

	
	// ��������� ���� ��������� �������
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

void Sandwich::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)    

	POINT UpperBread[4] = { {X - 8 * Length, Y - 4 * Length}, {X - 8 * Length, Y + -2 * Length},
		{ X + 7 * Length, Y + -2 * Length}, {X + 7 * Length, Y - 4 * Length}, };

	POINT Cheese[4] = { {X - 8 * Length, Y - 2 * Length}, {X - 8 * Length, Y - 1 * Length},
		{ X + 7 * Length, Y - 1 * Length}, {X + 7 * Length, Y - 2 * Length}, };

	POINT Cutlet[4] = { {X - 8 * Length, Y - 1 * Length}, {X - 8 * Length, Y + 1 * Length},
		{ X + 7 * Length, Y + 1 * Length}, {X + 7 * Length, Y - 1 * Length}, };

	POINT LowerBread[4] = { {X - 8 * Length, Y + 1 * Length}, {X - 8 * Length, Y + 3 * Length},
		{ X + 7 * Length, Y + 3 * Length}, {X + 7 * Length, Y + 1 * Length}, };

	//������� �� ������� ����� �������
	Polygon(hdc, UpperBread, 4);
	Polygon(hdc, LowerBread, 4);
	Polygon(hdc, Cheese, 4);
	Polygon(hdc, Cutlet, 4);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 

}
/*-----------------------------------------------------------------------*/
/*        ������ ������ FrenchFries            */
/*----------------------------------------*/
FrenchFries::FrenchFries(int InitX, int InitY, int InitLength):Shape(InitX, InitY, InitLength) {}


void FrenchFries::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)
	
	POINT Packet[4] = { {X - 7 * Length, Y - 8 * Length}, {X - 5 * Length, Y + 7 * Length},
		{ X + 8 * Length, Y + 7 * Length}, {X + 10 * Length, Y - 8 * Length}, };

	POINT stick1[4] = { {X - 5 * Length, Y - 8 * Length}, {X - 5 * Length, Y - 12 * Length},
		{ X - 3 * Length, Y -12 * Length}, {X - 3 * Length, Y - 8 * Length}, };

	POINT stick2[4] = { {X - 3 * Length, Y - 8 * Length}, {X - 3 * Length, Y - 12 * Length},
		{ X - 1 * Length, Y - 12 * Length}, {X - 1 * Length, Y - 8 * Length}, };

	POINT stick3[4] = { {X - 1 * Length, Y - 8 * Length}, {X - 1 * Length, Y - 12 * Length},
		{ X + 1 * Length, Y - 12 * Length}, {X + 1 * Length, Y - 8 * Length}, };

	POINT stick4[4] = { {X + 1 * Length, Y - 8 * Length}, {X + 1 * Length, Y - 12 * Length},
		{ X + 3 * Length, Y - 12 * Length}, {X + 3 * Length, Y - 8 * Length}, };

	POINT stick5[4] = { {X + 3 * Length, Y - 8 * Length}, {X + 3 * Length, Y - 12 * Length},
		{ X + 5 * Length, Y - 12 * Length}, {X + 5 * Length, Y - 8 * Length}, };

	POINT stick6[4] = { {X + 5 * Length, Y - 8 * Length}, {X + 5 * Length, Y - 12 * Length},
		{ X + 7 * Length, Y - 12 * Length}, {X + 7 * Length, Y - 8 * Length}, };
	
	POINT stick7[4] = { {X + 7 * Length, Y - 8 * Length}, {X + 7 * Length, Y - 12 * Length},
		{ X + 9 * Length, Y - 12 * Length}, {X + 9 * Length, Y - 8 * Length}, };

	//������� �� ������� ����� �������
	Polygon(hdc, Packet, 4);
	(HBRUSH)SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 0)));
	Polygon(hdc, stick1, 4);
	Polygon(hdc, stick2, 4);
	Polygon(hdc, stick3, 4);
	Polygon(hdc, stick4, 4);
	Polygon(hdc, stick5, 4);
	Polygon(hdc, stick6, 4);
	Polygon(hdc, stick7, 4);
	// ��������� ���� ��������� �������
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

void FrenchFries::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)    

	POINT Packet[4] = { {X - 7 * Length, Y - 8 * Length}, {X - 5 * Length, Y + 7 * Length},
		{ X + 8 * Length, Y + 7 * Length}, {X + 10 * Length, Y - 8 * Length}, };

	POINT stick1[4] = { {X - 5 * Length, Y - 8 * Length}, {X - 5 * Length, Y - 12 * Length},
		{ X - 3 * Length, Y - 12 * Length}, {X - 3 * Length, Y - 8 * Length}, };

	POINT stick2[4] = { {X - 3 * Length, Y - 8 * Length}, {X - 3 * Length, Y - 12 * Length},
		{ X - 1 * Length, Y - 12 * Length}, {X - 1 * Length, Y - 8 * Length}, };

	POINT stick3[4] = { {X - 1 * Length, Y - 8 * Length}, {X - 1 * Length, Y - 12 * Length},
		{ X + 1 * Length, Y - 12 * Length}, {X + 1 * Length, Y - 8 * Length}, };

	POINT stick4[4] = { {X + 1 * Length, Y - 8 * Length}, {X + 1 * Length, Y - 12 * Length},
		{ X + 3 * Length, Y - 12 * Length}, {X + 3 * Length, Y - 8 * Length}, };

	POINT stick5[4] = { {X + 3 * Length, Y - 8 * Length}, {X + 3 * Length, Y - 12 * Length},
		{ X + 5 * Length, Y - 12 * Length}, {X + 5 * Length, Y - 8 * Length}, };

	POINT stick6[4] = { {X + 5 * Length, Y - 8 * Length}, {X + 5 * Length, Y - 12 * Length},
		{ X + 7 * Length, Y - 12 * Length}, {X + 7 * Length, Y - 8 * Length}, };

	POINT stick7[4] = { {X + 7 * Length, Y - 8 * Length}, {X + 7 * Length, Y - 12 * Length},
		{ X + 9 * Length, Y - 12 * Length}, {X + 9 * Length, Y - 8 * Length}, };

	//������� �� ������� ����� �������
	Polygon(hdc, Packet, 4);
	Polygon(hdc, stick1, 4);
	Polygon(hdc, stick2, 4);
	Polygon(hdc, stick3, 4);
	Polygon(hdc, stick4, 4);
	Polygon(hdc, stick5, 4);
	Polygon(hdc, stick6, 4);
	Polygon(hdc, stick7, 4);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

/*-----------------------------------------------------------------------*/
/*        ������ ������ Human            */
/*----------------------------------------*/

Human::Human(int InitX, int InitY, int InitLength):Shape(InitX, InitY, InitLength) {}

void Human::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)

	POINT Legs[3] = { {X - 15 * Length, Y + 60 * Length}, {X + Length, Y + 30 * Length},
	{ X + 15 * Length, Y + 60 * Length} };
	POINT Buddy[2] = { {X + Length, Y + 30 * Length}, {X + Length, Y + Length} };
	//������� �� ������� ����� �������
	POINT Hands[3] = { {X - 15 * Length, Y + 20 * Length}, {X + Length, Y + Length}, 
	{X + 15 * Length, Y + 20 * Length} };

	Polyline(hdc, Legs, 3);
	Polyline(hdc, Buddy, 2);
	Polyline(hdc, Hands, 3);
	Ellipse(hdc, X - 7 * Length, Y - 20 * Length, X + 8 * Length, Y + Length);
	// ��������� ���� ��������� �������
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

void Human::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)

	POINT Legs[3] = { {X - 15 * Length, Y + 60 * Length}, {X + Length, Y + 30 * Length},
	{ X + 15 * Length, Y + 60 * Length} };
	POINT Buddy[2] = { {X + Length, Y + 30 * Length}, {X + Length, Y + Length} };
	//������� �� ������� ����� �������
	POINT Hands[3] = { {X - 15 * Length, Y + 20 * Length}, {X + Length, Y + Length},
	{X + 15 * Length, Y + 20 * Length} };

	Polyline(hdc, Legs, 3);
	Polyline(hdc, Buddy, 2);
	Polyline(hdc, Hands, 3);
	Ellipse(hdc, X - 7 * Length, Y - 20 * Length, X + 8 * Length, Y + Length);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}



/*-----------------------------------------------------------------------*/
/*        ������ ������ Bin            */
/*----------------------------------------*/

Bin::Bin(int InitX, int InitY, int InitLength):Shape(InitX, InitY, InitLength) {}

void Bin::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(200, 200, 200)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)


	POINT bin[4] = { {X - 15 * Length, Y - 20 * Length}, {X - 12 * Length, Y + 15 * Length},
		{ X + 12 * Length, Y + 15 * Length}, {X + 15 * Length, Y - 20 * Length}, };
	
	POINT lin1[2] = { {X - 10 * Length, Y + 10 * Length}, {X - 10 * Length, Y - 10 * Length} };
	POINT lin2[2] = { {X + Length, Y + 10 * Length}, {X + Length, Y - 10 * Length} };
	POINT lin3[2] = { {X + 10 * Length, Y + 10 * Length}, {X + 10 * Length, Y - 10 * Length} };
	
	Polygon(hdc, bin, 4);
	Polyline(hdc, lin1, 2);
	Polyline(hdc, lin2, 2);
	Polyline(hdc, lin3, 2);
	// ��������� ���� ��������� �������
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

void Bin::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //������� ���� (��� �������)
	SelectObject(hdc, Pen); //������� ���� ��������

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); //������� ����� (��� �������)
	HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ ������� ��������� ��� ��������� (����� ��)

	POINT bin[4] = { {X - 15 * Length, Y - 20 * Length}, {X - 12 * Length, Y + 15 * Length},
		{ X + 12 * Length, Y + 15 * Length}, {X + 15 * Length, Y - 20 * Length}, };

	POINT lin1[2] = { {X - 10 * Length, Y + 10 * Length}, {X - 10 * Length, Y - 10 * Length} };
	POINT lin2[2] = { {X + Length, Y + 10 * Length}, {X + Length, Y - 10 * Length} };
	POINT lin3[2] = { {X + 10 * Length, Y + 10 * Length}, {X + 10 * Length, Y - 10 * Length} };

	Polygon(hdc, bin, 4);
	Polyline(hdc, lin1, 2);
	Polyline(hdc, lin2, 2);
	Polyline(hdc, lin3, 2);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen); //-����
	DeleteObject(hBrush); //-����� 
}

