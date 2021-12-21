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
private:
	int p1, p2, p3;
public: 
	Square() {
		p1 = 0;
		p2 = 0;
		p3 = 0;
		cout << "Square()" << endl;
	}

	Square(int x, int y, int z) {
		this->p1 = x;
		this->p2 = y;
		this->p3 = z;
		cout << "Square(int x, int y)" << endl;
	}

	Square(const Square& p) {
		p1 = p.p1;
		p2 = p.p2;
		p3 = p.p3;
		cout << "Square(const Square& p)" << endl;
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
private:
	int p1, p2, p3;
public:
	Triangle() {
		p1 = 0;
		p2 = 0;
		p3 = 0;
		cout << "Triangle()" << endl;
	}

	Triangle(int x, int y, int z) {
		this->p1 = x;
		this->p2 = y;
		this->p3 = z;
		cout << "Triangle(int x, int y)" << endl;
	}

	Triangle(const Triangle& p) {
		p1 = p.p1;
		p2 = p.p2;
		p3 = p.p3;
		cout << "Triangle(const Triangle& p)" << endl;
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
		a = 0;
		max_a = 0;
		objects = new Shape * [a];
	}

	MyStorage(int max_a) {
		a = 0;
		this->max_a = max_a;
		objects = new Shape * [a];
	}

	void SetObject(int index, Shape* object) {
		if(index < max_a)
		objects[index] = object;
	}

	Shape& GetObject(int index) {
		return *objects[index];
	}

	int getCount() {
		return a;
	}

	void outpMax_size() {
		cout << "максимальный размер:" << max_a << endl;
	}

	void move(int l) {
		a++;
		checkSize();
		for (int i = a - 1; i >= l; i--) {
			objects[i] = objects[i - 1];
		}
	}

	void print() {
		for (int i = 0; i < a; i++) {
			GetObject(i).show_parametri();
			GetObject(i).formula();
			GetObject(i).sum_angle();
		}
	}

	void print(int l) {
		if (l >= 0) {
			for (int i = 0; i < l; i++) {
				GetObject(i).show_parametri();
				GetObject(i).formula();
				GetObject(i).sum_angle();
			}

			GetObject(l).show_parametri();
			GetObject(l).formula();
			GetObject(l).sum_angle();

			for (int i = l + 1; i < a; i++) {
				GetObject(i).show_parametri();
				GetObject(i).formula();
				GetObject(i).sum_angle();
			}
		}
	}

	void Cin(int l) {

		int x;
		cout << "1 - Square" << endl << "2 - Triangle" << endl;
		cin >> x;
		switch (x) {
			case 1: {
				Triangle* t = new Triangle;
				t->show_parametri();
				t->formula();
				t->sum_angle();
				SetObject(l, t);
				break;
			}

			case 2: {
				Square* s = new Square;
				s->show_parametri();
				s->formula();
				s->sum_angle();
				SetObject(l, s);
				break;
			}
		}
	}

	void Rand(int l) {
		int x = 1 + rand() % 2;
		switch (x) {
			case 1: {
				int p1, p2, p3;
				p1 = 1 + rand() % 2;
				p2 = 1 + rand() % 2;
				p3 = 1 + rand() % 2;
				Triangle* t = new Triangle(p1, p2, p3);
				SetObject(l, t);
				break;
			}

			case 2: {
				int p1, p2, p3;
				p1 = 1 + rand() % 2;
				p2 = 1 + rand() % 2;
				p3 = 1 + rand() % 2;
				Square* s = new Square(p1, p2, p3);
				SetObject(l, s);
				break;
			}
		}
	}

	void remove(int i) {
		if (a > 0) {
			a--;
			for (i; i < a; i++) {
				objects[i] = objects[i + 1];
			}
		}
	}

	void random() {

		MyStorage* storage = new MyStorage;
		int l = -1;
		for (int i = 0; i < 100; i++) {
			system("cls");
			int x;
			cout << "Размер хранилища: " << storage->getCount() << endl;
			if (storage->getCount() == 0) {
				x = 1;
				l = -1;
			}

			else {
				storage->print(l);
				storage->outpMax_size();
				x = 1 + rand() % 5;
			}

			switch (x) {
				case 1: {
					l++;
					storage->move(l);
					storage->Rand(l);
					break;
				}

				case 2: {
					storage->remove(l);
					l--;
					break;
				}

				case 3: {
					storage->Rand(l);
					break;

				}

				case 4: {
					if (l + 1 < storage->getCount())
						l++;
					break;
				}

				case 5: {
					if (l > 0)
						l--;
					break;
				}
			}
		}
		delete storage;
	}

};
int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0));
	MyStorage storage(0);
	bool flag = true;
	int l = -1;
	while (flag == true) {
		system("cls");
		cout << "Размер хранилища: " << storage.getCount() << endl;
		if (storage.getCount() == 0) {
			cout << "1 - добавить элемент" << endl << "6 - подобрать случайно" << endl << "7 - выход" << endl;
			l = -1;
		}

		else {
			storage.print(l);
			storage.outpMax_size();
			cout << "1 - добавить элемент" << endl << "2 - следующий элемент" << endl << "3 - предыдущий" << endl << "4 - удалить" << endl << "5 - изменить" << endl << "6 - подобрать случайно" << endl << "7 - выход" << endl;
		}
		int x;
		cin >> x;
		switch (x) {
			case 1: {
				l++;
				storage.move(l);
				storage.Cin(l);
				break;
			}
			case 2: {
				if (l + 1 < storage.getCount())
					l++;
				break;
			}
			case 3: {
				if (l > 0)
					l--;
				break;
			}
			case 4: {
				storage.remove(l);
				l--;
				break;
			}
			case 5: {
				storage.Cin(l);
				break;
			}
			case 6: {
				storage.random();
				break;
			}
			case 7: {
				flag = false;
				break;
			}
		}
	}
	return 0;
}
