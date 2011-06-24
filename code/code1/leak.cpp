void foo();

int main(){
    do{
        foo();
    } while(true);
    return 0;
}

void foo(){
    char *s = new char(1000);
}
