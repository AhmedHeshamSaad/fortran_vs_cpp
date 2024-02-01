program main
    implicit none
    integer, target :: myArray(10)
    integer, pointer :: ptr(:)
    integer :: i
  
    ! Initialize the array with values 1 through 10
    myArray = [(i, i = 1, 10)]
  
    ! Point ptr to the entire myArray
    ptr => myArray
    WRITE(*, '(A, 10I3)') "Original array:", ptr
  
    ! Now, let's point ptr to a slice of myArray
    ptr => myArray(5:7)
    WRITE(*, '(A, 3I3)') "Slice before mod:", ptr
  
    ! Modify the slice
    ptr = ptr * 2
    WRITE(*, '(A, 3I3)') "Slice after mod:", ptr
  
    ! Show the effect on the original array
    WRITE(*, '(A,10I3)') "Modified original array:", myArray
  end program main