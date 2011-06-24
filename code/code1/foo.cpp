class Foo{
	public:
	const int id;
	int const id2;
	const int &t;
	const int *p0;
	const int *const p1;
	Foo(int i)
		:t(i)
	{ }

};


int main(){
	int o;
	int * const i = &o;
	const int * j;
	int const * k;

	Foo f(1);
        if(true){
            int a = 1;
        }
        else while(true) {
            int a = 1;
        }
	return 0;
}
