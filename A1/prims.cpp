#include <iostream>
using namespace std;

int main()
{
    int vtx, edg;
    int weight = 0;
    cout << "Enter the number of vertex and edges" << endl;
    cin >> vtx >> edg;
    int mat[vtx][vtx];
    for (int i = 0; i < vtx; i++)
    {
        for (int j = 0; j < vtx; j++)
        {
            mat[i][j] = 0;
        }
    }
    cout << "Enter the input in the matrix" << endl;
    for (int i = 0; i < edg; i++)
    {
        int x, y, w;
        cout << "Enter the pair of vertex(x->y)" << endl;
        cin >> x >> y;
        cout << "Enter the weight of edge" << endl;
        cin >> w;
        mat[x][y] = w;
    }

    // prims
    bool arr[vtx];
    for (int i = 0; i < vtx; i++)
    {
        arr[i] = false;
    }
    arr[0] = true;
    for (int k = 0; k < vtx; k++)
    {
        int minW = 99999;
        for (int i = 0; i < vtx; i++)
        {
            if (arr[i] == true)
            {
                for(int j=0; j<vtx; j++)
                {
                    if(arr[j]==false)
                    {
                        if(mat[i][j]<minW)
                        {
                            minW = mat[i][j];
                        }
                    }
                }
            }
        }
        weight = weight + minW;
    }
    cout<<"Minimum cost of the spanning tree: "<<weight<<endl;
}