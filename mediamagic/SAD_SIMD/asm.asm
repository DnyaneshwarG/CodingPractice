.data

; variable declarations
pb_1 db 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
pw_1 dw 1, 1, 1, 1, 1, 1, 1, 1

.code

sad_asm:
    ; rcx = src1
    ; rdx = src2

    movdqu      xmm0, [rcx] ; load src1
    movdqu      xmm1, [rdx] ; load src2

    psubb       xmm0, xmm1  ; src1[0:15] - src2[0:15]

    ; pabsb logic here
    lea         r8, [pb_1]
    lea         r9, [pw_1]
    movdqa      xmm2, xmm0
    psrld       xmm2, 7
    pand        xmm2, [r8]
    pxor        xmm1, xmm1  ; xmm1 = [0,0,0....]
    pcmpgtb     xmm1, xmm0  ; cmp 0 > xmm0
    pxor        xmm1, xmm0
    paddb       xmm1, xmm2

    ; add 16 8-bit elements to get sad value
    pmaddubsw   xmm1, [r8]
    pmaddwd     xmm1, [r9]
    phaddd      xmm1, xmm1
    pshufd      xmm2, xmm1, 1
    paddd       xmm1, xmm2

    movd        eax, xmm1   ; return value is in eax register
    ret
