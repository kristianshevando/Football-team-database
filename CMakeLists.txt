cmake_minimum_required(VERSION 3.6)
project(coursework)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        Headers/Admin.cpp
        Headers/Admin.h
        Headers/User.cpp
        Headers/User.h
        Headers/Database.cpp
        Headers/Database.h
        Headers/Protect.cpp
        Headers/Protect.h
        Headers/Player.cpp
        Headers/Player.h
        Headers/Authorization.cpp
        Headers/Authorization.h
        Headers/Account.cpp
        Headers/Account.h
        bprinter-master/include/bprinter/table_printer.h
        bprinter-master/include/bprinter/impl/table_printer.tpp.h
        bprinter-master/src/table_printer.cpp
        Headers/Birthday.cpp Headers/Birthday.h Superadmin.cpp Superadmin.h Superaccount.cpp Superaccount.h SuperAuthorization.cpp SuperAuthorization.h)
add_executable(coursework ${SOURCE_FILES}
        Headers/Admin.cpp
        Headers/Admin.h
        Headers/User.cpp
        Headers/User.h
        Headers/Database.cpp
        Headers/Database.h
        Headers/Protect.cpp
        Headers/Protect.h
        Headers/Player.cpp
        Headers/Player.h
        Headers/Authorization.cpp
        Headers/Authorization.h
        Headers/Account.cpp
        Headers/Account.h Headers/Birthday.cpp Headers/Birthday.h Superadmin.cpp Superadmin.h Superaccount.cpp Superaccount.h SuperAuthorization.cpp SuperAuthorization.h)