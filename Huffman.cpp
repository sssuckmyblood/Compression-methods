#include <iostream>
#include <string>

class symbol {

public:
    char ch;
    size_t freq;

    symbol() {
        ch = NULL;
        freq = 0;
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
    std::string text = "абэракадабэра";
    int text_len = text.length();

    size_t b_count = 0;

    char sym[] = { ' ', 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т',
                   'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я'};
    symbol* symbols;
    int* unic_index = new int[text_len];
    for (size_t i = 0, j = 0; i < 34 && j < text_len; i++){
        if (text.find(sym[i]) != std::string::npos) {
            b_count++;
            unic_index[j] = text.find(sym[i]);
            j++;
        }

    }
    symbols = new symbol[b_count];

    
    for (size_t i = 0; i < b_count; i++){
        symbols[i].ch = text[unic_index[i]];
        for (size_t j = 0; j < text_len; j++)
        {
            
            if (symbols[i].ch == text[j])
                symbols[i].freq++;
        }
        
    }
    symbol temp;
    for (size_t i = 1; i < b_count; i++){
        for (size_t j = 0; j < b_count-i; j++)
        {
            if (symbols[j].freq < symbols[j + 1].freq) {
                temp = symbols[j];
                symbols[j] = symbols[j + 1];
                symbols[j + 1] = temp;
            }
        }
            

    }
    for (size_t i = 0; i < b_count; i++) {
        std::cout << symbols[i].ch << "\t" << symbols[i].freq << "\n";

    }
  
}