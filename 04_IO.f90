program combined_io
    implicit none
    real(8) :: array1(5) = [1, 2, 3, 4, 5]
    real(8) :: array2(5) = [6, 7, 8, 9, 10]
    real(8) :: val1, val2
    integer :: i, io_stat
    character(len=256) :: line, iomsg

    ! Writing to the file
    open(unit=10, file='data_fortran.txt', status='replace', action='write', iostat=io_stat, iomsg=iomsg)
    if (io_stat /= 0) then
        print *, "Error opening file: ", trim(iomsg)
        stop
    end if
    write(10, *) "# Array1  Array2"
    do i = 1, 5
        write(10, '(F20.16, 2X, F20.16)') array1(i), array2(i)
    end do
    close(10)

    ! Reading from the file
    open(unit=10, file='data_fortran.txt', status='old', action='read', iostat=io_stat, iomsg=iomsg)
    if (io_stat /= 0) then
        print *, "Error opening file: ", trim(iomsg)
        stop
    end if
    do
        read(10, '(A)', iostat=io_stat) line
        if (io_stat /= 0) exit ! Exit the loop on end-of-file or error

        if (line(1:1) == '#') cycle ! Skip comments
        
        read(line, *, iostat=io_stat) val1, val2
        if (io_stat == 0) then
            write(*, *) val1, val2
        end if
    end do
    close(10)
end program combined_io
