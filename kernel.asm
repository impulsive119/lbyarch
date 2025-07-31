section .text
global euclidian_distance_asm

euclidian_distance_asm:
    push rbp
    mov rbp, rsp
    sub rsp, 32            

    mov r10, [rbp + 16]    
    mov r11, [rbp + 24]    

    xor rax, rax           

.loop:
    cmp rax, rcx            
    jge .done

    movss xmm0, [r8 + rax*4]    
    subss xmm0, [rdx + rax*4]   
    movss xmm1, xmm0
    mulss xmm1, xmm1            

    movss xmm2, [r10 + rax*4]  
    subss xmm2, [r9 + rax*4]    
    movss xmm3, xmm2
    mulss xmm3, xmm3            

    addss xmm1, xmm3            
    sqrtss xmm1, xmm1           

    movss [r11 + rax*4], xmm1  

    inc rax
    jmp .loop

.done:
    mov rsp, rbp
    pop rbp
    ret
