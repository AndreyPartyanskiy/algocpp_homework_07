// algocpp_homework_07_3.cpp : 

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
        
        int* vis = new int [size]{};
        int a = 0;
        int t = 0;
        int prev = 0;
        int p = 0;

        for (int z=0;z<size;z++) 
        {
            a = 0;
            if (vis[t] == 0) 
            {             
                vis[t] = 1;
                while (a<size && (arr[a][t] == 0 || vis[a] != 0))
                {       
                    if (arr[a][t]==1 && vis[a] == 1 && a != prev) p = 1; 
                    a++;  
                }
            }
            prev = t;
            t = a;
        }
        if (p == 1)
        {
            std::cout << "В графе есть цикл!" << std::endl;
        }
        else 
        {
            std::cout << "В графе нет цикла!" << std::endl;
        }

        delete[]vis;
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