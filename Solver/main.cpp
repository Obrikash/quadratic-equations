#include <iostream>
#include <string>
#include <fstream>

// ����� ��� ������� ������ �� ������������� �����.
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getInput(bool isRussian)
{
	T input;
	while (true) {
		std::cin >> input;
		if (!std::cin)
		{
			if (std::cin.eof())
				exit(0);

			std::cin.clear();
			ignoreLine();
			if (isRussian)
				std::cout << "������������ ����, ��������� �����.\n";
			else
				std::cout << "Wrong input, try again.\n";
			continue;
		}

		return input;
	}
}

class InformationHolder // ����� ��� �������� ��������� ������
{
private:
	bool isRussian;
	
public:
	std::string menu_text;
	std::string first;
	std::string second;
	std::string third;

	InformationHolder(bool isRussian) : isRussian{ isRussian } {
		if (isRussian)
		{
			menu_text = " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			menu_text += "|                             ����                                 |\n";
			menu_text += "| 1. ���� ���������� ���������                                     |\n";
			menu_text += "| 2. ��������� ������ ������� ���������� ���������                 |\n";
			menu_text += "| 3. ������� ���������� ���������                                  |\n";
			menu_text += "| 4. ����� �� ���������                                            |\n";
			menu_text += " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			menu_text += "\n\n==> �������� ����� ����(1-4): ";


			first = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			first += "~~~~~~~~~~~~~ 1. ���� ���������� ��������� ~~~~~~~~~~~~~~~\n";
			first += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			first += "���������� ��������� - ��� �������������� ��������� ������ �������, ����� ��� �������� ax^2 + bx + c = 0.\n\n";
			first += "� ����������� �� ��������, ������� ����� ��������� ������������ ����������� ���������, ����� �������� ������ ����� ���������� ���������:\n";
			first += "1. 0 = 0.\n2. c = 0.\n3. ax^2 + bx + c = 0.\n4. ax^2 + bx = 0.\n5. ax^2 + c = 0.\n6. ax^2 = 0.\n7. bx + c = 0.\n8. bx = 0.\n";
			first += "������ ��������� ��������� �������������� ���� ������ ���������� ��������� ��� ���������� �� ������.\n\n";


			second =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			second += "~~~~~~~~~~~~~~ 2. ��������� ������ ������� ���������� ��������� ~~~~~~~~~~~~~~~\n";
			second += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			second += "��� ������� ���������� ��������� ������������ ��������� ������. ����� ������ ������� �� ���� ����������� ���������.\n\n";
			second += "� �������� ������� ������� ���������� ��������� ������ �������� ���������:\n1. ��������� ������� ��������.\n2. ���������� �� ���������\n";
			second += "3. ������������� �������������.\n4. ������� �����.\n\n��� ������� ������������ a ��������� ����������, � ��� ����� ������ ��� ������� ��������� ������ �������";
			second += " ���� ��������� ������������.\n\n��������� ������� �������������� ������, ����� �������� ����� ��������� ������� �������. ��� ����� ����� ���������� ��������, ";
			second += "� ������� ����� ����������� ����� �����, ���������� ��� � ��������� ��� �������� ���������� ��������� � ������ ��������� � ������������� �����.\n\n";
			second += "����� ������� ����� ����� ������������ ��� ��������� ����� 3, 4, 5 � 7, ������������ � ������ ���������.\n\n������ ������������ ������� ������� �����, ������� ";
			second += "������� �� ������� ��� � ������� �������������, ��� ���� ��������� ������������.\n\n";
			

			third = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			third += "~~~~~~~~~~~~~ 3. ������� ���������� ��������� ~~~~~~~~~~~~~\n";
			third += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
		}
		else
		{
			menu_text = " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			menu_text += "|                             Menu                                 |\n";
			menu_text += "| 1. Types of quadratic equations                                  |\n";
			menu_text += "| 2. Methods of solving quadratic equations                        |\n";
			menu_text += "| 3. Solving of quadratic equations                                |\n";
			menu_text += "| 4. Exit the program                                              |\n";
			menu_text += " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			menu_text += "\n\n==> Select one option(1-4): ";


			first = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			first += "~~~~~~~~~~~~~ 1. Types of quadratic equations  ~~~~~~~~~~~~~~~~\n";
			first += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			first += "Quadratic equation - is a algebraic equation with the power of 2th, the general form which ax^2 + bx + c = 0.\n\n";
			first += "Depending on values, which can take coefficients of a quadratic equation , it is possible to distinguish 8 types of a quadratic equation:\n";
			first += "1. 0 = 0.\n2. c = 0.\n3. ax^2 + bx + c = 0.\n4. ax^2 + bx = 0.\n5. ax^2 + c = 0.\n6. ax^2 = 0.\n7. bx + c = 0.\n8. bx = 0.\n";
			first += "This program operates all of these types of a quadratic equation when finding roots of equations.\n\n";


			second = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			second += "~~~~~~~~~~~~~~~~~ 2. Methods of solving quadratic equations  ~~~~~~~~~~~~~~~~~\n";
			second += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			second += "Various methods are used to solve equations. The choice of method depends on the type of quadratic equation.\n\n";
			second += "The main methods for solving quadratic equations usually include the following:\n1. Selecting a complete square.\n2. Factorization\n";
			second += "3. Using a discriminant.\n4. Vieta's theorem.\n\nWhen the coefficient a is zero, the equation simplifies and can be solved as an ordinary equation of the first degree";
			second += " by expressing the unknown.\n\nUsing the resources of a computer, you can find the roots of expressions using the selection method. To do this you need to define the interval, ";
			second += "in which the root search will be performed, set the step and check all values of equation in this interval with the set step.\n\n";
			second += "It makes sense to use the selection method for equations of types 3,4,5 and 7 used in this program.\n\nLet's call the classical solution method the method that";
			second += "based on a decision either by means of a discriminant or by expressing the unknown.\n\n";


			third = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			third += "~~~~~~~~~~~~~ 3. Solving quadratic equations ~~~~~~~~~~~~~\n";
			third += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
		}
	}
	
};

