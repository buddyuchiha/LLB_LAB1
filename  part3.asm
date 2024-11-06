%include "io64.inc"

section .data
    prompt_size db "Enter size: ", 0
    error_size db "Error: Invalid size.", 10, 0
    sorted_array db "Sorted array: ", 0
    newline db 10, 0

section .bss
    data resd 100
    size resd 1
    input_value resd 1

section .text
    global main

main:
    GET_DEC 4, size
    mov eax, [size]
    cmp eax, 0
    jle invalid_size

    mov ecx, eax
    xor ebx, ebx
input_elements:
    cmp ebx, ecx
    jge start_sorting
    
    GET_DEC 4, input_value
    mov eax, [input_value]
    mov [data + ebx * 4], eax
    
    inc ebx
    jmp input_elements

start_sorting:
    mov ebx, data
    mov edx, ecx
    dec edx
    xor ecx, ecx

sort_outer_start:
    cmp ecx, edx
    jge sort_end

    mov edi, ecx
sort_inner_right:
    cmp edi, edx
    jge sort_end_inner_right
    mov eax, [ebx + edi * 4]
    mov esi, [ebx + edi * 4 + 4]
    cmp eax, esi
    jle no_swap_right
    mov [ebx + edi * 4], esi
    mov [ebx + edi * 4 + 4], eax

no_swap_right:
    inc edi
    jmp sort_inner_right

sort_end_inner_right:
    dec edx

    mov edi, edx
sort_inner_left:
    cmp edi, ecx
    jle sort_end_inner_left
    mov eax, [ebx + edi * 4]
    mov esi, [ebx + edi * 4 - 4]
    cmp eax, esi
    jge no_swap_left
    mov [ebx + edi * 4], esi
    mov [ebx + edi * 4 - 4], eax

no_swap_left:
    dec edi
    jmp sort_inner_left

sort_end_inner_left:
    inc ecx
    jmp sort_outer_start

sort_end:

output_elements:
    PRINT_STRING sorted_array
    xor ebx, ebx
print_loop:
    cmp ebx, [size]
    jge end_program

    mov eax, [data + ebx * 4]
    PRINT_DEC 4, eax
    PRINT_STRING " "

    inc ebx
    jmp print_loop

end_program:
    PRINT_STRING newline
    ret

invalid_size:
    PRINT_STRING error_size
    jmp end_program
