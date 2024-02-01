program main
    implicit none
    integer, dimension(:), allocatable :: intArray
    real(8), dimension(:,:), allocatable :: matrix

    integer :: i, j

    ! 1D array
    intArray = [1, 2, 3, 4, 5]
    WRITE(*,*) "Initial intArray:", intArray
    intArray = intArray * 2
    WRITE(*,*) "Modified intArray:", intArray

    ! 2D array
    ALLOCATE(matrix(2,4))
    do i = 1, size(matrix, 1)
        do j = 1, size(matrix, 2)
            matrix(i,j) = i + j - 1  
        end do
    end do
    ! Print 2D array elements
    do i = 1, size(matrix, 1)
        do j = 1, size(matrix, 2)
            WRITE(*, *) "(", i, ",", j, "): ", matrix(i,j)
        end do
    end do

    ! Perform operations on the 2D array and print results
    matrix = matrix**2.D0 + matrix/2.D0

    WRITE(*,*) "Resulting Matrix elements after operations:"
    do i = 1, size(matrix, 1)
        do j = 1, size(matrix, 2)
            WRITE(*, *) "(", i, ",", j, "): ", matrix(i,j)
        end do
    end do

end program main
