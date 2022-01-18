@set bool=y
@cd create
g++ -D TEST_EXPORT -c test.cpp

@set /p bool=next: 
@if %bool% == y (
    g++ -shared -o test.dll test.o -Wl,--out-implib,test.lib

    @set /p bool=next: 
    @if %bool% == y (
        @move /Y test.dll ..\
        @move /Y test.lib ..\lib\
        @copy /Y test.hpp ..\include\
        @cd ..
        g++ main.cpp

        @set /p bool=next: 
        @if %bool% == y (
            a.exe
        )
    )
)

