#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int Add(int a,int b){
    return a+b;
}

int Sub(int a,int b){
    return a-b;
}

int Mul(int a,int b){
    return a*b;
}

int Div(int a,int b){
    if(b==0) return 0;
    return a/b;
}

int main(){
    int (*FuncPtrArray[])(int,int) = { Add,Sub,Mul,Div };
    for(int i = 0;i<SIZE;i++){
        printf("Output of Func[] %i: %i\n",i,FuncPtrArray[i](10,10));
    }

    void *FuncPointer = (void*){ Add };
    printf("Output of Func*: %i\n",(int)(((int (*)(int,int))(FuncPointer))(10,20)));

    void **FuncArray = (void*[]){ Add,Sub,Mul,Div };
    for(int i = 0;i<SIZE;i++){
        printf("Output of Func[] %i: %i\n",i,(int)(((int (*)(int,int))(FuncArray[i]))(2*i,5)));
    }
    
    int (**Funcs)(int,int) = (void*)calloc(SIZE,sizeof(void*));
    Funcs[0] = Add;
    Funcs[1] = Sub;
    Funcs[2] = Mul;
    Funcs[3] = Div;
    
    for(int i = 0;i<SIZE;i++){
        printf("Output of Func: %i\n",(int)((Funcs[i])(100,i)));
    }
    free(Funcs);
    
    return 0;
}