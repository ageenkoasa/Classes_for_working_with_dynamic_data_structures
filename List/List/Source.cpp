#include <fstream>
#include <iostream>
#include <windows.h>
#include "List.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List workList("list.txt");
	int k = -1;
	try
	{
		ofstream out("output.txt");
		while (k != 0) {
			cout << endl << endl;
			cout << "Выберите пункт:\n"
				<< "1. Создание объекта List с именем List1; вывод содержимого List1 на экран\n"
				<< "2. Вставка числа в список\n"
				<< "3. Вывод на экран List1\n"
				<< "4. Создание объекта List с именем List2; поиск максимального значения в массиве; вставка индексов элементов массива arr, равных максимальному значению, в список List2\n"
				<< "5. Удаление последнего элемента из списка\n"
				<< "6. Вывод значения элемента списка, находящегося на позиции i\n"
				<< "7. Вызов деструктора\n"
				<< "0. Выход\n";
			cout << "\nПункт: "; cin >> k;
			cout << "\n_____________________________\n";
			switch (k) {
			case 1: {
				List List1("list.txt");
				cout << "Содержимое списка List1:\n";
				List1.show();
				workList = List1;
				cout << "_____________________________\n";
				break;
			}
			case 2: {
				cout << "Введите число для вставки в конец списка: ";
				int num;
				cin >> num;
				workList.insert(workList.getLength() + 1, num);
				workList.show();
				cout << "_____________________________\n";
				break;
			}
			case 3: {
				cout << "Список List1:\n";
				workList.show();
				out << "Список List1:\n";
				out << workList;
				cout << "_____________________________\n";
				out << "_____________________________\n";
				break;
			}
			case 4: {
				int size = workList.getLength();
				int* arr = new int[size];
				Node* node = new Node;
				node = workList.getFirst();
				Node* next = NULL;
				for (int i = 0; i < size; i++) {
					arr[i] = node->field;
					next = new Node;
					next = node->next;
					node = next;
					next = NULL;
				}

				List List2(0);

				int max = arr[0];
				for (int i = 0; i < size; i++) {	
					if (arr[i] > max) max = arr[i];
				}
				for (int i = 0; i < size; i++) {
					if (arr[i] == max) List2.insert(List2.getLength(), i);
				}

				cout << "List2:  ";
				List2.show();
				out << "List2:  ";
				out << List2;
				cout << "\n_____________________________\n";
				out << "_____________________________\n";
				break;
			}
			case 5: {
				workList.remove(workList.getLength());
				workList.show();
				cout << "\n_____________________________\n";
				break;
			}
			case 6: {
				int k;
				cout << "Введите индекс i для поиска элемента, имеющего такой индекс: "; cin >> k;
				cout << k <<"-ый элемент списка List1: " << workList.getValue(workList.find(k + 1));
				cout << "\n_____________________________\n";
				break;
			}
			case 7: {
				workList.~List();
				workList.show();
				cout << "\n_____________________________\n";
				break;
			}
			case 0: {
				cout << "Выход\n";
				break;
			}
			default:
				break;
			}
		}
		out.close();
	}
	catch (const int n)
	{
		cerr << "Ошибка! Файл не открылся\n";
	}
	system("pause"); 
	return 0;
}
