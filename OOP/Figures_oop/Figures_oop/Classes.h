class Interface //интерфейс
{
public:   //эти методы доступны извне всем в программе
	//у интерфейса нет переменных
	//у интерфейса не может быть конструктора
	
	//чисто виртуальные функции
	virtual int GetX() = 0;						//получить X координату точки
	virtual int GetY() = 0;						//получить Y координату точки

	virtual void MoveTo(int NewX, int NewY) = 0;//переместить фигуру
	virtual void Drag(int Step) = 0;			//буксировка фигуры

	virtual void Expand(int DeltaLen) = 0;	//увеличить размер
	virtual void Reduce(int DeltaLen) = 0;	//уменьшить размер

	virtual void Show() = 0;              //показать фигуру
	virtual void Hide() = 0;              //спрятать фигуру
};


class Shape : Interface //абстрактный класс
{
public:   //эти методы доступны извне всем в программе
	int X;		//координата X
	int Y;		//координата Y
	int Length;
		 //у абстрактного класса есть конструктор
	Shape(int InitX = 10, int InitY = 10, int InitRdius = 10);

	int GetX();						//получить X координату точки
	int GetY();						//получить Y координату точки
	
	virtual void MoveTo(int NewX, int NewY);//переместить фигуру
	virtual void Drag(int Step);			//буксировка фигуры

	virtual void Expand(int DeltaLen);	//увеличить размер
	virtual void Reduce(int DeltaLen);	//уменьшить размер

		//полностью виртуальные функции
	virtual void Show();              //показать фигуру
	virtual void Hide();              //спрятать фигуру
};


class Glass : public Shape
{
public:
	Glass (int InitX=10, int InitY=10, int InitRdius=10); 
	virtual	void Show();		//показать фигуру стакан
	virtual	void Hide();		//скрыть фигуру стакан
};

class Sandwich : public Shape
{
public:
	Sandwich (int InitX = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//показать фигуру
	virtual	void Hide();		//скрыть фигуру
};

class FrenchFries : public Shape
{
public:
	FrenchFries (int InitX = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//показать фигуру
	virtual	void Hide();		//скрыть фигуру
};

class Human : public Shape
{
public:
	Human(int InitX = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//показать фигуру
	virtual	void Hide();		//скрыть фигуру
};

class Bin : public Shape 
{
public:
	Bin(int Initx = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//показать фигуру
	virtual	void Hide();		//скрыть фигуру
};