class Solver {				// ����� �������� ���� ���������� ��������� � �������� ���������� �� 3 ����� ����.
private:
	double a, b, c;
	double x1, x2;
	bool isRussian;
	bool toWrite{ false };

public:
	Solver(bool isRussian) : isRussian{ isRussian }
	{
		x1 = NULL;
		x2 = NULL;
		if (isRussian) {
			std::cout << "==> ������� ������������ a, b � c ����� ������ (����� ������ ����� �����): ";
			a = getInput<int>(isRussian);
			b = getInput<int>(isRussian);
			c = getInput<int>(isRussian);
			std::cout << "\n\n";
			std::cout << "��������� " << a << "x^2 + " << b << "x + " << c << " = 0.\n\n";
		}
		else {
			std::cout << "==> Enter a, b � c through space, enter floating numbers using period[.]: ";
			a = getInput<int>(isRussian);
			b = getInput<int>(isRussian);
			c = getInput<int>(isRussian);
			std::cout << "\n\n";
			std::cout << "Equation " << a << "x^2 + " << b << "x + " << c << " = 0.\n\n";
		}
	}

	// ���������� ������ ��� ������ ������������� � ���������� ������� ������� (����� ���� ��� ��������� ������������� ����� ����
	void discriminant()
	{
		// ����� ��� ������������ ����� ����
		if ((a <= 1e-5 && a >= -1e-5) && (b <= 1e-5 && b >= -1e-5) && (c <= 1e-5 && c >= -1e-5))
		{
			if (isRussian) {
				std::cout << "��������� ��������� ���: 0 = 0 " << ".\n\n";
				writeToFile();
				return;
			}
			else {
				std::cout << "The equation has form: 0 = 0 " << ".\n\n";
				writeToFile();
				return;
			}
			writeToFile();
		}

		// a, b = 0; c != 0
		if ((a <= 1e-5 && a >= -1e-5) && (b <= 1e-5 && b >= -1e-5) && (c >= 1e-5 || c <= -1e-5))
		{
			if (isRussian) {
				std::cout << "��������� �� ����� ������(��������� �� ����������).\n\n";
				writeToFile();
				return;
			}
			else {
				std::cout << "Equation doesn't have solutions(it doesn't exist).\n\n";
				writeToFile();
				return;
			}
		}

		// ax^2 = 0
		if (a <= 1e-5)
		{
			x1 = -c / b;
			if (isRussian) {
				std::cout << "��������� ����� ����� ���� ������: " << x1 << ".\n\n";
			}
			else {
				std::cout << "The equation has only one solution: " << x1 << ".\n\n";
			}
			writeToFile();
			return;
		}

		// b = 0, a � c != 0
		if (b <= 1e-5)
		{
			if ((-c / a) <= 0)
			{
				if (isRussian) {
					std::cout << "��������� �� ����� ������(������ �� �������������� �����).\n\n";
					writeToFile();
					return;
				}
				else {
					std::cout << "Equation doesn't have solutions(sqrt to negative number).\n\n";
					writeToFile();
					return;
				}
			}
			x1 = std::sqrt((-c / a));
			x2 = -std::sqrt((-c / a));
			if (isRussian)
			{
				std::cout << "��������� ����� ��������� �����: " << x1 << "; " << x2 << ".\n\n";
				writeToFile();
				return;
			}
			else
			{
				std::cout << "The equation has the following solutions: " << x1 << "; " << x2 << ".\n\n";
				writeToFile();
				return;
			}
		}
		double discr = b * b - 4 * a * c;
		if (!(discr >= 0)) {
			if (isRussian) {
				std::cout << "��������� �� ����� ������(������������ ������ ����).\n\n";
				writeToFile();
				return;
			}
			else {
				std::cout << "Equation doesn't have solutions(discriminant is less than 0).\n\n";
				writeToFile();
				return;
			}
		}
		else {
			// ������������ = 0. ���� ������������ ������� ���, ������������ �� � ������� ��� ������������ ����� ����(��������� � ��������� ������)
			if (discr <= 1e-8) {							
				x1 = -b / (2 * a);
				if (isRussian) {
					std::cout << "��������� ����� ����� ���� ������: " << x1 << ".\n\n";
				}
				else {
					std::cout << "The equation has only one solution: " << x1 << ".\n\n";
				}
			}

			// ������������ ������������� � ������� ��� ������
			else {
				x1 = (( -b + std::sqrt(discr)) / (2 * a));
				x2 = (( -b - std::sqrt(discr)) / (2 * a));

				if (isRussian)
				{
					std::cout << "��������� ����� ��������� �����: " << x1 << "; " << x2 << ".\n\n";
				}
				else
				{
					std::cout << "The equation has the following solutions: " << x1 << "; " << x2 << ".\n\n";
				}

			}
		}
		writeToFile();
	}
	
