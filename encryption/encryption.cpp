#include <iostream>
#include <string>
#include <vector>
using namespace std;
int maxdig(const string& key) {
	char maxDigit = key[0];
	for (char digit : key) {// цикл for each проходимся по ключу ищем самый высокий элемент методом перебора
		if (isdigit(digit) && digit > maxDigit) {
			maxDigit = digit;
		}
	}
	return maxDigit - '0';
}
void encryption(string& key, string& code) {
	int rows = maxdig(key);// вызываем функцию которая находит внутри "key" самый высокий элемент и по его размеру мы создаем размер матрицы 
	int cols = code.size() / rows;
	int it = 0;
	int value = 0;// создаем переменную которая будет считать количество итераций
	vector<vector<string>>matrix(rows, vector<string>(cols));
	while (!code.empty()) {//проверяем не пустая ли переменная код которая содержит наш шифр 
		for (size_t i = 0; i < key.size(); ++i) {
			int dig = key[i] - '0';// присваиваем dig ключ за индексом i
			if (value % 2 == 0) {// проверка на чётность 
				matrix[dig - 1][it] = code.substr(0, 2).c_str();//присваиваем матрице 2 буквы 
				code.erase(0, 2);
				}
			else {
				matrix[dig - 1][it] = code.substr(0, 1).c_str();//присваиваем матрице 1 букву
				code.erase(0, 1);
			}
			++value;//увеличиваем переменную отвечающую за подсчет 
			}
		++it;//переходим на следующую колонну
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j];//вывод матрицы через вложеный цикл
		}
	}
	cout << endl;// конец
}
int main() {
	while (true) {
		string key;
		string code;
		cout << "enter the key (if you want to exit, write 'end')" << endl;
		cin >> key;// вводим ключ и спрашиваем не хотим ли выйти 
		if (key == "end")
			break;
		cout << "please write the code" << endl;
		cin >> code;//принимаем шифр 
		encryption(key, code);//вызываем функцию шифра
	}
	return 0;
}