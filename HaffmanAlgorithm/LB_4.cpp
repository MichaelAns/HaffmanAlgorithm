#include "Occurence.h"
#include "HaffmanCode.h"

/// <summary>
/// Ищет ближайшее число вверх, равное степени двойке
/// </summary>
/// <param name="x"></param>
/// <returns>Число, равное степени двойке</returns>
long clp2(long x) {
    // Ищет и возвращает ближайшую к x сверху степень двойки
    // Вообще говоря, предполагает, что число 32-разрядное
    x--;
    for (int p = 1; p < 32; p <<= 1) x |= (x >> p);
    return ++x;
}

/// <summary>
/// Находит из числа, равного степени двойки, эту самую степень
/// </summary>
/// <param name="degreeOfTwo"></param>
/// <returns>Степень двойки</returns>
int degree(long degreeOfTwo)
{
    if (degreeOfTwo == 1)
    {
        return 1;
    }
    int degree = 0;
    while (degreeOfTwo != 1)
    {
        degreeOfTwo /= 2;
        degree++;
    }
    return degree;
}

int main()
{
    std::string source = "Sourceeeeeeeeee";    
    Occurence* occurence = new Occurence(source);

    // Степень двойки
    std::cout << "Degree:\n";
    int countOfUniqueSymbol = occurence->getNumberOfOccurence().size();
    int degre = degree(clp2(countOfUniqueSymbol));
    std::cout << degre << '\n';

    auto haffmanCode = new HaffmanCode(occurence);

    std::cout << '\n' << "\nHaffman wood: \n";
    haffmanCode->printWood(haffmanCode->getNodeList()->front());
    std::string code = haffmanCode->printCode();
    std::cout << code << '\n';
    std::cout << "Source lenght: " << source.length()*degre << "\nCode lenght: " << code.length() << '\n';
    // Нахождение разницы между закодированной строкой и незакодированной
    std::cout << "\nDifference: " << degre * source.length() - code.length() <<  '\n';
    std::cout << "Table: \n";
    haffmanCode->printTable();
}


