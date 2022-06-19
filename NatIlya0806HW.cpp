#include <iostream>
using namespace std;

// Класс "Поле".
class Field
{
private:
	static const size_t XSize = 10; // Размеры поля по "x".
	static const size_t YSize = 10; // Размеры поля по "y".
	char field[XSize][YSize]; // Двумерный массив элементов.
public:
	Field(){};
	template<typename T>
	void setStaticItem(T& item, int XCord, int YCord) // Установка статичного объекта. По координатам в поле устанаваливается знак объекта.
	{
		field[XCord][YCord] = item.returnSign();
	}	
};

// Класс "Коробка".
class Box
{
private: 
	int XCord; // Координата объекта по "x".
	int YCord; // Координата объекта по "y".
	const char sign = '#'; // Знак объекта.
	/// <...>
public:
	Box(int settingX, int settingY) : XCord{ settingX }, YCord{ settingY }{}; // Конструктор объекта(установка координат по осям "x" и "y".
	char returnSign() { return sign; } // Возвращение знака объекта.
	void spawnBox(Field& field, Box& box) // Установка объекта в поле.
	{
		field.setStaticItem(box, XCord, YCord);
	}
};

int main()
{
	Field level1; // Объект "Уровень 1" класса "Поле".
	int box1XCord = 1; // Координата по "x" объекта "Коробка-1".
	int box1YCord = 1; // Координата по "y" объекта "Коробка-1".
	Box box1(box1XCord, box1YCord); // Конструктор объекта "Коробка-1".
	box1.spawnBox(level1, box1); // Установка объекта "Коробка-1" в поле "Уровень 1".
}
