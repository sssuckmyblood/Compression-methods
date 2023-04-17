#include <iostream>
#include <string>

class symbol {

public:
    char ch;
    size_t freq;
    symbol* left;
    symbol* right;

 

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

class HaffmanTree {
public:
    HaffmanTree(){
        root = 0;
    }

    ~HaffmanTree() {
        DestroyNode(root);
    }

    void insert(char ch, int freq) {
        symbol** cur = &root;
        while (*cur) {
            symbol& node = **cur;
            if (freq > node.freq) {
                cur = &node.left;
            }
            else if (freq < node.freq) {
                cur = &node.right;
            }
            else {
                return;
            }
        }
        *cur = new symbol(ch, freq);
    }
    void print() {
        print_node(root);
      
    }

private:
    symbol* root;

    static void DestroyNode(symbol* node) {
        if (node) {
            DestroyNode(node->left);
            DestroyNode(node->right);
            delete node;
        }
    }

    
    void print_node(symbol* curr) {
        if (curr) // Проверка на ненулевой указатель
        {
            print_node(curr->left);
            std::cout << curr->ch << " " << curr->freq << std::endl;
            print_node(curr->right);
        }
    
    };
};

int main()
{
    setlocale(LC_ALL, "RUS");
    std::string text = "абэракадабэра";
    int text_len = text.length();

    size_t b_count = 0;

    char sym[] = { ' ', 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т',
                   'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я'};
    int* unic_index = new int[text_len];
    for (size_t i = 0, j = 0; i < 34 && j < text_len; i++){
        if (text.find(sym[i]) != std::string::npos) {
            b_count++;
            unic_index[j] = text.find(sym[i]);
            j++;
        }

    }
    HaffmanTree Tree;
    int freq = 0;
    char ch;
    for (size_t i = 0; i < b_count; i++){
        ch = text[unic_index[i]];
        for (size_t j = 0; j < text_len; j++)
        {
            
            if (ch == text[j])
                freq++;
        }
        Tree.insert(ch, freq);
        freq = 0;
         
    }
    Tree.print();
   /* symbol temp;
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

    }*/
  
}