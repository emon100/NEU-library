cmake_minimum_required(VERSION 3.13)
project(library C)

set(CMAKE_C_STANDARD 99)

add_executable(library main.c login.c admin.c manage.c information.c reader_center.c person_old.c person_edit.c person_delete.c person_insert.c person_backup.c person_recovery.c backup.c) #book_change.c book_delete.c book_load.c Book_login.c)