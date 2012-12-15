#include <fstream>

unsigned int *p_array = 0;
unsigned char uc_array1[3][3] = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};
unsigned char uc_array2[3][3] = {{3,2,1},
                            {6,5,4},
                            {9,8,7}};


int main(){
    p_array = new unsigned int[3];
    p_array[0] = (unsigned int)uc_array1;
    p_array[1] = (unsigned int)uc_array2;
    for(int i = 0;i < 2;i++){
        for(int x = 0;x < 3;x++){
            for(int y = 0;y < 3;y++){
                printf("%d ",(*p_array+i));
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
