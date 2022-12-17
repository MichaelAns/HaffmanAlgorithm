#include "Occurence.h"

/// <summary>
/// Пустой конструктор
/// </summary>
Occurence::Occurence() {}


/// <summary>
/// Конструктор, инициализирующий словарь Буква: Количество_буквы_в_сообщении
/// </summary>
/// <param name="source">Сообщение, которое необходимо закодировать</param>
Occurence::Occurence(std::string source)
{
	_source = source;
	calculateNumberOfOccurence(source);
}


/// <summary>
/// Геттер для длины количества символов в сообщении
/// </summary>
/// <returns>Длина символов в исходном сообщении</returns>
std::string Occurence::getSource()
{
	return _source;
}


/// <summary>
/// Геттер для словаря
/// </summary>
/// <returns>Возвращает словарь букв и их появлений</returns>
std::map<char, int> Occurence::getNumberOfOccurence()
{
	return _numberOfOccurence;
}

/// <summary>
/// Создание словаря и его заполнение
/// </summary>
/// <param name="source"> - сообщение, которое необходимо закодировать</param>
void Occurence::calculateNumberOfOccurence(std::string source)
{
	for (int i = 0; i < source.length(); i++) {
		char c = source[i];
		_numberOfOccurence[c]++;
	}	
}


/// <summary>
/// Вывод словаря данных в консоль
/// </summary>
void Occurence::printNumberOfOccurence()
{
	std::map<char, int> ::iterator it = (_numberOfOccurence.begin());
	while (it != _numberOfOccurence.end())
	{
		std::cout << it->first <<": " << it->second << '\n';		
		it++;
	}
	
}
