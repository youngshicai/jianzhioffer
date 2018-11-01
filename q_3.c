
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int find(int arr[][4],int rows,int columns,int value){//剑指offer第3题
//    int i,j;
//    for(i=0;i<rows;i++){
//        for(j=0;j<columns;j++){
//            printf("%4d",arr[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    int i=columns-1,index = columns,j;
    while(i>0){
        /*存在bug寻找区间，而不是边界被忽略了
        if(arr[0][i-1] <= value && value <= arr[0][i])
        {
            if(arr[0][i-1] == value || arr[0][i] == value)
                return 0;
            index = i;
            break;
        }
        */
        if( value >= arr[0][i])
        {
            if(arr[0][i] == value)
                return 0;
            index = i;
            break;
        }
        i--;
    }

    if(index == columns){
        return -1;
    }
    j=0;
    printf("index:%d\n",index);
    for(i=0;i<=index;i++){
        if(arr[rows-1][i]<value){
            printf("jump:%d\n",i);
            continue;
        }
        while(j<rows){
           if( arr[j][i] == value){
               return 0;
           }
           j++;
        }
    }

    return -1;
}

int find1(int *arr,int rows,int columns,int value){//剑指offer第3题
//    int i,j;
//    for(i=0;i<rows;i++){
//        for(j=0;j<columns;j++){
//            printf("%4d",arr[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    
    //特殊输入
    if(arr == NULL || rows <= 0 || columns<=0){
        return -1;
    }
    
    
    int i=columns-1,index = columns,j;
    while(i>0){
        if( value >= *((arr+0*columns)+i)) // value >= arr[0][i]
        {
            if(*((arr+0*columns)+i) == value)
                return 0;
            index = i;
            break;
        }
        i--;
    }

    if(index == columns){
        return -1;
    }
    j=0;
    printf("index:%d\n",index);
    for(i=0;i<=index;i++){
        if(*((arr+(rows-1)*columns)+i) < value){//if(arr[rows-1][i]<value){
            printf("jump:%d\n",i);
            continue;
        }
        while(j<rows){
           if( *((arr+j*columns)+i) == value){//if( arr[j][i] == value){
               return 0;
           }
           j++;
        }
    }

    return -1;
}


int main(){
    int columns=0,rows=0,i,j;
    int arr[][4] = {{1, 2,  8,  9},//二维数组定义处初始化不能[][]，列长度不能空
                    {2, 4,  9, 12},
                    {4, 7, 10, 13},
                    {6, 8, 11, 15}};

    columns = sizeof(arr[0])/sizeof(int);
    rows = sizeof(arr)/sizeof(arr[0]);
    printf("rows:%d columns:%d\n",rows,columns);

    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            printf("%4d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if(!find1((int *)arr, rows, columns, 13)){//    if(!find(arr, rows, columns, 13)){
        printf("yes 找到了\n");
    }else{
        printf("not found    找不到了\n");
    }


    return 0;
}
