
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; memory model ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION CODE

org __crt_org_code

IF (__crt_org_vector_table = -0x80) || (__crt_org_vector_table = -0x100)

section interrupt_vectors
section code_crt_start

ENDIF

section code_crt_init
section code_crt_main
section code_crt_exit
section code_crt_return
section code_crt_common

IF (__crt_org_vector_table) && (__crt_org_vector_table != -0x80) && (__crt_org_vector_table != -0x100)

section interrupt_vectors

ENDIF

section code_driver
section code_font
section code_clib
  include "../../clib_code.inc"
section code_lib
section code_compiler
section code_user

section rodata_driver
section rodata_font
section rodata_clib
  include "../../clib_rodata.inc"
  ;;section rodata_error_strings
  ;;section rodata_error_string_end
  ;;defb 0
section rodata_lib
section rodata_compiler
section rodata_user

SECTION CODE_END

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION DATA

IF __crt_org_data

   org __crt_org_data

ELSE

   IF __crt_model
      
      "DATA section address must be specified for rom models"
   
   ENDIF

ENDIF

section data_align_256
section data_align_128
section data_align_64
section data_align_32
section data_align_16
section data_align_8
section data_align_4
section data_align_2

section smc_jump_vectors
section smc_driver
section smc_font
section smc_clib
  include "../../clib_smc.inc"
section smc_lib
section smc_compiler
section smc_user

section data_driver
section data_font
section data_clib
  include "../../clib_data.inc"
  ;;section data_fcntl_stdio_heap_head
  ;;section data_fcntl_stdio_heap_body
  ;;section data_fcntl_stdio_heap_tail
  ;;section data_fcntl_fdtable_body
section data_lib
section data_compiler
section data_user

SECTION DATA_END

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION BSS

IF __crt_org_bss

   org __crt_org_bss

ELSE

   IF __crt_model

      org -1

   ENDIF

ENDIF

section bss_align_256
section bss_align_128
section bss_align_64
section bss_align_32
section bss_align_16
section bss_align_8
section bss_align_4
section bss_align_2

section bss_driver
section bss_font
section bss_clib
  include "../../clib_bss.inc"
section bss_lib
section bss_compiler
section bss_user

section BSS_UNINITIALIZED
SECTION BSS_END

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

IF (__crt_org_vector_table = 0)

section interrupt_vectors
org 0

ENDIF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;