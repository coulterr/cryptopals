default: challenge1 challenge2 challenge3 challenge4 challenge5 challenge6

challenge1: challenge1.c lib/hex_functions.o lib/base64_functions.o
	gcc challenge1.c lib/hex_functions.o lib/base64_functions.o -o challenge1

challenge2: challenge2.c lib/hex_functions.o lib/xor_functions.o
	gcc challenge2.c lib/hex_functions.o lib/xor_functions.o -o challenge2

challenge3: challenge3.c lib/dictionary_functions.o lib/cipher_functions.o lib/hex_functions.o lib/xor_functions.o lib/int_queue.o 
	gcc challenge3.c lib/dictionary_functions.o lib/cipher_functions.o lib/hex_functions.o lib/xor_functions.o lib/int_queue.o -o challenge3

challenge4: challenge4.c lib/hex_functions.o lib/xor_functions.o lib/dictionary_functions.o lib/cipher_functions.o lib/int_queue.o
	gcc challenge4.c lib/xor_functions.o lib/hex_functions.o lib/dictionary_functions.o lib/cipher_functions.c lib/int_queue.o -o challenge4

challenge5: challenge5.c lib/hex_functions.o lib/xor_functions.o
	gcc challenge5.c lib/xor_functions.o lib/hex_functions.o -o challenge5

challenge6: challenge6.c lib/cipher_functions.o lib/hex_functions.o lib/xor_functions.o lib/dictionary_functions.o lib/file_functions.o lib/int_queue.o
	gcc challenge6.c lib/cipher_functions.o lib/hex_functions.o lib/xor_functions.o lib/dictionary_functions.o lib/file_functions.o lib/int_queue.o -o challenge6

queue_test: queue_test.c lib/int_queue.o
	gcc queue_test.c lib/int_queue.o -o queue_test

file_functions: lib/file_functions.c
	gcc -o lib/file_functions.o -c lib/file_functions.c

cipher_functions: lib/cipher_functions.c 
	gcc -o lib/cipher_functions.o -c lib/cipher_functions.c
dictionary_functions: lib/dictionary_functions.c
	gcc -o lib/dictionary_functions.o -c lib/dictionary_functions.c
hex_functions: lib/hex_functions.c
	gcc -o lib/hex_functions.o -c lib/hex_functions.c 
base64_functions: lib/base64_functions.c
	gcc -o lib/base64_functions.o -c lib/base64_functions.c 
xor_functions: lib/xor_functions.c
	gcc -o lib/xor_functions.o -c lib/xor_functions.c 
int_queue: lib/int_queue.c
	gcc -o lib/int_queue.o -c lib/int_queue.c
