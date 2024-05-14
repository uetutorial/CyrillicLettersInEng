#include <iostream>
#include <fstream>  

using namespace std; //������������� namespace � ����� ������� ��� �������� std::

/// <summary>
/// ������ �++. �������� � ���������� � unreal engine �� c++
/// ��� ��������� ������ ���������� ������� �� ����� � ��������� ����� ������� �� ���������
/// ����: ABCDEFGHIJKLMNOPQRSTUVWXYZ 
/// ���������: ABCEHKMOPTX
/// </summary>
namespace tutorialue
{
    class ReadFile
    {
        string path_to_file{}; //���� � �����
        ifstream file_for_work{}; // ������ ����
    public:
        ReadFile(string path) :path_to_file(path) {} // ����������� 
        ifstream getFile() // �������� ����
        {
            ifstream myfile(path_to_file);
            return myfile;
        }
        string OutSymbol()
        {
            string sum_symbols{}; // ������ ��� ��������
            file_for_work = getFile();
            if (file_for_work.is_open())
            {
                cout << "���� ������" << endl;
                char one_file_symbol{}; // ���������� ��� ������ �������

                while (file_for_work.get(one_file_symbol))
                {
                    // �����������. ���������� ������� ������. ���� �� ���� ��� ������� ���������
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
                string tempstr = "���� �� ������, ���������� ���� " + path_to_file;
                return tempstr;
            }

        }
    };
    class DeleteEngSymbol
    {
    public:
        // ��� ��� ��������� ���������� ���������� � �����, ���� � ����� ����� � ������ ��������
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
                // ���������� ��������� ��������. ����� �� ������������ char == 'symbol' || � �.�. 
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
    std::cout << "������������ ����� ����������� ������� ������\n";

    tutorialue::ReadFile readfile("alphabet.txt");
    string withoutEngStr = tutorialue::DeleteEngSymbol::is_in(readfile.OutSymbol());
    cout << "withoutEngStr: " << withoutEngStr << endl;
}

