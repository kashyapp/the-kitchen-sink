namespace Foo{
    class Foo{
    };
}
namespace Bar{
    using Foo::Foo;
}

int main(){
    Bar::Foo baz;
    return 0;
}

