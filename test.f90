program dynamicStringExample
    implicit none
    integer, DIMENSION(:), allocatable :: i

    i = [1, 2, 3, 4]
    print*, i, SIZEOF(i)
    i = [1, 2, 3, 4, 5]
    print*, i, SIZEOF(i)
end program dynamicStringExample
