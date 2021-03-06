
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; sio driver IM2 vector table ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
   
IF (__Z80 != 0) && (__page_zero_present) && (__crt_org_vector_table > 0x100) && (__CRTCFG = 1)

    SECTION     interrupt_vectors

    EXTERN      __siob_interrupt_tx_empty
    EXTERN      __siob_interrupt_ext_status
    EXTERN      __siob_interrupt_rx_char
    EXTERN      __siob_interrupt_rx_error
    EXTERN      __sioa_interrupt_tx_empty
    EXTERN      __sioa_interrupt_ext_status
    EXTERN      __sioa_interrupt_rx_char
    EXTERN      __sioa_interrupt_rx_error

    defw        __siob_interrupt_tx_empty
    defw        __siob_interrupt_ext_status
    defw        __siob_interrupt_rx_char
    defw        __siob_interrupt_rx_error
    defw        __sioa_interrupt_tx_empty
    defw        __sioa_interrupt_ext_status
    defw        __sioa_interrupt_rx_char
    defw        __sioa_interrupt_rx_error

ENDIF

