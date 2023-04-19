#include <iostream>
#include <string>
#include <map>
class symbol {

public:
    char ch;
    size_t freq;
    symbol* left;
    symbol* right;
    bool branch;

 

    symbol() {
        ch = NULL;
        freq = 0;
        left = nullptr;
        right = nullptr;
        

    }
    symbol(char character, int fr) {
        ch = character;
        freq = fr;
        left = nullptr;
        right = nullptr;
    }

    symbol(const symbol &symbols) {
        this->ch = symbols.ch;
        this->freq = symbols.freq;
    }

    symbol operator=(symbol &symbols) {
        this->ch = symbols.ch;
        this->freq = symbols.freq;
        return *this;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    std::string text = "�����������";
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
    char ch;
    std::multimap<int, char> sorted_weight;
    for (size_t i = 0; i < b_count; i++){
        ch = text[unic_index[i]];
        for (size_t j = 0; j < text_len; j++)
        {
            
            if (ch == text[j])
                freq++;
        }   
        sorted_weight.insert(std::make_pair(freq, ch));
        freq = 0;
         
    }
    for (std::multimap<int, char>:: iterator i = sorted_weight.begin(); i != sorted_weight.end(); i++) {
        std::cout << i->first << "\t" << i->second << std::endl;

    }

   
  
}