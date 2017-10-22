#include "smatrix.h"

// Печатает символ в буффер cout'a
std::ostream & operator<<(std::ostream & os, const Symbol & symbol)
{
	COORD Coord;
	Coord.X = symbol.x_;
	Coord.Y = symbol.y_;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord); // Указываем позицию курсора
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), symbol.color_); // Указываем цвет
	os << symbol.sign_; // Выводим символ в буффер
	return os;
}

// Продвигает линию вниз
void MatrixLine::update()
{
	if (currentRow_ < consoleHeight) { // Если текущая строка ниже высоты консоли, прекращаем рисовать
		Symbol sign(signs[std::rand() % 72], column_, currentRow_);
		std::cout << sign;
	}
	if (currentRow_ >= size_) { // Если текущая строка линии больше длинны линии
		Symbol empty(' ', column_, currentRow_ - size_); // удаляем ее хвост
		std::cout << empty; // таким вот незатейливым методом
	}
	if (currentRow_ - size_ > consoleHeight) // Если высота стирания меньше высоты смерти
		killme = true; // Просим ликвидировать линию

	currentRow_++; // Инкрементируем текущую строку линии (позиция ее головы)
}

// Перебирает все линии и обновляет их
void linesUpdate()
{
	// Перебираем все линии
	for (size_t i = 0; i < lines.size(); i++)
	{
		lines[i].update(); // Обновляем линию
		if (lines[i].killme) // Если линия просит себя убить
			lines.erase(lines.begin()+i); // Удовлетворяем ее
	}
}

// Генерирует новые линии, если требуется
void linesGenerate()
{
	for (size_t i = 0; i < PER_TICK_GENERATIONS; i++)
	{
		MatrixLine line(std::rand() % consoleWeight); // Создаем линию в случайной колонке
		lines.push_back(line); // Кидаем линию в массив всех линий
	}
}
