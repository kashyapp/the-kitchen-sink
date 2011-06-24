/*
 * wants a role where there is a mix of development and business logic.
 * considers it his strong point. says he is not a complete 'geek'.
 * 
 *
 * Problem 1: Removespaces
 * keep two pointers, 
 */

//
//char *s will create a copy of the pointer, so will not work.
//

void removespaces(char **s){
	int i,j;
	i=0;
	j=0;
	while(*s[i] != '\0'){
		if(*s[i]==' '){
			i++;
		}
		else{
			(*s[j]=*s[i]);
			j++;
			i++;
		}
	}
	*s[j]='\0';
}


//use a hash for a growable array
//how????
//
//are you talking about realloc()
//
//not sure how calling function affects complexity
//comparision
//
//when i point out cost of realloc, he realises that overall cost of pushing
//while allocatiing using realloc one element at a time in n^2.
//
//
