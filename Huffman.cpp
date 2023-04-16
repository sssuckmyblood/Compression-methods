#include <iostream>
#include <string>

class symbol
{
public:
    char ch = NULL;
    size_t freq = 0;


};

int main()
{
    setlocale(LC_ALL, "RUS");
    std::string text = "абракадабра";

    std::string bukvs = "";
    size_t b_count = 0;

    char sym[] = { ' ', 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т',
                   'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };

    for (size_t i = 0; i < 34; i++)
    {
        if (text.find(sym[i]) != std::string::npos)
            b_count++;
    }

    std::cout << b_count << "\n";

    symbol* objects = new symbol[b_count];

    for (size_t i = 0; i < text.length(); i++)
    {
        bool flag = 1;
        for (size_t j = 0; j < b_count; j++)
        {

            if (objects[i].ch == objects[j].ch)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 0)
            break;

        objects[i].ch = text[i];
        for (size_t j = 0; j < text.length(); j++)
        {
            if (text[j] == objects[i].ch)
                objects[i].freq++;
        }
        std::cout << objects[i].freq << "\n";
    }
}