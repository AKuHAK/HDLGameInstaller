cmake_minimum_required(VERSION 3.10)

# set the project name
project(HDLGManClient.exe)

# add the executable
#include_directories(include)
add_executable(HDLGManClient.exe 
client.c
HDLGManClient.c
install-main.c
io.c
iso9660.c
main.c
OSD.c
system.c

client.h
HDLGManClient.h
install.h
io.h
iso9660.h
main.h
OSD.h
resource.h
system.h
)