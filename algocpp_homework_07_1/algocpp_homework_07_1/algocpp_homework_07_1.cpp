// algocpp_homework_07_1.cpp 

#include <iostream>
#include <fstream>
#include <Windows.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int x = 0, y = 0;
    int size;
    
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
        std::cout << "Порядок обхода вершин: "; 
        int dir = 0;
        for (int i = 0; i < size; i++)
        {
            if (dir == 0)
            {
                std::cout << x + 1 << " ";
                dir = 1;
            }
            else
            {
                std::cout << y + 1 << " ";
                dir = 0;
            }
            int mark = 0;
            while (mark == 0)
            {
                if (dir == 0) x++; else y++;
                if (arr[x][y] == 1) mark = 1;
            }
        }
        for (int i = 0; i < size; i++)
            delete[]arr[i];
        delete[] arr;
    }
    else 
    {
        std::cout << "File not found !" << std::endl;
    }
    return 0;
}
