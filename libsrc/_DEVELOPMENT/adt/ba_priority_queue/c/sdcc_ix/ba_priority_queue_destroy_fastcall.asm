
; void ba_priority_queue_destroy_fastcall(ba_priority_queue_t *q)

SECTION code_adt_ba_priority_queue

PUBLIC _ba_priority_queue_destroy_fastcall

EXTERN asm_ba_priority_queue_destroy

defc _ba_priority_queue_destroy_fastcall = asm_ba_priority_queue_destroy
