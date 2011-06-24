int f();
namespace{
int x;

int g(){
    x = 4;
    return f() + x;
}
}
int main(){
    return g();
}
