	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	push {r3, r4, r5, r6, lr}
    
	@ R4 = R0 - 0 (update flags)
    subs r4, r0, #0

	@ if(R0 <= 0) goto .L3 (which returns 0)
	ble .L3


	@ Compare R4 wtih 1
	cmp r4, #1

	@ If R4 == 1 goto .L4 (which returns 1)
	ble .L4

    mov r4, r0
    mov r5, #0 @previous0
    mov r6, #1 @previous1
    mov r1, #0
.L1:add r1, r1,#1      @i=i+1
    add r3, r5, r6   @sum=previous0+previous1

    mov r5, r6       @r5=r6
    mov r6, r3       
    
    cmp r1, r4
    bcc .L1
    
    mov r0, r6
    pop {r3, r4, r5, r6, pc}		@ EPILOG

    

.L3:
	mov r0, #0			@ R0 = 0
	pop {r3, r4, r5, r6, pc}		@ EPILOG

.L4:
	mov r0, #1			@ R0 = 1
	pop {r3, r4, r5, r6, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
