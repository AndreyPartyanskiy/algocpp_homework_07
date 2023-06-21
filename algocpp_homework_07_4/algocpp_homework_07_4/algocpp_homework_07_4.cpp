// algocpp_homework_07_4.cpp 


#include <iostream>
#include <fstream>
#include <Windows.h>

void dfs(int** arr, int ver, int* vis, int size, int cid )
{
    if (vis[ver] == 0) 
    {
        vis[ver] = cid;
        for (int i = 0; i < size; i++)
        {
            if (arr[i][ver] == 1 && vis[i] == 0)
            {
                dfs(arr, i, vis, size , cid);
            }
        }
    }
}

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
        int cid = 1;

        for (int i = 0; i < size; i++) 
        {
            if (vis[i] == 0)
            {
                dfs(arr,i,vis,size,cid);
                cid++;
            }
        }

        std::cout << "Принадлежность вершин компонентам связности: " << std::endl;
        for (int i = 0; i < size; i++) 
        {
          std::cout << i + 1 << " = " << vis[i]<< std::endl;
        }
        std::cout << "Количество компонентов связности в графе: " << cid-1 << std::endl;

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