
    SECTION code_driver
    SECTION code_driver_character_input

    PUBLIC _sioa_getc

    EXTERN __IO_SIOA_CONTROL_REGISTER

    EXTERN __IO_SIO_WR0_R5, __IO_SIO_WR5_RTS
    EXTERN __IO_SIO_RX_EMPTYISH

    EXTERN sioaRxCount, sioaRxOut

    _sioa_getc:

        ; exit     : l = char received
        ;            carry reset if Rx buffer is empty
        ;
        ; modifies : af, hl
        
        ld a,(sioaRxCount)          ; get the number of bytes in the Rx buffer
        ld l,a                      ; and put it in hl
        or a                        ; see if there are zero bytes available
        ret Z                       ; if the count is zero, then return

;       cp __IO_SIO_RX_EMPTYISH     ; compare the count with the preferred empty size
;       jr NC, getc_clean_up        ; if the buffer NOT emptyish, don't change the RTS
                                    ; this means retrieving characters will be slower
                                    ; when the buffer is emptyish.
                                    ; Better than the reverse case.
        
;       ld a,__IO_SIO_WR0_R5        ; prepare for a read from R5
;       out (__IO_SIOA_CONTROL_REGISTER),a  ; write to SIOA control register
;       in a,(__IO_SIOA_CONTROL_REGISTER)   ; read from the SIOA R5 register
;       ld l,a                      ; put it in L
        
;       ld a,__IO_SIO_WR0_R5        ; prepare for a write to R5
;       out (__IO_SIOA_CONTROL_REGISTER),a  ; write to SIOA control register

;       ld a,__IO_SIO_WR5_RTS       ; set the RTS
;       or l                        ; with previous contents of R5
;       out (__IO_SIOA_CONTROL_REGISTER),a  ; write the SIOA R5 register
        
    getc_clean_up:
        ld hl, sioaRxCount
        di
        dec (hl)                    ; atomically decrement Rx count
        ld hl, (sioaRxOut)          ; get the pointer to place where we pop the Rx byte
        ei
        ld a, (hl)                  ; get the Rx byte

        inc l                       ; move the Rx pointer low byte along, 0xFF rollover
        ld (sioaRxOut), hl          ; write where the next byte should be popped

        ld l, a                     ; put the byte in hl
        scf                         ; indicate char received
        ret

    EXTERN _sio_need
    defc NEED = _sio_need

