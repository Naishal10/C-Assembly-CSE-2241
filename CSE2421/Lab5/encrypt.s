#Naishal Patel

.section .data
    bits: .space 8
    string:  .space 8
    left: .byte 0
    right: .byte 0
    center: .byte 0
    buffer: .byte 0

.section .text
.globl main
main:

	pushq %rbp #stack housekeeping #1
	movq %rsp, %rbp
	
	pushq %rbx
	pushq %rcx
	pushq %r12        # Counter for bit striping, i
	pushq %r13        # Counter for chunk
	pushq %r14        # buffer 
	pushq %r15	      # counter for encrypt
	movq $0, %r13     # set counter to 0
	movq $0, %r14     # set buffer to 0
	movq $0, %r15     # counter for encrypt


	
read:

    # Read a character
    movq $0, %rax          # System call number for read
    movq $0, %rdi          # File descriptor for stdin
    leaq buffer(%rip), %rsi # Buffer to store the character
    movq $1, %rdx          # Number of bytes to read
    syscall                # Call kernel

    # Check if EOF
    cmpq $0, %rax          # EOF is signalled by a read of 0 bytes
    je end                 # If EOF, jump to end
    #call getchar
    movq buffer(%rip), %rcx
	movq %rcx, string(%r13) # add characters to the string
	incq   %r13   

	cmpq $0, %rax           # Check if EOF
	je end                  # If EOF, jump to end

	movq $0, %r14     # set counter to 0
	cmpq $8, %r13     # princheck if chunk is 8
	cmove %r14, %r12  # set counter to 0
    cmove %r14, %r15  # set counter to 0
	je  stripBit

	jmp read

stripBit:
	movq buffer(%rip), %rbx         # Copy rax to rbx  for shifting
	movb %r12b, %cl    
	shrq %cl, %rbx          # Shift rbx  (copy of ch) i bits to the right
	andq $1, %rbx           # Perform bitwise AND operation with 1
	movq %rbx, bits(%r12)   # Store the result into bits[i]

	incq   %r12
	cmpq $8, %r12           # check if chunk is 8
	je  encrypt
	
	jmp stripBit

encrypt:
	movq $0, %r14         # Move $0 to a temporary register
	cmpq $7, %r15         # Compare %r12 with 7
	cmovge %r14, %r13     # If %r12 >= 7, move %r15 (which is 0) to %r13
	jge read              # If the zero flag is set (meaning %r12 was >= 7), jump to read

	# left = string[i] >> ((CHUNK-1)-i);
	movq string(%r15), %rax
	movq $7, %r14
	subq %r15, %r14
	movb %r14b, %cl
	shrq %cl, %rax
	movq %rax, left

	# left = left << (CHUNK-i);
	movq $8, %r14
	subq %r15, %r14
	movb %r14b, %cl
	shlq %cl, %rax
	movq %rax, left

	# right = string[i] << (i+1);
	movq string(%r15), %rax
	movq %r15, %r14
	addq $1, %r14
	movb %r14b, %cl
	shlq %cl, %rax
	movq %rax, right

	# right = right >> (i+1);
	shrq %cl, %rax
	movq %rax, right

	# center = (bits[i] << ((CHUNK-1)-i));
	movq bits(%r15), %rax
	movq $7, %r14
	subq %r15, %r14
	movb %r14b, %cl
	shlq %cl, %rax
	movq %rax, center

	# string[i] = (left | right) | center;
	movq $0, %rax
	orq left, %rax
	orq right, %rax
	orq center, %rax
	movq %rax, string(%r15)


	#Add putchar
	movq string(%r15), %rdi # Move character into rdi
	call putchar
      

	incq %r15
	jmp encrypt

    

end:
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rcx
	popq %rbx

	xorq %rax, %rax
	leave
	ret





