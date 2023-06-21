// algocpp_homework_07_2.cpp 

#include <iostream>
#include <fstream>
#include <Windows.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int x = 0, y = 0;
    int size, sel;
    
    std::ifstream import_data("input.txt");
    if (import_data.is_open())
    {
        import_data >> size;
        int** arr = new int*[size];
        for (int i = 0; i < size; i++)
        arr[i] = new int[size];
        
        for (int i=0;i<size;i++) 
        {
            for (int y = 0; y < size; y++) 
            {
                import_data >> arr[i][y];
            }
        }
        import_data.close();
        std::cout << "В графе " << size <<" вершин. Введите номер вершины, с которой начнётся обход: ";
        std::cin >> sel;
        std::cout << "Порядок обхода вершин: "; 
       
        int mark_head=0,mark_tail=0;
        int* prop = new int[size] {};
        int* vert = new int[size] {};
        std::cout << sel << " ";
        sel--;
        vert[mark_head] = sel;
        prop[sel] = 1;
        while(mark_tail < size-1)
        {    
            for (int t=0;t<size;t++) 
            {
                if (arr[t][sel] == 1 && prop[t]==0)
                {               
                    vert[mark_tail++] = t;
                    std::cout << t+1 << " ";
                    prop[t] = 1;
                }
            }            
            sel = vert[mark_head++];
        }
        std::cout << std::endl;
                  
        for (int i = 0; i < size; i++)
            delete[]arr[i];
        delete[] arr;
        delete[]vert;
        delete[] prop;
    }
    else 
    {
        std::cout << "File not found !" << std::endl;
    }
    return 0;
}