.name    "sebc"
.comment "sebc"

st	r1, :l1
ld	%4, r3
l1:	live	1
ld	%:l1, r2
l3:	ldi	%:l1, r2, r4
sti	r4, %:l1, r2
add	r2, r3, r2
live:	zjmp	%:l1
zjmp	%:l3
