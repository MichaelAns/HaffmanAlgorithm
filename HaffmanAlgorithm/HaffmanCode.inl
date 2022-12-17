#include "HaffmanCode.h"


void HaffmanCode::setNodeList(Occurence* occurence)
{
    std::map<char, int> map = occurence->getNumberOfOccurence();
    std::map<char, int> ::iterator it;

    for (it = map.begin();
        it != map.end();
        it++)
    {
        Node* node = new Node;
        node->symbol = it->first;
        node->occurence = it->second;
        _list.push_back(node);
    }
}

std::list<Node*>* HaffmanCode::getNodeList()
{
    return  &_list;
}

HaffmanCode::HaffmanCode(Occurence* occurence)
{
    _source = occurence->getSource();
    setNodeList(occurence);
    createHaffmanWood();
    buildTable(_list.front());

}

void HaffmanCode::createHaffmanWood()
{
    // Пока список не дойдёт до корня дерева (будет равняться сумме всех элементов)
    while (_list.size() != 1) {
        _list.sort(MyCompare());
        #pragma region Объединение первой пары листьев (узлов)

        Node* sonL = _list.front();
        _list.pop_front();
        Node* sonR = _list.front();
        _list.pop_front();

        #pragma endregion

        // Создание отца для левого и правого сына
        Node* parent = new Node(sonL, sonR);
        _list.push_back(parent);
    }
    
    // Создание корня дерева
    Node* root = _list.front();
}

void HaffmanCode::printWood(Node* root, unsigned k = 0)
{
    if (root != NULL){
        HaffmanCode::printWood(root->left, k + 3);

        for (unsigned i = 0; i < k; i++){
            std::cout << " ";
        }

        if (root->symbol) {
            std::cout << root->occurence << " (" << root->symbol << ")\n";
        } 
        else {
            std::cout << root->occurence << '\n';
        }

        HaffmanCode::printWood(root->right, k + 3);
    }
}

void HaffmanCode::buildTable(Node* root)
{
    if (root->left != NULL) {
        _code.push_back(1);
        buildTable(root->left);
    }
    if (root->right != NULL) {
        _code.push_back(0);
        buildTable(root->right);
    }
    
    if (root->symbol) {
        _table[root->symbol] = _code;
    }

    if (_code.size() != 0) {
        _code.pop_back();
    }
}

void HaffmanCode::printTable()
{
    
    for (auto it = _table.begin(); it != _table.end(); it++)
    {
        std::string code;
        for (int i = 0; i < it->second.size(); i++)
        {
            code += std::to_string(it->second[i]);
        }
        std::cout << it->first << ": " << code << '\n';
    }
}

std::string HaffmanCode::printCode()
{
    std::string result = "";
    for (int i = 0; i < _source.length(); i++) {
        char c = _source[i];
        std::vector<bool> x = _table[c];
        for (int n = 0; n < x.size(); n++)
        {
            result += std::to_string(x[n]);
        }
    }
    return result;
}
