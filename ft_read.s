	global ft_read							; ssize_t		ft_read(int fd, void *buf, size_t count);
	extern __errno_location

ft_read:
	mov	rax, 0				;assigner 0 à rax
	syscall					;appel systeme pour 0 (read)
	cmp	rax, 0
	jl _err					;si rax < 0 appel d'error
	jmp	end					;end

_err:
	neg rax								; valeur absolue de rax
	mov	r9, rax							; assigne la valeur de rax dans un temp
	call __errno_location wrt ..plt		; call errno
	mov [rax],r9						; assigne la valeur errno dans le pointer
	mov rax, -1
end:
	ret
