void test1(const int* p){
}

void test2(const int* &p){
    
}

int main(){
    int *p = new int(10);
    test2(p);

    return 0;
}
