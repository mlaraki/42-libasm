	global ft_strcmp

ft_strcmp:
		mov rax, 0 ; initialiser rax
		mov rbx, 0 ; initialiser rbx
while:
		mov al, [rdi] ; on assigne s1[i] à al
		mov bl, [rsi] ; on assigne s2[i] à bl
		cmp al, bl; on compare s1[i] a s2[i]
		jne compare; si pas egal on renvoi la différence de rax et rbx
		cmp al, 0; on check si s1[i] est fini
		je return; si oui on renvoi rax
		cmp bl, 0; on check si s2[i] est fini
		je return; si oui on renvoi rbx
		inc rdi; increment rdi
		inc rsi; increment rsi
		jmp while; loop

compare:
		sub	rax, rbx; on soustrait rax et rbx
return:
		ret; renvoi rax
