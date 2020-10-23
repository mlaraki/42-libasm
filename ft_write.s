	global ft_write ;ssize_t		ft_write(int fd, void const *buf, size_t count);
	extern __errno_location

;renvoi le nombre d'octets ecrit ou -1 si il échoue ( dans ce cas errno contient le code d'erreur)
ft_write:
	mov	rax, 1				;assigner 1 à rax
	syscall					;appel systeme pour 1 (write), echec si inferieur à 0
	cmp	rax, 0				;comparer rax à 0
	jl err					;si rax < 0 appel d'error
	jmp	end					;end

err:
	neg rax								; valeur absolue de rax( valeur retour du syscall qui est négatif)
	mov	r9, rax							; assigne la valeur de rax dans un temp
	call __errno_location wrt ..plt		; call errno
	mov QWORD [rax], r9				; assigne la valeur errno dans le pointer
	mov rax, -1
end:
	ret
