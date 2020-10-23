	global ft_strlen

;size_t		ft_strlen(const char *str);
ft_strlen:
			xor		rax, rax			; i = 0
			jmp		compare
compare:
			cmp		BYTE [rdi + rax], 0	; str[i] == 0
			jne		increment
increment:
			inc		rax					; i++
done:
			ret							; return i