	// ������� ��� ������ ��������� � ������ � ��������� � ����.
	void writeToFile()
	{
		if (isRussian) {
			std::cout << "�� ������ �������� ����� � ���� answer.txt?[Y/n]: ";
			char input{};
			while (true) {
				input = getInput<char>(isRussian);
				if (input == 'Y') {
					std::ofstream outputFile("answer.txt", std::ios::app);

					// ��������� ��������� �� �������� � �������� ����.
					if (!outputFile.is_open()) {
						std::cerr << "������ �� ����� �������� �����!" << '\n';
						return;
					}

					outputFile << "��������� " << a << "x^2 + " << b << "x + " << c << " = 0\n";
					if (x2 != NULL)
						outputFile << "x1 = " << x1 << ", x2 = " << x2 << '\n';
					else if (x1 == NULL && x2 == NULL) {
						outputFile << "��� �������.\n";
					}
					else
						outputFile << "��������� ����� ���� ������������ �������: x1 = " << x1 << '\n';
					std::cout << "����� ������� ������� � ����!\n";
					outputFile.close();
					break;
				}
				else if (input == 'n')
					return;
				else
				{
					std::cout << "������������ ����, ��������� �����.\n";
					continue;
				}
			}
		}
		else {
			std::cout << "Do you want to write the answer to the answer.txt?[Y/n]: ";
			char input{};
			while (true) {
				input = getInput<char>(isRussian);
				if (input == 'Y') {
					std::ofstream outputFile("answer.txt", std::ios::app);

					if (!outputFile.is_open()) {
						std::cerr << "Error opening file!" << '\n';
						return;
					}

					outputFile << "The equation " << a << "x^2 + " << b << "x + " << c << " = 0\n";
					if (x2 != NULL)
						outputFile << "x1 = " << x1 << ", x2 = " << x2 << '\n';
					else if (x1 == NULL && x2 == NULL) {
						outputFile << "No roots.\n";
					}
					else
						outputFile << "The equation has only one solution: x1 = " << x1 << '\n';

					std::cout << "The answer is successfully written!\n";
					outputFile.close();
					break;
				}
				
				// ������������ ��������� �� ������ ������ � ����.
				else if (input == 'n')
					return;
				else
				{
					std::cout << "Wrong input. try again.\n";
					continue;
				}
			}
		}
	}
};

