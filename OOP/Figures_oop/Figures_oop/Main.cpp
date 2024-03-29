#pragma once                  
#include <windows.h>
#include <iostream>
#include "Classes.h" 	//объявление классов
#include "GetConlWin.h"		//указатель на консольное окно

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc;	// Объявим контекст устройства

bool CheckCollisionHuman(Shape& one, Shape& two);
bool CheckCollisionBin(Shape& one, Shape& two); // AABB - AABB collision

int main()
{
//объявление и инициализация переменных
	int Length0 = 5;			//начальное значение радиуса
	int DeltaLen = 1;		//начальное изменение радиуса
	bool gl = false, san = false, fr = false;
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует - можем работать
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			Glass  AGlass(100, 220, Length0);
			Sandwich ASandwich(200, 240, Length0);
			FrenchFries AFrenchFries(300, 220, Length0);
			Human AHuman(700, 500, Length0);
			Bin ABin(1200, 500, Length0);
			int success = 0;
			while (1) {
				if (KEY_DOWN(49)) // цифра 1 
				{
					if(!gl)AGlass.Show();
					if(!san)ASandwich.Show();
					if(!fr)AFrenchFries.Show();
					AHuman.Show();
					ABin.Show();
					Sleep(200);
				}
				if (KEY_DOWN(50)) // цифра 2 
				{
					if(!gl)AGlass.Expand(DeltaLen); // увеличить фигуру на DeltaLen
					if(!san)ASandwich.Expand(DeltaLen); 
					if(!fr)AFrenchFries.Expand(DeltaLen);
					AHuman.Expand(DeltaLen);
					ABin.Expand(DeltaLen);
					Sleep(100);
				}
				if (KEY_DOWN(51)) // цифра 3
				{
					if (!gl)
						while (1)
						{
							if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
								break;
							AGlass.Drag(20); // переенсти фигуру 
							if (CheckCollisionHuman(AGlass, AHuman))
							{
								AGlass.Hide();
								AHuman.Show();
								success++;
								gl = true;
								break;
							}
							if (CheckCollisionBin(AGlass, ABin))
							{
								AGlass.Hide();
								ABin.Show();
								gl = true;
								break;
							}
						}
				}
				if (KEY_DOWN(52)) //цифра 4        
				{
					if (!san)
						while (1)
						{
							if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
								break;
							ASandwich.Drag(20); // переенсти фигуру 
							if (CheckCollisionHuman(ASandwich, AHuman))
							{
								ASandwich.Hide();
								AHuman.Show();
								success++;
								san = true;
								break;
							}
							if (CheckCollisionBin(ASandwich, ABin))
							{
								ASandwich.Hide();
								ABin.Show();
								san = true;
								break;
							}
						}
				}
				if (KEY_DOWN(53)) //цифра 5        
				{
					if (!fr)
						while (1)
						{
							if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
								break;
							AFrenchFries.Drag(20); // переенсти фигуру 
							if (CheckCollisionHuman(AFrenchFries, AHuman))
							{
								AFrenchFries.Hide();
								AHuman.Show();
								success++;
								fr = true;
								break;
							}
							if (CheckCollisionBin(AFrenchFries, ABin))
							{
								AFrenchFries.Hide();
								ABin.Show();
								fr = true;
								break;
							}
						}
				}
				if (KEY_DOWN(54)) //цифра 6        
				{
					if(!gl)AGlass.Reduce(DeltaLen); // уменьшить фигуру на DeltaLen
					if(!san)ASandwich.Reduce(DeltaLen); 
					if(!fr)AFrenchFries.Reduce(DeltaLen);
					AHuman.Reduce(DeltaLen);
					ABin.Reduce(DeltaLen);
					Sleep(100);
				}
				if (KEY_DOWN(48)) //цифра 0
				{
					break;
				}
				if (gl && san && fr)
				{
					if (success == 3)
					{
						std::cout << "SUCCESS. SCORE 3/3";
						break;
					}
					else if (success == 2)
					{
						std::cout << "SUCCESS. SCORE 2/3";
						break;
					}
					else if (success == 1)
					{
						std::cout << "FAIL. SCORE 1/3";
						break;
					}
					else if (success == 0)
					{
						std::cout << "FAIL. SCORE 0/3";
						break;
					}
				}
			}
		 }
	 }
}

bool CheckCollisionHuman(Shape& one, Shape& two) // AABB - AABB collision
{
	// collision x-axis?
	bool collisionX = one.X + 7 * one.Length >= two.X - 7 * two.Length &&
		two.X + 8 * two.Length >= one.X -7 * one.Length;
	// collision y-axis?
	bool collisionY = one.Y + 7 * one.Length >= two.Y -20 * two.Length &&
		two.Y + two.Length >= one.Y -7 * one.Length;
	// collision only if on both axes
	return collisionX && collisionY;
}

bool CheckCollisionBin(Shape& one, Shape& two) // AABB - AABB collision
{
	// collision x-axis?
	bool collisionX = one.X + 7 * one.Length >= two.X - 14 * two.Length &&
		two.X + 14 * two.Length >= one.X - 7 * one.Length;
	// collision y-axis?
	bool collisionY = one.Y + 7 * one.Length >= two.Y - 20 * two.Length &&
		two.Y + 15 * two.Length >= one.Y - 7 * one.Length;
	// collision only if on both axes
	return collisionX && collisionY;
}