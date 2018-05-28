	.file	"ecran.c"
	.text
	.type	outb, @function
outb:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %edx
	movl	%esi, %eax
	movb	%dl, -4(%rbp)
	movw	%ax, -8(%rbp)
	movzbl	-4(%rbp), %eax
	movzwl	-8(%rbp), %edx
#APP
# 84 "cpu.h" 1
	outb %al, %dx
# 0 "" 2
#NO_APP
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	outb, .-outb
	.globl	ptr_mem
	.type	ptr_mem, @function
ptr_mem:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%rax,4), %edx
	addl	%eax, %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	addl	$376832, %eax
	addl	%eax, %eax
	movl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	ptr_mem, .-ptr_mem
	.globl	ecrit_car
	.type	ecrit_car, @function
ecrit_car:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, %eax
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movb	%al, -28(%rbp)
	movsbw	-28(%rbp), %ax
	movl	-32(%rbp), %edx
	sall	$8, %edx
	orl	%edx, %eax
	movl	%eax, %r12d
	movl	-36(%rbp), %eax
	sall	$12, %eax
	movl	%eax, %ebx
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	ptr_mem
	movq	%rax, %rdx
	movl	%r12d, %eax
	orl	%ebx, %eax
	movw	%ax, (%rdx)
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	ecrit_car, .-ecrit_car
	.globl	efface_ecran
	.type	efface_ecran, @function
efface_ecran:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L6
.L9:
	movl	$0, -4(%rbp)
	jmp	.L7
.L8:
	movl	-4(%rbp), %esi
	movl	-8(%rbp), %eax
	movl	$0, %r8d
	movl	$15, %ecx
	movl	$32, %edx
	movl	%eax, %edi
	call	ecrit_car
	addl	$1, -4(%rbp)
.L7:
	cmpl	$79, -4(%rbp)
	jbe	.L8
	addl	$1, -8(%rbp)
.L6:
	cmpl	$24, -8(%rbp)
	jbe	.L9
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	efface_ecran, .-efface_ecran
	.globl	place_curseur
	.type	place_curseur, @function
place_curseur:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$24, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$4, %eax
	movl	%eax, %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	andl	$15, %eax
	movb	%al, -4(%rbp)
	movl	$980, %esi
	movl	$15, %edi
	call	outb
	movzbl	-4(%rbp), %eax
	movl	$981, %esi
	movl	%eax, %edi
	call	outb
	movb	$0, -3(%rbp)
	movl	$980, %esi
	movl	$14, %edi
	call	outb
	movzbl	-3(%rbp), %eax
	movl	$981, %esi
	movl	%eax, %edi
	call	outb
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	place_curseur, .-place_curseur
	.ident	"GCC: (GNU) 8.1.0"
	.section	.note.GNU-stack,"",@progbits
