/*
Summary: did a quick phone screen (this was a first phone screen) since both of us were in a hurry. Wrapped up in 50 minutes. But, he is good to go for further rounds. 

Areas covered: simple coding, algo, OO, design unix
Not covered at all: Data structures, DB

Caveat: for the coding problem, he sent in correct code but code that just did not respect the constraints that I'd set. Without those constraints it is rather trivial. Despite that, I'm giving an 'inclined'.

Questions:
0) strengths
1) reverse a character array without using a looping construct
2) distinguish an abstract class from an interface
3) html object model
4) find all email addresses in a directory of files


0) His strengths (according to him)
algo, problem solving, java 
Says his exposure to software design itself is lower since the work he does involves a lot of algorithmic problem solving and programming optimization itself as against larger design.

1) String reverse without looping constructs:
(where the string is a char array)
got onto it rightaway, and gave two methods.
a) swap first and last, and recursively go through with it
b) push characters onto an explicict/implicit stack and as we drop out of the recursive call, populate the source array with the elements.

WARNING: I'd asked him to send the code in by email and he sent in the following. During the course of the interview, I'd made it ample clear that we are using an array of characters and not a String object. And that I wanted an in-place algorithm, not one that would go about creating new objects. It seemed to me that he understood that clearly. But the code he sent in was completely unlike what I'd asked.


*/
String  reverse(String str){

	if(str.length()==0){
		return str;
	}

	if(str.length()==1){
		return str;
        
                     }
	return(str.charAt(str.length() -1)+reverse(str.substring(1,str.length()-1))+str.charAt(0) );
    
}

/*
2) Interface vs abstract
gave a pretty good and rounded explanation with examples on where he'd like to use interfaces against abstract classes.

3) Object model for html
said he wasn't very familiar with html itself, but with a small set of the tags i gave him, he gave a very reasoable design

interface Tag
	print()// method
abstract classes for each kind of tag, implements the Tag interface
	print method of tag would print it and prints of contained objects
eg:
*/
class html{
	member body, head;
	print();
};

class body{
	list of tags;
}
/*
I haven't written down too clearly here, but he is quite clear on the composite model of the design and appreciates the fact that we could very well use a family of abstract classes to capture the common behaviour of the actual elements by utilising polymorphic methods that capture the differences in the actual classes.

4) email addresses in a text file , directory of text files.
his gunshot answer was the typical one of searching for the '@' character and search before and after it for character patterns that satisfy some simple constraints for email addresses.
however, he was not immediately sure how he'd traverse directories to search all files in a directory. 

with some prodding he realised that possibly perl with some regular expression foo might make it easier. but also admitted that Java itself had regex support.

Anyway, most candidates who do not have too much of unix commandline experience end up with similar solutions. and i don't think we are red-flagging this.
*/
