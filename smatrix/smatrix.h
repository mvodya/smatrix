#pragma once
#define MIN_LINE_SIZE 1; // Минимальный размер линии
#define MAX_LINE_SIZE 10; // Максимальный размер линии

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib>
#include <ctime>

/* КЛАССЫ */
// Класс символа для отображения в терминале с определенной позицией и цветом
class Symbol {
private:
	int x_; // Колонка
	int y_; // Строка
	int color_; // Цвет
	char sign_; // Отображаемый символ
public:
	Symbol(char sign, int x, int y, int color = 2) { x_ = x; y_ = y; sign_ = sign; color_ = color; }; // Конструктор символа
	friend std::ostream & operator<<(std::ostream & os, const Symbol & symbol); // Для отображения через cout
};

// Класс линии для отрисовки, собственно, линии :)
class MatrixLine {
private:
	int column_; // Колонка, в которой отображается
	int size_; // Размер
	int currentRow_; // Стркоа (голова линии)
public:
	MatrixLine(int column) { column_ = column; size_ = std::rand() % MAX_LINE_SIZE + MIN_LINE_SIZE; currentRow_ = 0; killme = false; };
	void update(); // Метод обновления линии
	bool killme; // Просьба сделать харакири линии
};

/* МЕТОДЫ */
void linesUpdate(); // Обновляет все линии
void linesGenerate(); // Генерирует новые линии

/* ПЕРЕМЕННЫЕ */
static std::vector<MatrixLine> lines; // Массив линий
static int consoleHeight = 28; // Высота отображаемой области
static int consoleWeight = 119; // Высота отображаемой области
const int UPDATE_RATE = 50; // Скорость обновления (в milisec.)
const int PER_TICK_GENERATIONS = 2; // Кол-во новых линий за такт
const char signs[72] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890@#$%^&*?~"; // Используемые символы