namespace Test{
class Foo{		
	public:
		Foo(){
		}
};

class Bar{
	public:
		Bar(){
		}
};
}


template<class Foo>
class Baz{
	Test::Foo foo;
	public:
		Baz(){
		}
};

using namespace Test;
int main(){
	Baz<Bar> baz;
	return 0;
}
