	global ft_strcpy

;char		*ft_strcpy(char *dst, const char *src);
ft_strcpy: ;
	mov rax, 0 ; initialisation de rax à 0

check:
	cmp rdi, 0; si rdi(dest) est NULL, erreur
	je error
	cmp rsi, 0; si rsi(src) est NULL, erreur
	je error

while:
	mov dl, byte [rsi + rax]; copier byte par byte de src (rsi) + i (rax) vers temp (dl).
	mov byte [rdi + rax], dl; copier byte par byte du temp (dl) vers dst (rdi)
	cmp dl, 0; condition de fin de la boucle
	je return; si fin de la string go return
	inc rax; increment i (rax)
	jmp while; loop
error:
	mov rax, 0
	ret

return:
	mov rax, rdi; assigner dst (rdi) à rax
	ret ; renvoi rax
