#Naishal Patel
.section .rodata

# Data Types
t1: .string "char"
t2: .string "short"
t3: .string "int"
t4: .string "long"
t5: .string "float"
t6: .string "double"


#Add more strings here
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

#Change the number of string here, and it should be equal to the num of string above.
NUM_STRINGS:
    .quad 5

#Change this to 1 for different mode in sorting by word count
PRINT_MODE_WORD:
    .quad 0

#Change this to 1 for different mode in sorting by length
PRINT_MODE:
    .quad 0

.data
.align 8

sortwordLabel: .string "Sorted by Word Count: \n\n"
sortlenLabel: .string "Sorted by Length of String: \n\n"
word_format: .string "%s\n"
name_format: .string "%s\n"
size_format: .string "%d bytes\n"
padding_format: .string "Padding: %d bytes added\n"
struct_format: .string "The structure size is : %d bytes \n"

types:
    .quad t1
    .quad t2
    .quad t3
    .quad t4
    .quad t5
    .quad t6

size:
    .quad 1
    .quad 2
    .quad 4
    .quad 8
    .quad 4
    .quad 8

strings:
    .quad string1
    .quad string2
    .quad string3
    .quad string4
    .quad string5



.global swap_strings,
       .type swap_strings, @function
# Function to swap two string pointers
swap_strings:
    pushq   %rbp # save the base pointer
    movq    %rsp, %rbp # create the new stack frame
    movq (%rdi), %rax    # Load the value of the first string pointer into RAX
    movq (%rsi), %rdx    # Load the value of the second string pointer into RDX
    movq %rdx, (%rdi)    # Store the second string pointer at the first address
    movq %rax, (%rsi)    # Store the first string pointer at the second address
    leave
    ret
.size swap_strings, .-swap_strings


.global count_words,
.type count_words, @function

count_words:  # Start of the function
    xor %rax, %rax
    xor %rcx, %rcx

next_char:  # Label for the start of the main loop
    movb (%rdi, %rcx), %dl  # Load the RCX'th character from the string into DL
    cmp $0, %dl  # Compare the character with null terminator
    je end_of_string  # If it's the null terminator, jump to end_of_string
    cmp $32, %dl  # Compare the character with space
    je next_word  # If it's a space, jump to next_word
    inc %rcx  # If it's not a space, increment RCX to move to the next character
    jmp next_char  # Jump back to the start of the loop

next_word:  # Label for the start of the word counting logic
    inc %rcx  # Increment RCX to move to the next character
    movb (%rdi, %rcx), %dl  # Load the RCX'th character from the string into DL
    cmp $0, %dl  # Compare the character with null terminator
    je end_of_string  # If it's the null terminator, jump to end_of_string
    cmp $32, %dl  # Compare the character with space
    je next_word  # If it's a space, keep looping until we find a non-space character
    inc %rax  # we've found a new word
    jmp next_char

end_of_string:  # Label for the end of the string
    incq %rax  # Increment the word count one last time
    ret

.size count_words, .-count_words



.global sortWord,
.type sortWord, @function

sortWord:
    # Set up stack frame for the function call
    pushq %rbp
    pushq %rbx
    pushq %r12
    pushq %r13  # Counter
    pushq %r14  # Counter
    movq %rsp, %rbp
    movq $0, %rbx
    movq $0, %rax

sortStrings:
    movq $0, %r12                #  j = 0
    movq $0, %rbx                #  i = 0
    movq (NUM_STRINGS), %r13    # temporary num of strings, i
    

outer_loop:
    cmpq  %r13, %rbx
    je end_sort
    incq %rbx                   # i += 1
    movq (NUM_STRINGS), %r14    # temporary num of strings, j
    decq %r14                   # num of string -= 1; 4
    movq $0, %r12               # j = 0
inner_loop:
    cmpq  %r14, %r12            # when done with iner loop, j = num - 1 - i
    je outer_loop               #to go to outerloop

    movq %r12, %rdx              # preserving j in temp location

    movq $0, %rax                # reset RAX
    movq strings(,%rdx,8), %rdi
    call count_words

    movq %rax, %r8             #temp str lenth of str(j)

    movq %r12, %rdx              # preserving j in temp location
    incq %rdx                    # j+1

    movq $0, %rax                # reset RAX
    movq strings(,%rdx,8), %rdi
    call count_words

    movq %rax, %r9             #temp str lenth of str(j+1)
    movq %r12, %rdx              # preserving j in temp location
    cmpq %r9, %r8
    jg swap

    incq %r12
    jmp inner_loop


