#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Shape {
public:
    Shape() {
    }
	virtual void show_parametri() = 0;
	virtual string formula() = 0;
	virtual int sum_angle() = 0;
	~Shape() {
	}
};
class Square : public Shape {
public: 

	Square() {
	}

	virtual void show_parametri() {
		cout << " Это квадрат " << endl;
	    cout << " Углов " << 4 << endl;
	}
	virtual string formula() {
		return "a * h";
	}
	virtual int sum_angle() {
		return 360;
	}

	~Square() {
		cout << " Квадрат удален " << endl;
	}
};


class Triangle : public Shape {

public:

	Triangle() {
	}

	virtual void show_parametri() {
		cout << " Это треугольник " << endl;
		cout << " Углов " << 3 << endl;
	}
	virtual string formula() {
		return "a * h / 2";
	}
	virtual int sum_angle() {
		return 180;
	}
	~Triangle() {
		cout << " Треугольник удален " << endl;
	}

};

class MyStorage{
private:
	Shape** objects;
	int a;
	int max_a;

	void checkSize() {

		if (a >= max_a)

			increase();

	}

	void increase() {

		Shape** temp = new Shape * [max_a + 10];

		for (int i = 0; i < max_a; i++) {

			temp[i] = objects[i];

		}

		delete objects;

		max_a += 10;

		objects = new Shape * [max_a];

		for (int i = 0; i < max_a; i++) {

			objects[i] = temp[i];

		}

	}
public:
	MyStorage() {
	}

	void SetObject(int index, Shape* object) {
		if(index < max_a)
		objects[index] = object;
	}

	void outpMax_size() {
		cout << "максимальный размер:" << max_a << endl;
	}

	void move(int m) {
		a++;
		checkSize();
		for (int i = a - 1; i >= m; i--) {
			objects[i] = objects[i - 1];
		}
	}

	Shape& GetObject(int index) {
		return *objects[index];
	}

	int getCount() {
		return a;
	}

	void print() {

		for (int i = 0; i < a; i++) {

			GetObject(i).show_parametri();

			GetObject(i).formula();

			GetObject(i).sum_angle();

		}

	}


};
int main() {

	setlocale(LC_ALL, "Rus");
			
}
