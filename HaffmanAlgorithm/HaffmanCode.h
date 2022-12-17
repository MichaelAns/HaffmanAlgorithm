#include <list>
#include <vector>
#include "Occurence.h"
#include "Node.h"

#pragma once
class HaffmanCode
{
	private:

		/// <summary>
		/// Исходное сообщение
		/// </summary>
		std::string _source;

		/// <summary>
		/// Дерево для кодирования Хаффмана
		/// </summary>
		std::list<Node*> _list;

		/// <summary>
		/// Вектор для создания кода символа
		/// </summary>
		std::vector<bool> _code;

		/// <summary>
		/// Словарь для создания таблицы
		/// </summary>
		std::map< char, std::vector<bool> > _table;

		/// <summary>
		/// Условие сортировки списка по возрастанию
		/// </summary>
		struct MyCompare {
			bool operator()(Node* l, Node* r) const {
				return l->occurence < r->occurence;
			}
		};

		/// <summary>
		/// Заполнение списка листьями
		/// </summary>
		/// <param name="occurence"> - словарь символов и количества вхождений</param>
		void setNodeList(Occurence* occurence);

		/// <summary>
		/// Создание дерева для кодирования Хаффмана
		/// </summary>
		void createHaffmanWood();

		/// <summary>
		/// Построение таблицы символ:код Хаффмана
		/// </summary>
		/// <param name="root"></param>
		void buildTable(Node* root);

	public:
		/// <summary>
		/// Геттер для списка листьев
		/// </summary>
		/// <returns>Возвращает указатель на список листьев</returns>
		std::list<Node*>* getNodeList();

		/// <summary>
		/// Конструктуор, заполняющий список и сортирующий его
		/// </summary>
		/// <param name="occurence"></param>
		HaffmanCode(Occurence* occurence);

		/// <summary>
		/// Вывод дерева в консоль
		/// </summary>
		/// <param name="root"></param>
		/// <param name="k"></param>
		void printWood(Node* root, unsigned k);

		/// <summary>
		/// Вывод таблицы символ:код на экран
		/// </summary>
		void printTable();

		/// <summary>
		/// Вывод кода в строку
		/// </summary>
		std::string printCode();
};

#include "HaffmanCode.inl"
