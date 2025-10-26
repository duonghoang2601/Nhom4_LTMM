Hướng dẫn chạy code C mã hoá DES 
Yêu cầu:
- gcc 
- Phần mềm VSCode

Cần kiểm tra xem file des.c và des.h co nằm trong bash không, nếu chưa có, chạy 

cd "duong-dan-den-thumuc"

Compile chương trình:
gcc -O3 des.c run_des.c -o run_des.o

Bay gio, ta tao mot file ban ro can ma hoa co dinh dang .txt (vi du "example.txt") cung voi duong dan hua file .c va .h

B1: Tao khoa
./run_des.o -g "duong-dan-de-chua-file-khoa/keyfile.key"

B2: Ma hoa file .txt ban ro
./run_des.o -e "duong-dan-de-chua-file-khoa/keyfile.key" "duong-dan-chua-file-an-ro/example.txt" "duong-dan-de-luu-file-ma-hoa/example.enc"

3: Giai ma
./run_des.o -d "duong-dan-de-chua-file-khoa/keyfile.key" "duong-dan-de-luu-file-ma-hoa/example.enc" "duong-dan-luu-file-duoc-giai/de_example.txt"


Lưu y:
- co the thay thoi ten file tuy y "exmple" chi la vi du
-   mode -e la mode ma hoa , mode -d la mode giai ma
- co the thuc hien 3DES bang cach -e -d -e voi khoa 1 va 3 giong nhau con khoa 2 tao them
