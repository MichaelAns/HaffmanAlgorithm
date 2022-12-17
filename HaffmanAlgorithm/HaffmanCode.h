#include <list>
#include <vector>
#include "Occurence.h"
#include "Node.h"

#pragma once
class HaffmanCode
{
	private:

		/// <summary>
		/// �������� ���������
		/// </summary>
		std::string _source;

		/// <summary>
		/// ������ ��� ����������� ��������
		/// </summary>
		std::list<Node*> _list;

		/// <summary>
		/// ������ ��� �������� ���� �������
		/// </summary>
		std::vector<bool> _code;

		/// <summary>
		/// ������� ��� �������� �������
		/// </summary>
		std::map< char, std::vector<bool> > _table;

		/// <summary>
		/// ������� ���������� ������ �� �����������
		/// </summary>
		struct MyCompare {
			bool operator()(Node* l, Node* r) const {
				return l->occurence < r->occurence;
			}
		};

		/// <summary>
		/// ���������� ������ ��������
		/// </summary>
		/// <param name="occurence"> - ������� �������� � ���������� ���������</param>
		void setNodeList(Occurence* occurence);

		/// <summary>
		/// �������� ������ ��� ����������� ��������
		/// </summary>
		void createHaffmanWood();

		/// <summary>
		/// ���������� ������� ������:��� ��������
		/// </summary>
		/// <param name="root"></param>
		void buildTable(Node* root);

	public:
		/// <summary>
		/// ������ ��� ������ �������
		/// </summary>
		/// <returns>���������� ��������� �� ������ �������</returns>
		std::list<Node*>* getNodeList();

		/// <summary>
		/// ������������, ����������� ������ � ����������� ���
		/// </summary>
		/// <param name="occurence"></param>
		HaffmanCode(Occurence* occurence);

		/// <summary>
		/// ����� ������ � �������
		/// </summary>
		/// <param name="root"></param>
		/// <param name="k"></param>
		void printWood(Node* root, unsigned k);

		/// <summary>
		/// ����� ������� ������:��� �� �����
		/// </summary>
		void printTable();

		/// <summary>
		/// ����� ���� � ������
		/// </summary>
		std::string printCode();
};

#include "HaffmanCode.inl"
