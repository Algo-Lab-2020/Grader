#include <iostream>
using namespace std;

int main(){
    int n;
    int c[1000];
    /* index of h = colum **/
    int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char t[1000];
    int height = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> t[i] >> c[i];
    }

    for (int j = 0; j < n; j++){
        int index = c[j]-1;
        if (t[j] == 'i'){
            h[index] += 4;
        }
        else if (t[j] == 'o')
        {   
            if (h[index] > h[index+1]){
                h[index] += 2;
                h[index+1] = h[index];
            }
            else
            {
                h[index+1] += 2;
                h[index] = h[index+1];
            }
        }
        else if (t[j] == '-')
        {   
            int max = h[index];
            for (int a = 1; a <= 3; a++){
                if (max < h[index+a]){
                    max = h[index+a];
                } 
            }
            max += 1;
            h[index] = max;
            h[index+1] = max;
            h[index+2] = max;
            h[index+3] = max;
        }
    }

    for (int k = 0; k < 10; k++){
        if(height < h[k]){
            height = h[k];
        }
    }
    cout << height << endl;
}