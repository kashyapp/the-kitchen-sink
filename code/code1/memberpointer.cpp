struct test{
	test(){
		i=new int;
	}
	~test(){
		cout<<"I am dying"<<endl;
		delete i;
	}
	int *i;
};

int main(){
	test foo;
	test *bar = &foo;
	test *baz = new test;
	test *baaz = new(test);
	
	delete *baz;
	delete baz;

	return 0;
}
