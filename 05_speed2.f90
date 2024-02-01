program main
    use iso_c_binding
    implicit none
    integer, parameter :: n = 10000, m = 10000
    real(c_double), dimension(n, m) :: array1, array2, result
    integer :: i, j
    real(c_double) :: start, finish, elapsed

    ! Initialize 2D arrays
    do i = 1, n
        do j = 1, m
            array1(i, j) = real(i + j, c_double)
            array2(i, j) = real(n - i + m - j, c_double)
        end do
    end do

    call cpu_time(start)
    ! Perform element-wise addition
    result = array1 / 100.D0  + array2**2.D0 + sin(array1 / 100.D0)
    call cpu_time(finish)

    elapsed = finish - start
    print *, "Operation took ", elapsed, " seconds."

    ! Optionally print some results
    print *, "Sample result: ", result(n, m)
end program main
