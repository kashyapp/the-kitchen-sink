/*
Thangaraj Sengoden
SDE1
09/26
1st Telecon

* Introduction
Questions:
* 2nd largest
* bfs levels
* private inheritance
* 2n
*
*/

/*
Introduction
Why Amazon?


0) Claims he is not strong in OOD with C++,
1) Private inheritance
good answer incl visiblity and functionality
*/

class EligibleForSchol : private Student{
	
};

void collectfees(student){
	
}
//confused about is-a

// Came to interview without pen and paper
    1
  2   3
4  5    6
    7

void pre(node){
	print(node);
	pre(node->left);
	pre(node->right);
}

//i am not familiar with graphs, trees only i am familiar
//hint: depth of each node, doesn't know what is depth!!!
//is it depth first traversal?? because i hinted that we go in increasing order of depth
//

int atoi_t(char *ch)
{
	//null check
	//integer bounds
	int final = 0;
	int num = 0;
	int mul = 1;
	int strLen = strlen(ch);
	char * p = ch + strlen - 1; //pointint to last char
	while(strlen)
	{
		num = (int)(*p) - '0';
		final = final + num * mul;
		mul = mul * 10;
		strlen--;
		p--;		
	}
	return final;
}
