;
;	CPC Maths Routines
;
;	August 2003 **_|warp6|_** <kbaccam /at/ free.fr>
;
;	$Id: dsub.asm,v 1.1 2003-08-30 16:42:48 dom Exp $
;

		INCLUDE		"#cpcfp.def"

		XLIB		dsub
		XDEF		dsubc

		LIB		stkequ
		XREF		fa


.dsub						; (fa+1)=(fa+1)-(sp+3)
		ld	hl,3
		add	hl,sp			; hl=sp+3
		ex	de,hl
		ld	hl,fa+1			; de=fa+1
.dsubc		call	CPCFP_FLO_REV_SUB	; (hl)=(de)-(hl)
		pop     hl			;ret to program
		pop     bc			;get rid of fp number
		pop     bc
		pop	bc
		jp      (hl)			;outta here back to program


