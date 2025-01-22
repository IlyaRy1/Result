/* 
�������� ������ - swarm robotics
*/

#include <iostream>
using namespace std;

class RoboBee { //�������� ������
private: //����������� �������
	string name; //��� ������
	int Bee_xNewHome = 0; //���������� ���� �� X
	int Bee_yNewHome = 0; //���������� ���� �� Y
	bool Bee_KnowWhereNewHome = false; //�������� �� ������ ����������: false - ���, true - ��

public: // ����������� �������
	RoboBee(string name_val) { //�����������
		name = name_val;
	}

	void GoZone() { //����� - ����������� ������ �� ����������� ����
		cout << "��������� " << name << " �������� �� ������ ������ ����" << endl << endl;
	}

	void GoHome() { // ����� - ����������� ������ �����
		cout << "��������� " << name << " �������� �����" << endl << endl;
	}

	int getInfoAboutNewHome() { // ������ - ����� ��� ��������� ������ �� private
		return Bee_KnowWhereNewHome;

	}

	int getNewHomeX() { // ������ - ����� ��� ��������� ������ �� private
		return Bee_xNewHome;

	}

	int getNewHomeY() { // ������ - ����� ��� ��������� ������ �� private
		return Bee_yNewHome;

	}

	void Searching() { //����� - ������������ ����
		cout << "��������� " << name << " ��������� ����" << endl << endl;
		cout << "����� �� ��������� " << name << " ����� ���?" << endl;
		cout << "0 - ���� ���, 1 - ���� ��" << endl;
		cin >> Bee_KnowWhereNewHome;
		cout << endl;
		if (Bee_KnowWhereNewHome == true) { //��� ������� �������� ���� - ������� ������� ��� ����������
			cout << "������� ������� ����������" << endl;
			cout << "X: ";
			cin >> Bee_xNewHome;
			cout << "Y: ";
			cin >> Bee_yNewHome;
			cout << endl;
		}
		else { //��� ���������� �������� ���� - ������ �� ����������
			;
		}


	}

	void setNewHomeX(int xNewHome) { //������ - ���������� �������� ���������� X
		Bee_xNewHome = xNewHome;

	}

	void setNewHomeY(int yNewHome) { // ������ - ���������� �������� ���������� Y
		Bee_yNewHome = yNewHome;

	}

	void setNewHomeKnowledge(bool KnowWhereNewHome) { //������ - ���������� �������� ��������, ����������� �� ����������� � ��������� ����
		Bee_KnowWhereNewHome = KnowWhereNewHome;

	}

	void GoNewHome() { // ����� - ����������� ������ � ����� ����� �����
		cout << "��������� " << name << " �������� � ����� ��� � ������������ (" << Bee_xNewHome << ", " << Bee_yNewHome << "). ������ ���������" << endl << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Ru"); // ������ � ������� ������
	RoboBee bee1("���� ����"); //�������� ���������� ������
	RoboBee bee2("������ ����"); //�������� ���������� ������


	int Hive_xNewHome = 0; //���������� ������ ���� �� �
	int Hive_yNewHome = 0; //���������� ������ ���� �� Y
	bool Hive_KnowWhereNewHome = false; //�������� �� � ���� � ��������������� ������ ����

	while (true) { //����, ����������� ���������� �� break;

		bee1.GoZone(); //����� ������ GoZone
		bee1.Searching(); //����� ������ Searching
		bee1.GoHome(); //����� ������ GoHome

		if (Hive_KnowWhereNewHome == false) { //��������� ���������� �� ����
			cout << "����� � ���� �� ����� ����� ���" << endl << endl;
			Hive_KnowWhereNewHome = bee1.getInfoAboutNewHome(); //��������� ������ �� bee1

			if (Hive_KnowWhereNewHome == false) {
				cout << "��������� �������� ����������, ��� ���� �� ����� ����� ���" << endl << endl;
				continue; //������ ����� ����
			}

			else {
				cout << "��������� �������� ����������, ��� ��� ����� ����� ���" << endl << endl;
				Hive_KnowWhereNewHome = true; //���� ������� ���������� � ��������������� ������ ����
				Hive_xNewHome = bee1.getNewHomeX(); //���� ������� ���������� � ���������� X ������ ����
				Hive_yNewHome = bee1.getNewHomeY(); // ���� ������� ���������� � ���������� Y ������ ����
				break; //����� �����
			}
		}

		else {
			bee1.setNewHomeX(Hive_xNewHome); // ��������� bee1 �������� ���������� � ��������������� ������ ����
			bee1.setNewHomeY(Hive_yNewHome); // ��������� bee1 �������� ���������� Y ��������������� ������ ����
			bee1.setNewHomeKnowledge(true); //�������� ���������� bee1 ������������� �������� true (����� � ��������������� ������ ����)
			break; // ����� �����
		}
	}

	bee1.GoNewHome(); //����� ������ GoNewHome

	while (true) { //����������� �������� � ������ ����������� ������ RoboBee

		bee2.GoZone();
		bee2.Searching();
		bee2.GoHome();

		if (Hive_KnowWhereNewHome == false) {
			cout << "����� � ���� �� ����� ����� ���" << endl << endl;
			Hive_KnowWhereNewHome = bee2.getInfoAboutNewHome();

			if (Hive_KnowWhereNewHome == false) {
				cout << "��������� �������� ����������, ��� ���� �� ����� ����� ���" << endl << endl;
				continue;
			}

			else {
				cout << "��������� �������� ����������, ��� ��� ����� ����� ���" << endl << endl;
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