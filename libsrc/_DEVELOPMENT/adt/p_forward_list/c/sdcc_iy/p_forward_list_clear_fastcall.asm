
; void p_forward_list_clear_fastcall(p_forward_list_t *list)

SECTION code_adt_p_forward_list

PUBLIC _p_forward_list_clear_fastcall

EXTERN asm_p_forward_list_clear

defc _p_forward_list_clear_fastcall = asm_p_forward_list_clear
