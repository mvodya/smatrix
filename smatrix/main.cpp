/*
	smatrix - простой эффект "символьного дождя" для консоли Windows

	Написано неким чуваком @mvodya в 2017 году
	Исходники распространяются на сайте https://github.com/mvodya/smatrix
	Все файлы в проекте распространяются под лицензией MIT License (текст с лицензией в корне проекта)
*/

#include <iostream>
#include "smatrix.h"

int main() {
	// Генерируем семя (зависит от времени) для рандома
	std::srand(unsigned(std::time(0)));
	// Главный цикл
	while (true) {
		linesGenerate(); // Генерируем новые линии, если требуется
		linesUpdate(); // Обновляем существующие линии
		std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_RATE)); // Задержка (тик цикла)
	}
	return 0;
}