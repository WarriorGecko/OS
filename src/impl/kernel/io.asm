global iostart


section.text

iostart:
    mov dword [0xb8000], 0x4f524f45
    call read_keyboard


read_keyboard:
    push bx
    push cx
    push dx
    push si
    push di

    mov ah,0x00
    int 0x16

    pop di
    pop si
    pop dx
    pop cx
    pop bx
    ret