#include <iostream>
#include <fstream>  

using namespace std; //использование namespace в таком формате для обучения std::

/// <summary>
/// Изучаю с++. Перехожу с блюпринтов в unreal engine на c++
/// Эта программа читает английский алфавит из файла и оставляет буквы похожие на кириллицу
/// Дано: ABCDEFGHIJKLMNOPQRSTUVWXYZ 
/// Результат: ABCEHKMOPTX
/// </summary>
namespace tutorialue
{
    class ReadFile
    {
        string path_to_file{}; //путь к файлу
        ifstream file_for_work{}; // читаем файл
    public:
        ReadFile(string path) :path_to_file(path) {} // конструктор 
        ifstream getFile() // получаем файл
        {
            ifstream myfile(path_to_file);
            return myfile;
        }
        string OutSymbol()
        {
            string sum_symbols{}; // строка для символов
            file_for_work = getFile();
            if (file_for_work.is_open())
            {
                cout << "Файл открыт" << endl;
                char one_file_symbol{}; // переменная для одного символа

                while (file_for_work.get(one_file_symbol))
                {
                    // РЕФАКТОРИНГ. пропускаем перенос строки. пока не знаю как сделать нормально
                    if (!(one_file_symbol == '\n'))
                    {
                        sum_symbols = sum_symbols + one_file_symbol;
                    }
                    else
                    {
                        continue;
                    }
                }
                return sum_symbols;
            }
            else
            {
                string tempstr = "файл не найден, подключите файл " + path_to_file;
                return tempstr;
            }

        }
    };
    class DeleteEngSymbol
    {
    public:
        // код для сравнения нескольких переменных с одной, взят с этого сайта в рамках обучения
        // start other code
        //https://www.geeksforgeeks.org/efficient-ways-to-compare-a-variable-with-multiple-values/
        template <typename T>
        static bool is_in(/*const*/ T& v, initializer_list<T> lst)
        {
            return (find(begin(lst), end(lst), v) != end(lst));
        }
        // end other code
        static string is_in(string engstr)
        {
            string withoutEngStr{};
            for (char instr : engstr)
            {
                // Сравниваем несколько значений. чтобы не использовать char == 'symbol' || и т.д. 
                if (!(is_in(instr, { 'D', 'F', 'G','I','J','L','N','Q','R','S','U','V','W','Y','Z' })))
                {
                    withoutEngStr = withoutEngStr + instr;
                }
            }
            return withoutEngStr;
        }
    };
}

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "Кирилический шрифт английскими буквами кэпсом\n";

    tutorialue::ReadFile readfile("alphabet.txt");
    string withoutEngStr = tutorialue::DeleteEngSymbol::is_in(readfile.OutSymbol());
    cout << "withoutEngStr: " << withoutEngStr << endl;
}