swap:
    leaq strings(,%rdx,8), %rdi  # Load the address of the j'th string into rdi
    incq %rdx  # Increment rdx
    leaq strings(,%rdx,8), %rsi  # Load the address of the (j+1)'th string into rsi
    call swap_strings  # Call swap_strings to swap the j'th string with the (j+1)'th string
    incq %r12  # Increment j
    jmp inner_loop  # Jump back to the start of the inner loop

end_sort:
    movq $0, %rbx  # Reset rbx to 0
    cmpq $0, (PRINT_MODE_WORD)  # Compare PRINT_MODE with 0
    je printAll  # If PRINT_MODE is 0, jump to printAll

print:
    movq $0, %rax  # Reset RAX to 0
    movq strings(,%rbx,8), %rsi  # Load the rbx'th string into rsi
    movq $name_format, %rdi  # Load the name format into rdi
    call printf  # Call printf to print the rbx'th string
    jmp endS  # Jump to endS

printAll:
    cmpq  (NUM_STRINGS), %rbx  # Compare rbx with the number of strings
    je endS  # If rbx is equal to the number of strings, jump to endS
    movq $0, %rax  # Reset RAX to 0
    movq strings(,%rbx,8), %rsi  # Load the rbx'th string into rsi
    movq $name_format, %rdi  # Load the name format into rdi
    call printf  # Call printf to print the rbx'th string
    incq %rbx  # Increment rbx
    jmp printAll  # Jump back to the start of the printAll loop

endS:
    #Stack Clean up
    popq %r14
    popq %r13
    popq %r12
    popq %rbx
    popq %rbp
    movq $0, %rax
    ret

.size sortWord, .-sortWord


.global sortLength,
.type sortLength, @function

sortLength:
    # Set up stack frame for the function call
    pushq %rbp
    pushq %rbx
    pushq %r12
    pushq %r13  # Counter
    pushq %r14  # Counter
    movq %rsp, %rbp
    movq $0, %rbx
    movq $0, %rax

sortStringsL:
    movq $0, %r12                #  j = 0
    movq $0, %rbx                #  i = 0
    movq (NUM_STRINGS), %r13    # temporary num of strings, i
    

outer_loopL:
    cmpq  %r13, %rbx
    je end_sortL
    incq %rbx                   # i += 1
    movq (NUM_STRINGS), %r14    # temporary num of strings, j
    decq %r14                   # num of string -= 1; 4
    movq $0, %r12               # j = 0

inner_loopL:
    cmpq  %r14, %r12            # when done with iner loop, j = num - 1 - i
    je outer_loopL               #to go to outerloop

    movq %r12, %rdx              # preserving j in temp location

    movq $0, %rax                # reset RAX
    movq strings(,%rdx,8), %rdi
    call strlen

    movq %rax, %r8             #temp str lenth of str(j)

    movq %r12, %rdx              # preserving j in temp location
    incq %rdx                    # j+1

    movq $0, %rax                # reset RAX
    movq strings(,%rdx,8), %rdi
    call strlen

    movq %rax, %r9             #temp str lenth of str(j+1)
    movq %r12, %rdx              # preserving j in temp location
    cmpq %r9, %r8
    jg swapL

    incq %r12
    jmp inner_loopL


swapL:
    leaq strings(,%rdx,8), %rdi  # Load the address of the j'th string into rdi
    incq %rdx  # Increment rdx
    leaq strings(,%rdx,8), %rsi  # Load the address of the (j+1)'th string into rsi
    call swap_strings  # Call swap_strings to swap the j'th string with the (j+1)'th string
    incq %r12  # Increment j
    jmp inner_loopL  # Jump back to the start of the inner loop

end_sortL:
    movq $0, %rbx  # Reset rbx to 0
    cmpq $0, (PRINT_MODE)  # Compare PRINT_MODE with 0
    je printAllL  # If PRINT_MODE is 0, jump to printAllL

printL:
    movq $0, %rax  # Reset RAX to 0
    movq strings(,%rbx,8), %rsi  # Load the rbx'th string into rsi
    movq $name_format, %rdi  # Load the name format into rdi
    call printf  # Call printf to print the rbx'th string
    jmp endSL  # Jump to endSL

