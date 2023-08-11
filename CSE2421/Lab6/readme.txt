Name: Naishal Patel

Q1 & Q2:

Add the strings under :

	.section .rodata

#example

	string1:
	    .string "I'm big fan of small word. No like big word or good grammar. Grammar too hard."
	string2:
	    .string "I really hate how nice the weather is getting."
	string3:
	    .string "What"
	string4:
	    .string "Amazing, isn't it? With just the slightest touch the material warps around the skin effortlessly."
	string5:
	    .string "Mmm, ice cream so good!"


#then update the num of string at:

	NUM_STRINGS:
	    .quad 5

# You can change mode of each sorting function here:

	#Change this to 1 for different mode in sorting by word count
	PRINT_MODE_WORD:
	    .quad 0

	#Change this to 1 for different mode in sorting by length
	PRINT_MODE:
	    .quad 0



