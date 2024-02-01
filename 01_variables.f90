program main
    implicit none
    ! Variable declarations first
    integer :: integerVar = 123
    logical :: true = .true., false = .false.
    
    real :: realVar = 1.1234567890123456789
    real(4) :: singlePVar = 1.1234567890123456789
    real(8) :: doublePVar = 1.1234567890123456789D0

    character(len=14) :: str = "Hello, Fortran"
    character(len=:), allocatable :: dynamicStr
    
    ! Integers and bool
    PRINT*, integerVar
    PRINT*, true, false
    WRITE(*, *) integerVar
    WRITE(*, '(I12)') integerVar
    WRITE(*, '(I5)') integerVar
    
    ! Floats
    ! field width of 20 and 16 decimal places
    WRITE(*, '(F20.16)') realVar
    WRITE(*, '(F20.16)') singlePVar
    WRITE(*, '(F20.16)') doublePVar
    
    ! Strings
    WRITE(*, '(A)') str

    ! Assigning a value to the allocatable string
    dynamicStr = "Hello, Fortran"
    WRITE(*, "(A,T22,A)") "Initial string: ", dynamicStr
    ! Modifying the string (slicing and concatenation)
    dynamicStr = dynamicStr(1:7) // "World!!!!!!!!!!"
    WRITE(*, "(A,T22,A)") "After modification: ", dynamicStr

end program main