printAllL:
    cmpq  (NUM_STRINGS), %rbx  # Compare rbx with the number of strings
    je endSL  # If rbx is equal to the number of strings, jump to endSL
    movq $0, %rax  # Reset RAX to 0
    movq strings(,%rbx,8), %rsi  # Load the rbx'th string into rsi
    movq $name_format, %rdi  # Load the name format into rdi
    call printf  # Call printf to print the rbx'th string
    incq %rbx  # Increment rbx
    jmp printAllL  # Jump back to the start of the printAllL loop

endSL:
    #Stack Clean up
    popq %r14
    popq %r13
    popq %r12
    popq %rbx
    popq %rbp
    movq $0, %rax
    ret

.size sortLength, .-sortLength


.section .text
.globl main
.type main, @function

main:
    pushq %rbp
    pushq %rbx
    pushq %r12      # num of the string
    pushq %r13      # counter
    pushq %r14      # counter for inner loop
    pushq %r15      # struct length
    movq $0, %r13
    movq $-1, %r14
    movq $0, %r15
    movq %rsp, %rbp
    movq %rdi, %r12 # Store argc in r12
    movq %rsi, %rbx # Store argv in rbx
    cmpq $1,%r12
    je callfunction

print_loop:
    incq %r13
    cmpq %r12, %r13
    je printStructSize # If r12 (argc) is less than 0, jump to print struct size


    movq (%rbx,%r13,8), %rsi # Move the r13'th string pointer in argv to rdi
    movq $name_format, %rdi  # Move the output format to rsi

    # Call printf
    movq $0, %rax # Clear rax for printf
    call printf
    movq (%rbx,%r13,8), %rsi # Move the r13'th string pointer in argv to rsi

loop_datatypes:
    incq %r14  # Increment the inner loop counter
    cmpq $6, %r14  # If all data types have been checked...
    jge print_loop  # ...jump back to the outer loop
    movq types(,%r14,8), %rdi  # Load the address of the current data type name into rdi
    xor %rax, %rax  # Clear rax (strcmp's first argument is the number of vector registers used)
    call strcmp  # Call strcmp to compare the data type names
    test %eax, %eax  # If the data type names do not match...
    jnz loop_datatypes  # ...repeat the inner loop

    # Print the data type size
    movq size(,%r14,8), %rsi  # Load the size of the current data type into rsi
    leaq size_format, %rdi  # Load the address of the size format string into rdi
    xor %rax, %rax  # Clear rax (printf's first argument is the number of vector registers used)
    call printf  # Call printf to print the size of the data type

printPadding:
    movq $4, %rcx  # Load 4 into rcx
    subq size(,%r14,8), %rcx  # Subtract the size of the current data type from 4
    cmpq $0, %rcx  # If the result is negative...
    jl zero

    # Print the padding size
    movq $padding_format, %rdi  # Load the address of the padding format string into rdi
    movq %rcx, %rsi  # Load the padding size into rsi
    movq $0, %rax  # Clear rax (printf's first argument is the number of vector registers used)
    call printf
    addq $4, %r15  # Add 4 to the total structure size
    movq $-1, %r14  # Reset the inner loop counter
    jmp print_loop

zero:
    # No padding is needed for the current data type
    movq $0, %rcx  # Load 0 into rcx
    movq $padding_format, %rdi  # Load the address of the padding format string into rdi
    movq %rcx, %rsi  # Load the padding size into rsi
    movq $0, %rax  # Clear rax (printf's first argument is the number of vector registers used)
    call printf
    addq $8, %r15  # Add 8 to the total structure size
    movq $-1, %r14  # Reset the inner loop counter
    jmp print_loop

nextCmp:
    incq %r13      # Increment the counter
    jmp print_loop # Repeat the loop

callfunction:
    #print title of the Sorting
    xor %rax, %rax
    movq $sortwordLabel, %rdi
    call printf

    xor %rax, %rax
    call sortWord

    #print title of the Sorting
    xor %rax, %rax
    movq $sortlenLabel, %rdi
    call printf

    xor %rax, %rax
    call sortLength
    jmp end

printStructSize:
    #Print the total structure size
    xor %rax, %rax
    movq %r15, %rsi
    movq $struct_format, %rdi
    call printf

end:

    #Stack Clean up
    xor %rax, %rax
    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %rbx
    popq %rbp
    ret # Return from main

.size main, .-main




