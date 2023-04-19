
#include <iostream>
#include <string>
#include <map>
#include <vector>
class symbol {

public:
    char ch;
    int freq;
    int parent;
    int zero;
    int one;
    bool branch;

 
    symbol(char character, int f) {
        ch = character;
        freq = f;
        parent = -1;
        zero = -1;
        one = -1;
        branch = true;


    }
    symbol(char character, int f, int p, int z, int o, bool b) {
        ch = character;
        freq = f;
        parent = p;
        zero = z;
        one = o;
        branch = b;


    }
    symbol() {
        ch = NULL;
        parent = -1;
        zero = -1;
        one = -1;
        branch = true;
        

    }
};
std::string BoolToString(bool b) {
    return b ? "1" : "0";
}

int main()
{
    setlocale(LC_ALL, "RUS");
    std::string text = "�������� ��������� ����������� ���������� ����� � ����� � ������� ����� � ��������� ������ ���������� �� �������� ��� �������� ������� ��� ��������� ��� �� ������ �������� ���� ���������� �� � ������� �� ������� ������ � ������������ �������� �������������� �������� ��� ����������  ������ � �������� �� ���������� � ������� ��������� ����� ����  ����� ������ ������� ��� ������ ������ �� � ������� �� ������������ ������� �������� ������ ���������� �� �������� ��� ���� �������� ������ ���� �������� �� ����� ���� ������� ��������� �� ��� ������� ���� ��������� ���� �������� � ������ �� ���  ����� ���� ��� ��� ������� ���� �� ������������ ��� ����������� ����� � �������� ��� ��� ��� ������ ������� ��� �������� �������� ��� ���� ������ ����� ������� ���������� ����������� ��������� ����� ������������� �� ������� ������� ��� �� ����������  �������� �������� �������� ��� � ������ ����� ����� ��� ������� ������� � � �������� � ����� ������  ���������� �� ������ ������ �� ���� ������ � ��� ��� ������� ��������� � �����  �������� ������� ���������� ��������� ����� ����� ������� ������� � �� ���� �� ������� �����  ������������ ������ �� �� ��� ������� ������� ��� ������ ���������� ���������� ������ � ������� ������ �� ���������� ������ ��������� ������ ����� ���� ��������� ����";
    int text_len = text.length();

    size_t b_count = 0;

    char sym[] = { ' ', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                   '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    int* unic_index = new int[text_len];
    for (size_t i = 0, j = 0; i < 34 && j < text_len; i++){
        if (text.find(sym[i]) != std::string::npos) {
            b_count++;
            unic_index[j] = text.find(sym[i]);
            j++;
        }

    }
    
    int freq = 0;
    std::string ch;
    std::multimap<int, int> sorted_weight;
  
    for (size_t i = 0; i < b_count; i++){
        ch += text[unic_index[i]];
        for (size_t j = 0; j < text_len; j++)
        {
            
            if (ch[i] == text[j])
                freq++;
        }   
        sorted_weight.insert(std::make_pair(freq, i));
        freq = 0;
         
    }

    std::vector<symbol> tree;  
    int k = 0;
    for (std::multimap<int, int>::iterator i = sorted_weight.begin(); i != sorted_weight.end(); i++) {
        tree.push_back(symbol(ch[k], i->first));
        k++;
    }
    
   
    while (sorted_weight.size() > 1) {
        int freq0 =  begin(sorted_weight)->first;
        int n0 = begin(sorted_weight)->second;
        sorted_weight.erase(begin(sorted_weight));
        int freq1 = begin(sorted_weight)->first;
        int n1 = begin(sorted_weight)->second;
        sorted_weight.erase(begin(sorted_weight));
        tree.push_back(symbol('\0', freq0 + freq1, -1, n0, n1, true));
        tree[n0].parent = tree.size()-1;
        tree[n0].branch = true;
        tree[n1].parent = tree.size()-1;
        tree[n0].branch = false;
        sorted_weight.insert(std::make_pair(freq0+freq1, tree.size()-1));
        
    }
    std::cout << "������� ���������: " << "\n";
    std::map<char, std::string> CodeTable;
    for (size_t i = 0; i < b_count; i++) {
        auto n = tree[i];
        char temp_ch = tree[i].ch;
        std::cout << n.ch << " ";
        std::string Code;
        while (n.parent != -1) {
            Code += BoolToString(n.branch);
            n = tree[n.parent];
        }
        std::reverse(Code.begin(), Code.end());   
        CodeTable[temp_ch] = Code;
        for (size_t i = 0; i < Code.size(); i++){
            std::cout << Code[i];
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "�������� �����: " << "\n";
    std::cout << text;
    std::cout << "\n";

    std::string text_encode;
    for (int i = 0; i < text_len; i++) {
        for (std::map<char, std::string>::iterator j = CodeTable.begin(); j != CodeTable.end(); j++) {
            if (text[i] == j->first) {
                text_encode += j->second;
            }
        }
    }

       std::cout << "\n";
       std::cout << "�������������� �����: " << "\n";
       std::cout << text_encode;
       std::cout << "\n";

       std::string temp;
       std::string text_decode;
        for (int i = 0; i < text_encode.size(); i++) {
            temp.push_back(text_encode[i]);
            for (std::map<char, std::string>::iterator j = CodeTable.begin(); j != CodeTable.end(); j++) {
                if (temp == j->second) {
                    text_decode.push_back(j->first);
                    temp.clear();
                
                }
        
            }
       
        
        }

    std::cout << "\n";
    std::cout << "��������������� �����: " << "\n";
    std::cout << text_decode;
    std::cout << "\n";
  
}