// ������ ���������, ����� � ��� ����� �������������� � �������������
class Menu {			
private:
	bool isRussian;

public:
	Menu(bool isRussian) : isRussian {isRussian} {}
	void showMenu();
};

void Menu::showMenu()
{
	InformationHolder text{isRussian};
	while (true) {
		std::cout << "\n\n\n";
		std::cout << text.menu_text;
		short num{};

		// �������� ����������� ����, ���� �� ������� ���������� ����.
		while (true) {			
			std::cin >> num;
			if (!std::cin)
			{
				if (std::cin.eof())
					exit(0);

				std::cin.clear();
				ignoreLine();

				std::cout << "������������ ����, ��������� �����.\n";
				continue;
			}
			
			// ������ ��������, ����� ����� ������������ ������, ��������� �, � ������ ������� ������� � ����.
			if (num == 1) {
				std::cout << "\033[2J\033[1;1H" << text.first;
				if (isRussian)
					std::cout << "������� ����� ������� ����� ����� ������� � ����\n\n\n";
				else
					std::cout << "Press any key to go back to the menu\n\n\n";
				system("pause");
				break;
			}
			else if (num == 2)
			{
				std::cout << "\033[2J\033[1;1H" << text.second;
				if (isRussian)
					std::cout << "������� ����� ������� ����� ����� ������� � ����\n\n\n";
				else
					std::cout << "Press any key to go back to the menu\n\n\n";
				system("pause");
				break;
			}
			else if (num == 3)
			{
					std::cout << "\033[2J\033[1;1H" << text.third;
					short x{};
					Solver solver{ isRussian };
					solver.discriminant();
					if (isRussian)
						std::cout << "������� ����� ������� ����� ����� ������� � ����\n\n\n";
					else
						std::cout << "Press any key to go back to the menu\n\n\n";
					system("pause");
					break;
			}
			else if (num == 4)
				return;
			else {
				std::cout << "������������ ����, ��������� �����.\n";
				continue;
			}

		}
		std::cout << "\033[2J\033[1;1H";
	}
}

int main()
{
	setlocale(LC_ALL, "ru-RU");
	int num{};
	bool isRussian{ false };
	std::cout << "�������� ����(choose the language), 1 - RUSSIAN, 2 - ENGLISH: ";

	while (true) {			// �������� ����������� ����, ���� �� ������� ���������� ����.
		num = getInput<int>(isRussian);
		if (num == 1) {
			isRussian = true;
			break;
		}
		else if (num == 2)
			break;
		else {
			std::cout << "������������ ����, ��������� �����.\n";
			continue;
		}
	}
	std::cout << "\033[2J\033[1;1H";
	// �������� ������, ����� ������� �� ��������� ��� ����� ���������
	Menu menu{ isRussian };
	menu.showMenu();

	return 0;
}