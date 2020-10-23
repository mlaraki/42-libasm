global	ft_strdup ;char		*ft_strdup(const char *s1);
extern	ft_strlen
extern	malloc
extern	ft_strcpy

ft_strdup:
	mov		rax, 0
	cmp		rdi, 0					;compare rdi(arg str) et NULL
	je		_return					;si NULL , go vers _error et renvoi NULL

_strlen:
	call	ft_strlen				;assigne le resultat de ft_strlen à rax
	inc		rax						;add +1 for \0
	push	rdi						;push rdi(arg str) sur la stack
	mov		rdi, rax				;sauvegarder la valeur de strlen dans rdi, pour libérer rax dans l'optique d'un malloc
_malloc:
	call	malloc wrt ..plt		;malloc (prend rdi en tant que size)
	cmp		rax, 0					;protéger le malloc
	je		_error					;si malloc renvoi NULL go _error

_strcpy:
	pop		rdi						;récupérer rdi(arg str) de la stack
	mov		rsi, rdi				;assigner rdi à rsi, qui est le 2eme argument de strcpy (src)
	mov		rdi, rax				;à ce moment rax est la variable alloué par malloc. On assigne rax à rdi, qui est dst de strcpy
	call	ft_strcpy				;appel strcpy
	ret

_return:
	ret
_error:
	mov	rax, 0 						; assigne NULL à rax
	pop rdi							; calling convention
	ret 							; renvoi rax



