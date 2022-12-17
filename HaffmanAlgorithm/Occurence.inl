#include "Occurence.h"

/// <summary>
/// ������ �����������
/// </summary>
Occurence::Occurence() {}


/// <summary>
/// �����������, ���������������� ������� �����: ����������_�����_�_���������
/// </summary>
/// <param name="source">���������, ������� ���������� ������������</param>
Occurence::Occurence(std::string source)
{
	_source = source;
	calculateNumberOfOccurence(source);
}


/// <summary>
/// ������ ��� ����� ���������� �������� � ���������
/// </summary>
/// <returns>����� �������� � �������� ���������</returns>
std::string Occurence::getSource()
{
	return _source;
}


/// <summary>
/// ������ ��� �������
/// </summary>
/// <returns>���������� ������� ���� � �� ���������</returns>
std::map<char, int> Occurence::getNumberOfOccurence()
{
	return _numberOfOccurence;
}

/// <summary>
/// �������� ������� � ��� ����������
/// </summary>
/// <param name="source"> - ���������, ������� ���������� ������������</param>
void Occurence::calculateNumberOfOccurence(std::string source)
{
	for (int i = 0; i < source.length(); i++) {
		char c = source[i];
		_numberOfOccurence[c]++;
	}	
}


/// <summary>
/// ����� ������� ������ � �������
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
