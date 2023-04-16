class Interface //���������
{
public:   //��� ������ �������� ����� ���� � ���������
	//� ���������� ��� ����������
	//� ���������� �� ����� ���� ������������
	
	//����� ����������� �������
	virtual int GetX() = 0;						//�������� X ���������� �����
	virtual int GetY() = 0;						//�������� Y ���������� �����

	virtual void MoveTo(int NewX, int NewY) = 0;//����������� ������
	virtual void Drag(int Step) = 0;			//���������� ������

	virtual void Expand(int DeltaLen) = 0;	//��������� ������
	virtual void Reduce(int DeltaLen) = 0;	//��������� ������

	virtual void Show() = 0;              //�������� ������
	virtual void Hide() = 0;              //�������� ������
};


class Shape : Interface //����������� �����
{
public:   //��� ������ �������� ����� ���� � ���������
	int X;		//���������� X
	int Y;		//���������� Y
	int Length;
		 //� ������������ ������ ���� �����������
	Shape(int InitX = 10, int InitY = 10, int InitRdius = 10);

	int GetX();						//�������� X ���������� �����
	int GetY();						//�������� Y ���������� �����
	
	virtual void MoveTo(int NewX, int NewY);//����������� ������
	virtual void Drag(int Step);			//���������� ������

	virtual void Expand(int DeltaLen);	//��������� ������
	virtual void Reduce(int DeltaLen);	//��������� ������

		//��������� ����������� �������
	virtual void Show();              //�������� ������
	virtual void Hide();              //�������� ������
};


class Glass : public Shape
{
public:
	Glass (int InitX=10, int InitY=10, int InitRdius=10); 
	virtual	void Show();		//�������� ������ ������
	virtual	void Hide();		//������ ������ ������
};

class Sandwich : public Shape
{
public:
	Sandwich (int InitX = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//�������� ������
	virtual	void Hide();		//������ ������
};

class FrenchFries : public Shape
{
public:
	FrenchFries (int InitX = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//�������� ������
	virtual	void Hide();		//������ ������
};

class Human : public Shape
{
public:
	Human(int InitX = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//�������� ������
	virtual	void Hide();		//������ ������
};

class Bin : public Shape 
{
public:
	Bin(int Initx = 10, int initY = 10, int initRdius = 10);
	virtual	void Show();		//�������� ������
	virtual	void Hide();		//������ ������
};

