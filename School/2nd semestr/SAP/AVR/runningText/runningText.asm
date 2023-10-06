.cseg ; nasledujici umistit do pameti programu (implicitni)
; definice pro nas typ procesoru
.include "m169def.inc"
; podprogramy pro praci s displejem
.org 0x1000
.include "print.inc"

; Zacatek programu - po resetu
.org 0
jmp start

.org 0x100
delka: .db 6 ; definice read-only konstanty v pameti programu (jeden bajt s hodnotou 6)
retez: .db "VELICE DLOUHY TEXT, KTERY SE NEVEJDE NA DISPLEJ",0 ; retezec zakonceny nulou (nikoli znakem "0")


start:
    ; Inicializace zasobniku
    ldi r16, 0xFF
    out SPL, r16
    ldi r16, 0x04
    out SPH, r16
    ; Inicializace displeje
    call init_disp
    
main_loop:
	ldi r30, low(2*retez)
    ldi r31, high(2*retez)


	ldi r25, ' '
	ldi r24, ' '
	ldi r23, ' '
	ldi r22, ' '
	ldi r21, ' '
	ldi r20, ' '

	ldi r19, 7

	lpm r18, Z+
    
loop:
    ; display current character in current segment position
    ldi r17, 2
    ;call show_char
    
    ; delay between displays
    ldi r26, 230
cek2: ldi r27, 220
cek: dec r27
    brne cek
    dec r26
    brne cek2
    
    ; shift displayed characters one position to the left
    mov r25, r24
	mov r16, r25
	call show_char

	mov r24, r23
	mov r16, r24
	inc r17
	call show_char
	
	mov r23, r22
	mov r16, r23 
	inc r17
	call show_char
	
	mov r22, r21
	mov r16, r22
	inc r17
	call show_char

	mov r21, r20
	mov r16, r21 
	inc r17
	call show_char

	mov r20, r18
	mov r16, r20 
	inc r17
	call show_char
	    
    ; get next character to display
	cpi r19, 7
	brlt endloop
    lpm r18, Z+
    cpi r18, 0
    breq endloop  ; end of string, jump to end
    
    ; add next character to rightmost segment
    jmp loop
    
endloop:
    ; loop finished, stop program
	dec r19
	cpi r19, 0
	breq main_loop

    ldi r18, ' '
	jmp loop
	

end: jmp end
