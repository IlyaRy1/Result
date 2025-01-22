/* 
Итоговая работа - swarm robotics
*/

#include <iostream>
using namespace std;

class RoboBee { //создание класса
private: //модификатор доступа
	string name; //имя робота
	int Bee_xNewHome = 0; //координаты улья по X
	int Bee_yNewHome = 0; //координаты улья по Y
	bool Bee_KnowWhereNewHome = false; //известны ли роботу координаты: false - нет, true - да

public: // модификатор доступа
	RoboBee(string name_val) { //конструктор
		name = name_val;
	}

	void GoZone() { //метод - перемещение робота до обследуемой зоны
		cout << "Робопчела " << name << " полетела на поиски нового дома" << endl << endl;
	}

	void GoHome() { // метод - перемещение робота домой
		cout << "Робопчела " << name << " полетела домой" << endl << endl;
	}

	int getInfoAboutNewHome() { // геттер - метод для получения данных из private
		return Bee_KnowWhereNewHome;

	}

	int getNewHomeX() { // геттер - метод для получения данных из private
		return Bee_xNewHome;

	}

	int getNewHomeY() { // геттер - метод для получения данных из private
		return Bee_yNewHome;

	}

	void Searching() { //метод - исследование зоны
		cout << "Робопчела " << name << " исследует зону" << endl << endl;
		cout << "Нашла ли робопчела " << name << " новый дом?" << endl;
		cout << "0 - если нет, 1 - если да" << endl;
		cin >> Bee_KnowWhereNewHome;
		cout << endl;
		if (Bee_KnowWhereNewHome == true) { //при наличии хорошего улья - просьба вввести его координаты
			cout << "Введите текущие координаты" << endl;
			cout << "X: ";
			cin >> Bee_xNewHome;
			cout << "Y: ";
			cin >> Bee_yNewHome;
			cout << endl;
		}
		else { //при отсутствии хорошего улья - ничего не происходит
			;
		}


	}

	void setNewHomeX(int xNewHome) { //сеттер - установить значение координаты X
		Bee_xNewHome = xNewHome;

	}

	void setNewHomeY(int yNewHome) { // сеттер - установить значение координаты Y
		Bee_yNewHome = yNewHome;

	}

	void setNewHomeKnowledge(bool KnowWhereNewHome) { //сеттер - установить значение свойству, отвечающему за известность о положении улья
		Bee_KnowWhereNewHome = KnowWhereNewHome;

	}

	void GoNewHome() { // метод - перемещение робота в новое место жилья
		cout << "Робопчела " << name << " полетела в новый дом с координатами (" << Bee_xNewHome << ", " << Bee_yNewHome << "). Задача выполнена" << endl << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Ru"); // работа с русским языком
	RoboBee bee1("Баба Капа"); //создание экземпляра класса
	RoboBee bee2("Пчёлка Майя"); //создание экземпляра класса


	int Hive_xNewHome = 0; //координаты нового улья по Х
	int Hive_yNewHome = 0; //координаты нового улья по Y
	bool Hive_KnowWhereNewHome = false; //известно ли в улье о местонахождении нового улья

	while (true) { //цикл, выполняется бесконечно до break;

		bee1.GoZone(); //вызов метода GoZone
		bee1.Searching(); //вызов метода Searching
		bee1.GoHome(); //вызов метода GoHome

		if (Hive_KnowWhereNewHome == false) { //получение информации из улья
			cout << "Никто в улье не нашел новый дом" << endl << endl;
			Hive_KnowWhereNewHome = bee1.getInfoAboutNewHome(); //получение данных от bee1

			if (Hive_KnowWhereNewHome == false) {
				cout << "Робопчела передала информацию, что тоже не нашла новый дом" << endl << endl;
				continue; //начать новый цикл
			}

			else {
				cout << "Робопчела передала информацию, что она нашла новый дом" << endl << endl;
				Hive_KnowWhereNewHome = true; //улей получил информацию о местонахождении нового улья
				Hive_xNewHome = bee1.getNewHomeX(); //улей получил информацию о координате X нового улья
				Hive_yNewHome = bee1.getNewHomeY(); // улей получил информацию о координате Y нового улья
				break; //конец цикла
			}
		}

		else {
			bee1.setNewHomeX(Hive_xNewHome); // экземпляр bee1 получает координату Х местонахождения нового улья
			bee1.setNewHomeY(Hive_yNewHome); // экземпляр bee1 получает координату Y местонахождения нового улья
			bee1.setNewHomeKnowledge(true); //свойству экземпляра bee1 присваивается значение true (знает о местонахождении нового улья)
			break; // конец цикла
		}
	}

	bee1.GoNewHome(); //вызов метода GoNewHome

	while (true) { //аналогичные операции с другим экземпляром класса RoboBee

		bee2.GoZone();
		bee2.Searching();
		bee2.GoHome();

		if (Hive_KnowWhereNewHome == false) {
			cout << "Никто в улье не нашел новый дом" << endl << endl;
			Hive_KnowWhereNewHome = bee2.getInfoAboutNewHome();

			if (Hive_KnowWhereNewHome == false) {
				cout << "Робопчела передала информацию, что тоже не нашла новый дом" << endl << endl;
				continue;
			}

			else {
				cout << "Робопчела передала информацию, что она нашла новый дом" << endl << endl;
				Hive_KnowWhereNewHome = true;
				Hive_xNewHome = bee2.getNewHomeX();
				Hive_yNewHome = bee2.getNewHomeY();
				break;
			}
		}

		else {
			bee2.setNewHomeX(Hive_xNewHome);
			bee2.setNewHomeY(Hive_yNewHome);
			bee2.setNewHomeKnowledge(true);
			break;
		}
	}

	bee2.GoNewHome();
}