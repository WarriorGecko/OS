global port_byte_in

port_byte_in:
    mov dx, ax3f2
    in al, dx
    or al, 00001000
    out dx, al