Hướng dẫn chạy code C mã hoá DES 
Yêu cầu:
- gcc 
- Phần mềm VSCode

Cần kiểm tra xem file des.c và des.h co nằm trong bash không, nếu chưa có, chạy 

Compile chương trình:
B1: đi đến thư mục
cd "duong dan den thu muc"
B2: 
Mã hóa:
gcc common/des_core.c common/des_tables.c encrypt/main_encrypt.c -o encrypt_des.exe
 .\encrypt_des.exe

 Giải mã:
gcc common/des_core.c common/des_tables.c decrypt/main_decrypt.c -o decrypt_des.exe
.\decrypt_des.exe

Test Vector chuẩn của NIST cho DES
Key: 0101010101010101
Plaintext: 95F8A5E5DD31D900
Ciphertext: 8000000000000000