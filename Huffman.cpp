#include <iostream>
#include <string>

class symbol {

public:
    std::string ch;
    size_t freq;
    symbol* left;
    symbol* right;

 

    symbol() {
        ch = "";
        freq = 0;
        left = nullptr;
        right = nullptr;
        

    }
    symbol(std::string character, int fr) {
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

    void insert(std::string ch, int freq) {
        symbol** cur = &root;
        while (*cur) {
            symbol& node = **cur;
            if (freq > node.freq) {
                cur = &node.left;
            } else if (freq < node.freq) {
                cur = &node.right;
            } else {
                cur = &node.right;
            }
        }
        *cur = new symbol(ch, freq);
     

    }
    void print() {
        print_node(root);
      
    }
    void create() {
        create_tree(root);
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
        if (curr) // �������� �� ��������� ���������
        {
            std::cout << curr->ch << " " << curr->freq << std::endl;
            print_node(curr->left);
            print_node(curr->right);
        }
    
    }

    void create_tree(symbol* curr) {
        for (symbol* temp = curr; temp; temp = temp->right) {
            if (temp->left)
                std::cout << temp->left->ch << " " << temp->left->freq << "\t";
            std::cout << temp->ch << " " << temp->freq << "\t";
            

        }
       

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
    HaffmanTree Tree;
    int freq = 0;
    std::string ch;
    for (size_t i = 0; i < b_count; i++){
        ch = text[unic_index[i]];
        for (size_t j = 0; j < text_len; j++)
        {
            
            if (ch[0] == text[j])
                freq++;
        }
        Tree.insert(ch, freq);
        freq = 0;
         
    }
    Tree.create();
    //Tree.print();
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