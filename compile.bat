nasm -f win64 kernel.asm -o kernel.obj
gcc -c main.c -o main.obj -m64
gcc main.obj kernel.obj -o distance.exe -m64 -lm
distance.exe
